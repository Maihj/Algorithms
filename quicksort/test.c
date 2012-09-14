/* Test quicksort */
#include <stdio.h>
#include "quicksort.h"

int main(){
    int i, start, end;
    int array[ARRAY_LENGTH];
    start = 0;
    end = ARRAY_LENGTH - 1;
    
    printf("--------------------------------------------------\n--------------------QUICKSORT---------------------\n--------------------------------------------------\n");
    printf("Please enter %d integers: ", ARRAY_LENGTH);
    for (i = 0; i < ARRAY_LENGTH; i++)
	scanf("%d", &array[i]);
    printf("\n");
    
    printf("The original array is: ");
    for (i = 0; i < ARRAY_LENGTH; i++)
	printf("%d ", array[i]);
    printf("\n");

    /* quicksort */
    quicksort(&array[0], &start, &end);

    printf("The sorted array is: ");
    for (i = 0; i < ARRAY_LENGTH; i++)
	printf("%d ", array[i]);
    printf("\n\n");

    return 0;
}
