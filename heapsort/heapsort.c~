#include "heap.h"

/* make the subtree rooted at index i become a max-heap */
void max_heapify(int *array, int *i, int *heap_size){
    int l, r, temp, largest;
    l = LEFT(*i);
    r = RIGHT(*i);
    
    /* compare the value at index i and that of its leftchild */
    if (l <= *heap_size && *(array + l - 1) > *(array + (*i) - 1))
	largest = l;
    else
	largest = *i;

    /* compare the value at index largest and that of i's rightchild */
    if (r <= *heap_size && *(array + r - 1) > *(array + largest - 1))
	largest = r;
    
    /* exchange values if necessary*/
    if (largest != *i){
	temp = *(array + (*i) - 1);
	*(array + (*i) - 1) = *(array + largest - 1);
	*(array + largest - 1) = temp;
	max_heapify(array, &largest, heap_size);
    }   
}

/* build the max-heap */
/* The elements in the subarray array[(⌊n/2⌋+1)...n] are all leaves of the tree, and so each is a 1-element heap to begin with. The procedure build_max_heap() goes through the remaining nodes of the tree and runs max_heapify() on each one. */
void build_max_heap(int *array){
    int heap_size, i;
    heap_size = ARRAY_LENGTH;
    
    for (i = ARRAY_LENGTH / 2; i >= 1; i--)
	max_heapify(array, &i, &heap_size);
}

/* the algorithm of heapsort */
void heapsort(int *array){
    int i, x, temp, heap_size;
    int *p;
    x = 1;
    p = &x;
    heap_size = ARRAY_LENGTH;
    
    build_max_heap(array);
    
    for (i = ARRAY_LENGTH; i >= 2; i--){
	/* exchange array[0] and array[ARRAY_LEHGTH-1], since array[0] is the maximum of this array */
	temp = *array;
	*array = *(array + i - 1);
	*(array + i - 1) = temp;
	heap_size--;
	max_heapify(array, p, &heap_size);
    }
}
