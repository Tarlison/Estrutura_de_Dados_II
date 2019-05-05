#include "RedBlackTree.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    rb_tree *tree = build_tree();
    Node *aux_for_remove = (Node*)malloc(sizeof(Node));
    int aux, aux2;

    cout << "Enter the number of values to be inserted" << endl;
    cin >> aux;

    while(aux > 0){
        cout << "Enter the value" << endl;
        cin >> aux2;
        tree->root = rb_insert(tree, aux2);
        aux--;
    }

    cout << "Choose the order" <<endl;
    cout << "1 - Infixa" << endl;
    cout << "2 - Pre-Fixa" << endl;
    cout << "3 - Pos-Fixa" << endl;
    cin >> aux;
    choose_print_order(tree,aux);
    cout<<endl;

    cout << "Enter the value for remove" << endl;
    cin >> aux;
    aux_for_remove = search_node(tree,tree->root,aux);
    rb_remove(aux_for_remove,tree);


    cout <<"Apos Remocao do " << aux << endl;
    cout << "Choose the order" <<endl;
    cout << "1 - Infixa" << endl;
    cout << "2 - Pre-Fixa" << endl;
    cout << "3 - Pos-Fixa" << endl;
    cin >> aux;
    choose_print_order(tree,aux);
    cout<<endl;

    return 0;
}