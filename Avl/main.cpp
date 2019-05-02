#include "Avl.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int ordem, aux_for_search, remove_value;
    tree_bin *arv = build_tree();
    arv->root = insert_avl(arv->root, 20); arv->root = insert_avl(arv->root, 10); arv->root = insert_avl(arv->root, 23);
    arv->root = insert_avl(arv->root,  5); arv->root = insert_avl(arv->root, 15); arv->root = insert_avl(arv->root, 21);
    arv->root = insert_avl(arv->root, 27); arv->root = insert_avl(arv->root,  2); arv->root = insert_avl(arv->root, 13);
    arv->root = insert_avl(arv->root,  6); arv->root = insert_avl(arv->root, 11); arv->root = insert_avl(arv->root, 12);

    cout << "Choose impression order" << endl;
    cout << "1 - pre_order 2 - in_order 3 - post_order: " << endl;
    cin >> ordem;
    choose_print_order(arv, ordem);

    cout << endl;

    cout << "Choose one value for search" << endl;
    cin >> aux_for_search;
    if (tree_search(arv, aux_for_search))
        cout << "The value is in the tree" << endl;
    else
        cout << "The value isn't in the tree" << endl;

    cout << "Choose one value for remove" << endl;
    cin >> remove_value;
    arv->root = remove(arv->root, remove_value);

    cout << "Choose impression order" << endl;
    cout << "1 - pre_order 2 - in_order 3 - post_order: " << endl;
    cin >> ordem;
    choose_print_order(arv, ordem);

    cout << endl;

    cout << "Choose one value for search" << endl;
    cin >> aux_for_search;
    if (tree_search(arv, aux_for_search))
        cout << "The value is in the tree" << endl;
    else
        cout << "The value isn't in the tree" << endl;

    return 0;
}