#ifndef AVL_AVL_H
#define AVL_AVL_H
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;
typedef struct no{
    int height;
    int info;
    struct no *right;
    struct no *left;
}Node;

typedef struct arv_bin{
    Node * root;
}tree_bin;

tree_bin *build_tree();
Node *new_node(int k);
Node *rotation_for_right(Node *root);
Node *rotation_for_left(Node *root);
Node *remove(Node *root, int k);
Node *insert_avl(Node *root, int k);
int height_node(Node *root);
int balance_factor(Node *root);
int max(int x, int y);
void choose_print_order(tree_bin * arv, int ordem);
void print_pre_order(Node *root);
void print_in_order(Node * root);
void print_post_order(Node *root);





#endif //AVL_AVL_H
