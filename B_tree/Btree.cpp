//
// Created by tarlison on 24/04/19.
//
#include "Btree.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;

Node *b_tree_create(){
    Node *x = (Node*) malloc(sizeof(Node));
    x->is_leaf = 1;
    x->number_of_keys = 0;
    return x;
}

Node *b_tree_search(Node *x, int k){
    int i = 0;
    while (i < x->number_of_keys && k > x->key[i]){
        i = i + 1;
    }
    if (i < x->number_of_keys && k == x->key[i]){
        return x;
    }
    else if (x->is_leaf){
        return NULL;
    }
    return b_tree_search(x->children[i],k);


}

void b_tree_split_child(Node *x,int i){
	int j;
	Node *z = (Node*)malloc(sizeof(Node));
	Node *y = x->children[i];
	z->is_leaf = y->is_leaf;
	z->number_of_keys = t/2 - 1;
	for (j = 0; j < ((t/2)-1); j++){
		z->key[j] = y->key[j+(t/2)+1];
	}
	y->number_of_keys = t/2;
	if (!y->is_leaf){
		for(j = x->number_of_keys; j > i+1; j--){
			x->children[j+1] = x->children[j];		
		}
	}
	x->children[i+1] = z;
	for (j = x->number_of_keys; j > i; j--){
		x->key[j] = x->key[j-1];	
	}
	x->key[i] = y->key[t/2];
	x->number_of_keys += 1; 
}

void b_tree_insert_nonfull(Node *x, int k){
	int i = x->number_of_keys;
	if (x->is_leaf){
		while (i >= 0 && k < x->key[i-1]){
            x->key[i] = x->key[i-1];
            i = i - 1;
		}
		x->key[i] = k;
		x->number_of_keys = x->number_of_keys + 1;
	}
	else{
		while(i>= 0 && k < x->key[i-1]){
			i = i - 1;
		}
		//i = i + 1;
		if (x->children[i]->number_of_keys == t-1){
			b_tree_split_child(x,i);
			if (k > x->key[i]){
				i = i + 1;
			}		
		}
		b_tree_insert_nonfull(x->children[i], k);
	}
}

void b_tree_insert(b_tree *T,int k){
	Node *r = T->root;
	if(r->number_of_keys == t - 1){
		Node *s = (Node*)malloc(sizeof(Node));	
		T->root = s;
		s->is_leaf = 0;
		s->number_of_keys = 0;
		s->children[0] = r;
		b_tree_split_child(s,0);
		b_tree_insert_nonfull(s,k);
	} 
	else{
		b_tree_insert_nonfull(r,k);
	}
}

void print_tree (Node * root) {
    int i;
    for (i = 0; i < root->number_of_keys; i++) {
        if ( root->is_leaf == 0 )
            print_tree ( root->children [i]);
        cout << "." << root->key [i];
    }
    if ( root->is_leaf == 0 ) {
        print_tree(root ->children[i]);
    }
}





