#include <stdio.h>

#define PARENT(i) (i) / 2         //i's parent
#define LEFT(i)   (i) * 2         //i's leftchild
#define RIGHT(i)  (i) * 2 + 1     //i's rightchild
#define ARRAY_LENGTH  5           //the length of array

/* make the subtree rooted at index i become a max-heap */
void max_heapify(int *array, int *i, int *heap_size);

/* build the max-heap */
void build_max_heap(int *array);

/* algorithm of heapsort */
void heapsort(int *array);
