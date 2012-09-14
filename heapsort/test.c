#include <stdio.h>
#include "heapsort.h"

/* heapsort */
int main(){
    int i;
    int array[ARRAY_LENGTH];
    
    printf("------------------------------\n-----------HEAPSORT-----------\n------------------------------\n");
    
    printf("Please input %d integers: ", ARRAY_LENGTH);
    for (i = 0; i < ARRAY_LENGTH; i++)
	scanf("%d", &array[i]);
    
    printf("The original array is: ");
    for (i = 0; i < ARRAY_LENGTH; i++)
	printf("%d ", array[i]);
    printf("\n");
    
    heapsort(&array[0]);
    
    printf("The sorted array is: ");
    for (i = 0; i < ARRAY_LENGTH; i++)
	printf("%d ", array[i]);
    printf("\n");
    printf("\n");

    return 0;
}
