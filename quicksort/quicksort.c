/* Functions */
#include "quicksort.h"

/* return the index i of array[0,...,ARRAY_LENGTH-1] so that every element in array[0,...,i-1] <= array[i] & <= array[i+1,...,ARRAY_LENGTH-1] */
int partition(int *array, int *start, int *end){
    int i, j, temp;
    i = *start - 1;
    
    for (j = *start; j <= *end - 1; j++){
	if (*(array + j) <= *(array + *end)){
	    i++;
	    /* exchange array[i] and array[j] */
	    temp = *(array + i);
	    *(array + i) = *(array + j);
	    *(array + j) = temp;
	}
    }
    /* exchange array[i+1] and array[end] */
    temp = *(array + i + 1);
    *(array + i + 1) = *(array + *end);
    *(array + *end) = temp;
    
    return i + 1;
}

/* the algorithm of quicksort */
void quicksort(int *array, int *start, int *end){
    int i;
    int *p;
    p = &i;
    
    if (*start < *end){
	i = partition(array, start, end);
	i--;
	quicksort(array, start, p);
	i = i + 2;
	quicksort(array, p, end);
    }
}
