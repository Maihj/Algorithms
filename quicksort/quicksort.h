/* Header of implementing the algorithm of quicksort */
#ifndef QUICKSORT_H
#define QUICKSORT_H

#define ARRAY_LENGTH 5

/* return the index i of array[0,...,ARRAY_LENGTH-1] so that every element in array[0,...,i-1] <= array[i] & <= array[i+1,...,ARRAY_LENGTH-1] */
int partition(int *array, int *start, int *end);

/* the algorithm of quicksort */
void quicksort(int *array, int *start, int *end);

#endif
