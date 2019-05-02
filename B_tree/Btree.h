//
// Created by tarlison on 24/04/19.
//
#ifndef B_TREE_BTREE_H
#define B_TREE_BTREE_H
#define t 3
using namespace std;

typedef struct node{
    int number_of_keys;
    int key[t-1];
    struct node *children[t];
    int is_leaf;
}Node;

typedef struct Btree{
    Node *root;
}b_tree;

Node *b_tree_create();
Node *b_tree_search(Node *x, int k);
void b_tree_insert(b_tree *T,int k);
void b_tree_insert_nonfull(Node *x, int k);
void b_tree_split_child(Node *x,int i);




//y.chave[j+med (t/2)]

#endif //B_TREE_BTREE_H
