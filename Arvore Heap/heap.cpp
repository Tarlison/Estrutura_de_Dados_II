#include "heap_sort.h"
#include <iostream>
#include <limits.h>
using namespace std;

int main(){
	Heap *h = build();
    build_max_heap(h);
    heap_sort(h);
    build_max_heap(h);
    maximum(h);
    cout << heap_extract_max(h) << endl;
    heap_increase_key(h, 2, 22);
    heap_increase_key(h, 1, 44);
    max_heap_insert(h, 66);
    minimum(h);
    cout << heap_extract_min(h) << endl;
    heap_decrease_key(h, 3, 34);
    min_heap_insert(h, 47);
    return 0;

}
