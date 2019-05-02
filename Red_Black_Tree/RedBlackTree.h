//
// Created by Tarlison Sander on 16/04/2019.
//
#ifndef RED_BLACK_TREE_REDBLACKTREE_H
#define RED_BLACK_TREE_REDBLACKTREE_H
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;

enum Color {RED = 1, BLACK = 0};

typedef struct no{
    Color color; // if color == 'R' means red, if color == 'B' means black;
    int info;
    struct no *right;
    struct no *left;
    struct no *father;
}Node;

typedef struct arv_bin{
    Node *root;
    Node *nil;
}rb_tree;

rb_tree *build_tree();
Node *search_node(rb_tree *tree,Node *root ,int c);
Node *rb_insert(rb_tree *T, int z);
Node *rb_insert_node(rb_tree *T, Node *z);
Node *rb_insert_fixup(rb_tree *T,Node *z);
Node *tree_minimum(rb_tree *T,Node *x);
void rb_transplant(rb_tree *T, Node *u, Node *v);
void rb_remove(Node *root, rb_tree *T);
void rb_delete_fixup(rb_tree *T, Node *x);
void left_rotate(rb_tree *tree, Node *root);
void right_rotate(rb_tree *tree, Node *root);
void choose_print_order(rb_tree * arv, int ordem);
void print_pre_order(rb_tree *arv,Node *root);
void print_in_order(rb_tree *arv ,Node *root);
void print_post_order(rb_tree *arv,Node *root);


#endif //RED_BLACK_TREE_REDBLACKTREE_H