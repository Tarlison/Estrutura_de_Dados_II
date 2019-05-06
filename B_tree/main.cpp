#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include "Btree.h"
using namespace std;

int main() {
    b_tree *tree = (b_tree*)malloc(sizeof(b_tree));
    int value;
    tree->root = b_tree_create();

    b_tree_insert(tree, 40);
    b_tree_insert(tree, 80);
    b_tree_insert(tree, 100);
    b_tree_insert(tree, 30);
    b_tree_insert(tree, 110);
    b_tree_insert(tree, 90);

    cout << "values in the tree  30 40 80 90 100 110" << endl;

    cout << "Enter a value for search" << endl;
    cin >> value;

    if(b_tree_search(tree->root, value) == NULL){
        printf("Value not found\n");
    }else{
        printf("Value %d found \n",value);
    }

    print_tree (tree->root);

}
