//
// Created by Tarlison Sander on 16/04/2019.
//
#include "RedBlackTree.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>

rb_tree *build_tree(){
    rb_tree *tree = (rb_tree*)malloc(sizeof(rb_tree));
    Node *n = (Node*)malloc(sizeof(Node));
    tree->nil = n;
    tree->nil->color = BLACK;
    tree->root = tree->nil;
    return tree;
}

void left_rotate(rb_tree *tree, Node *root){
    Node *y = (Node*)malloc(sizeof(Node));
    y = root->right;
    root->right = y->left;
    if (y->left != tree->nil)
        y->left->father = root;
    y->father = root->father;
    if (root->father == tree->nil)
        tree->root = y;
    else if (root == root->father->left)
        root->father->left = y;
    else if (root == root->father->right)
        root->father->right = y;
    y->left = root;
    root->father = y;

}

void right_rotate(rb_tree *tree, Node *root){
    Node *y = (Node*)malloc(sizeof(Node));
    y = root->left;
    root->left = y->right;
    if (y->right != tree->nil)
        y->right->father = root;
    y->father = root->father;
    if (root->father == tree->nil)
        tree->root = y;
    else if (root == root->father->left)
        root->father->left = y;
    else if (root == root->father->right)
        root->father->right = y;
    y->right = root;
    root->father = y;

}

Node *search_node(rb_tree *tree,Node *root ,int c){
    if (root == tree->nil || root->info == c){
        return root;
    }
    else if (c < root->info){
        return search_node(tree,root->left, c);
    }
    else if (c > root->info){
        return  search_node(tree,root->right, c);
    }
}

Node *rb_insert(rb_tree *T, int z){
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->right = new_node->left = T->nil;
    new_node->color = RED;
    new_node->info = z;
    new_node->father = T->nil;
    return  T->root = rb_insert_node(T, new_node);
}

Node *rb_insert_node(rb_tree *T, Node *z){
    Node *y = (Node*) malloc(sizeof(Node));
    Node *x = (Node*) malloc(sizeof(Node));
    y = T->nil;
    x = T->root;
    while (x != T->nil){
        y = x;
        if (z->info < x->info)
            x = x->left;
        else
            x = x->right;
    }
    z->father = y;
    if (y == T->nil)
        T->root = z;
    else if (z->info < y->info)
        y->left = z;
    else
        y->right = z;
    z->left = T->nil;
    z->right = T->nil;
    z->color = RED;
    return T->root = rb_insert_fixup(T,z);
}

Node *rb_insert_fixup(rb_tree *T,Node *z){
    Node *y = (Node*) malloc(sizeof(Node));
    while(z->father->color == RED){
        if (z->father == z->father->father->left){
            y = z->father->father->right;
            if (y->color == RED){
                z->father->color = BLACK;   //case 1, "father's" color receives BLACK
                y->color = BLACK;   //case 1, "uncle's" color receives BLACK
                z->father->father->color = RED; //case 1, "grandfather's" color receives RED;
                z = z->father->father; //case 1, the 'z' now is the grandfather's;
            }
            else{
                if(z == z->father->right){
                    z = z->father; //case 2, the father of 'z' is now the new 'z';
                    left_rotate(T, z); //case 2, rotation simple for left;

                }
                z->father->color = BLACK; //case 3, "father's" color receives BLACK;
                z->father->father->color = RED; //case 3, "grandfather's" color receives RED;
                right_rotate(T, z->father->father); //case 3, rotation simple in the "grandfather" for right;
            }
        }
        else{
            if (z->father == z->father->father->right){
                y = z->father->father->left;
                if (y->color == RED){
                    z->father->color = BLACK;   //case 1, "father's" color receives BLACK
                    y->color = BLACK;   //case 1, "uncle's" color receives BLACK
                    z->father->father->color = RED; //case 1, "grandfather's" color receives RED;
                    z = z->father->father; //case 1, the 'z' now is the grandfather's;
                }
                else{
                    if(z == z->father->left){
                        z = z->father; //case 2, the father of 'z' is now the new 'z';
                        right_rotate(T, z); //case 2, rotation simple for right;

                    }
                    z->father->color = BLACK; //case 3, "father's" color receives BLACK;
                    z->father->father->color = RED; //case 3, "grandfather's" color receives RED;
                    left_rotate(T, z->father->father); //case 3, rotation simple in the "grandfather" for left;
                }
            }
        }
    }
    T->root->color = BLACK;
    return T->root;
}

void rb_transplant(rb_tree *T, Node *u, Node *v){
    if(u->father == T->nil)
        T->root = v;

    else if(u == u->father->left)
        u->father->left = v;

    else
        u->father->right = v;

    v->father = u->father;
}

Node *tree_minimum(rb_tree *T,Node *x){
    while (x->left != T->nil){
        x = x->left;
    }
    return x;
}

void rb_remove(Node *node_for_remove, rb_tree *T){
  Node *y = (Node*)malloc(sizeof(Node));
  Node *x = (Node*)malloc(sizeof(Node));
  y = node_for_remove;
  Color y_original_color = y->color;
  if (node_for_remove->left == T->nil){
      x = node_for_remove->right;
      rb_transplant(T, node_for_remove, node_for_remove->right);
  }
  else if(node_for_remove->right == T->nil){
      x = node_for_remove->left;
      rb_transplant(T,node_for_remove,node_for_remove->left);
  }
  else{
      y = tree_minimum(T,node_for_remove->right);
      y_original_color = y->color;
      x = y->right;
      if(y->father == node_for_remove){
          x->father = y;
      }
      else{
          rb_transplant(T,y,y->left);
          y->right = node_for_remove->right;
          y->right->father = y;
      }
      rb_transplant(T,node_for_remove,y);
      y->left = node_for_remove->left;
      y->left->father = y;
      y->color = node_for_remove->color;
  }
  if(y_original_color == BLACK){
      rb_delete_fixup(T,x);
  }
}

void rb_delete_fixup(rb_tree *T, Node *x){
    Node *w = (Node*) malloc(sizeof(Node));
    while (x != T->root && x->color == BLACK){
        if (x == x->father->left){
            w = x->father->right;
            if (w->color == RED){
                w->color = BLACK;   //case 1 brother of x receives BLACK;
                x->father->color = RED; //case 1 father of x receives RED;
                left_rotate(T, x->father);  //case 1 left_rotate in the father;
            }
            if (w->left->color == BLACK && w->right->color == BLACK){
                w->color = RED; //case 2 brother of x receives RED;
                x = x->father;  //case 2 x receives the value of his father;
            }
            else{
                if (w->right->color == BLACK){
                    w->left->color = BLACK; //case 3 the nephew on the left receives BLACK;
                    w->color = RED; //case 3 the brother receives RED;
                    right_rotate(T, w); //case 3 right_rotate in the brother;
                    w = x->father->right; //case 3
                }
                w->color = x->father->color;    //case 4 the brother receives the color of father;
                x->father->color = BLACK;   //case 4 the father receives BLACK;
                w->right->color = BLACK;    //case 4 the nephew on the right receives BLACK;
                left_rotate(T, x->father);  //case 4 left_rotate in the father;
                x = T->root;    //case 4 node att;
            }
        }
        else{
            if (x == x->father->right){
                w = x->father->left;
                if (w->color == RED){
                    w->color = BLACK;   //case 1 brother of x receives BLACK;
                    x->father->color = RED; //case 1 father of x receives RED;
                    right_rotate(T, x->father);  //case 1 right_rotate in the father;
                }
                if (w->right->color == BLACK && w->left->color == BLACK){
                    w->color = RED; //case 2 brother of x receives RED;
                    x = x->father;  //case 2 x receives the value of his father;
                }
                else if (w->left->color == BLACK){
                    w->right->color = BLACK; //case 3 the nephew on the right receives BLACK;
                    w->color = RED; //case 3 the brother receives RED;
                    left_rotate(T, w); //case 3 left_rotate in the brother;
                    w = x->father->right; //case 3 
                }
                w->color = x->father->color;    //case 4 the brother receives the color of father;
                x->father->color = BLACK;   //case 4 the father receives BLACK;
                w->left->color = BLACK;    //case 4 the nephew on the left receives BLACK;
                right_rotate(T, x->father);  //case 4 right_rotate in the father;????
                x = T->root;    //case 4 node att;
            }
        }
    }
    x->color = BLACK;

}

//Prints
void choose_print_order(rb_tree * arv, int ordem){
    if(ordem == 1)
        print_in_order(arv, arv->root);
    if(ordem == 2)
        print_pre_order(arv, arv->root);
    if(ordem == 3)
        print_post_order(arv, arv->root);
}

void print_pre_order(rb_tree *arv,Node *root){
    if(root != arv->nil){
        printf("[%d,%s] ", root->info, (root->color == RED) ? "RED" : "BLACK");
        print_pre_order(arv,root->left);
        print_pre_order(arv,root->right);
    }
}

void print_in_order(rb_tree *arv, Node *root){
    if(root != arv->nil){
        print_in_order(arv,root->left);
        printf("[%d,%s] ", root->info, (root->color == RED) ? "RED" : "BLACK");
        print_in_order(arv,root->right);
    }
}

void print_post_order(rb_tree *arv,Node *root){
    if(root != arv->nil){
        print_post_order(arv,root->left);
        print_post_order(arv,root->right);
        printf("[%d,%s] ", root->info, (root->color == RED) ? "RED" : "BLACK");
    }
}