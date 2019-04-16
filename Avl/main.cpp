#include "Avl.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int ordem;
    tree_bin *arv = build_tree();
    arv->root = insert_avl(arv->root, 20); arv->root = insert_avl(arv->root, 10); arv->root = insert_avl(arv->root, 23);
    arv->root = insert_avl(arv->root,  5); arv->root = insert_avl(arv->root, 15); arv->root = insert_avl(arv->root, 21);
    arv->root = insert_avl(arv->root, 27); arv->root = insert_avl(arv->root,  2); arv->root = insert_avl(arv->root, 13);
    arv->root = insert_avl(arv->root,  6); arv->root = insert_avl(arv->root, 11); arv->root = insert_avl(arv->root, 12);
    cout << "Choose impression order" << endl;
    cout << "1 - pre_order 2 - in_order 3 - post_order: " << endl;
    cin >> ordem;
    choose_print_order(arv, ordem);



    return 0;
}