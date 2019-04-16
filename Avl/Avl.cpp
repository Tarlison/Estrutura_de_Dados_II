#include "Avl.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;


tree_bin *build_tree(){
    tree_bin * arv = (tree_bin *) malloc(sizeof(tree_bin));
    arv->root = NULL;
    return arv;
}

Node *new_node(int k){
    Node *p = (Node*) malloc(sizeof(Node));
    p->info = k;
    p->height = 0;
    p->right = p->left = NULL;
    return p;
}

int height_node(Node *root){
    if(root == NULL){
        return -1;
    }
    return root->height;
}

int balance_factor(Node *root){
    if(root == NULL){
        return 0;
    }
    return height_node(root->right) - height_node(root->left);
}

int max(int x, int y){
    return x > y ? x : y;
}

Node *rotation_for_right(Node *root){
    Node *aux = root->left;
    Node *aux2 = aux->right;

    aux->right = root;
    root->left = aux2;

    root->height = max(height_node(root->left),height_node(root->right))+1;
    aux->height = max(height_node(aux->left),height_node(aux->right))+1;

    return aux;

}

Node *rotation_for_left(Node *root){
    Node *aux = root->right;
    Node *aux2 = aux->left;

    aux->left = root;
    root->right = aux2;

    root->height = max(height_node(root->left),height_node(root->right))+1;
    aux->height = max(height_node(aux->left),height_node(aux->right))+1;

    return aux;

}

Node *insert_avl(Node *root, int k){
    if (root == NULL){
        return (new_node(k));
    }
    if (k < root->info){
        root->left = insert_avl(root->left, k);
    }
    else if (k > root->info){
        root->right = insert_avl(root->right, k);
    }
    else{
        return root;
    }

    root->height = 1 + max(height_node(root->left),height_node(root->right));

    int balanceFactor = balance_factor(root);
    //Left Left Case
    if (balanceFactor < -1 && k < root->left->info){
        return rotation_for_right(root);
    }
    //Right Right Case
    if (balanceFactor > 1 && k > root->right->info){
        return rotation_for_left(root);
    }
    //Left Right Case
    if (balanceFactor < -1 && k >root->right->info){
        root->left = rotation_for_left(root->left);
        return rotation_for_right(root);
    }
    //Right Left Case
    if (balanceFactor > 1 && k < root->right->info){
        root->right = rotation_for_right(root->right);
        return rotation_for_left(root);
    }
    //no rotations
    return root;

}

Node* remove(Node *root, int k){
    if (root == NULL){
        return NULL;
    }
    else if (k < root->info){
        root->left = remove(root->left, k);
    }
    else if (k > root->info){
        root->right = remove(root->right, k);
    }
    else{
        if (root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        else if (root->left == NULL){
            Node *aux = root;
            root = root->right;
            free(aux);
        }
        else if (root->right == NULL){
            Node *aux = root;
            root = root->left;
            free(aux);
        }
        else {
            Node *aux = root->left;
            while (aux->right != NULL){
                aux = aux->right;
            }

            root->info = aux->info;
            aux->info = k;
            root->left = remove(root->left,k);
        }
    }

    if (root == NULL){
        return root;
    }

    root->height = 1 + max(height_node(root->left), height_node(root->right));

    int balanceFactor = balance_factor(root);

    // Left Left Case
    if (balanceFactor < -1 && balance_factor(root->left) <= 0){
        return rotation_for_right(root);
    }
    // Left Right Case
    if (balanceFactor < -1 && balance_factor(root->left) > 0){
        root->left = rotation_for_left(root->left);
        return rotation_for_right(root);
    }
    //Right Right Case
    if (balanceFactor > 1 && balance_factor(root->right) >= 0){
        return rotation_for_left(root);
    }
    //Right Left Case
    if (balanceFactor > 1 && balance_factor(root->right) < 0){
        root->right = rotation_for_right(root->right);
        return rotation_for_left(root);
    }
    return root;
}

void choose_print_order(tree_bin * arv, int ordem){
    if(ordem == 1)
        print_pre_order(arv->root);
    if(ordem == 2)
        print_in_order(arv->root);
    if(ordem == 3)
        print_post_order(arv->root);
}

void print_pre_order(Node *root){
    if(root != NULL){
        printf("%d ", root->info);
        print_pre_order(root->left);
        print_pre_order(root->right);
    }
}

void print_in_order(Node *root){
    if(root != NULL){
        print_in_order(root->left);
        printf("%d ", root->info);
        print_in_order(root->right);
    }
}

void print_post_order(Node * root){
    if(root != NULL){
        print_post_order(root->left);
        print_post_order(root->right);
        printf("%d ", root->info);
    }
}





