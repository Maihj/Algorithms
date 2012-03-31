#include <stdio.h>
#include <stdlib.h>

#define LENGTH 5

/* Insert a value to the queue. */
void enqueue(int queue[LENGTH], int value);
/* Delete a value from the queue. */
int dequeue(int queue[LENGTH]);
/* When the queue is empty. */
int head = (LENGTH - 1) / 2, tail = (LENGTH - 1) / 2;

/* Implement the queue by array. */
int main(){
    int queue[LENGTH];
    int value, i, choice;
    
    /* Initialize the queue. */
    for (i = 0; i < LENGTH; i++)
	queue[i] = 0;
    
    printf("------------------------------\n           Queue\n------------------------------\n");
    while (choice != 5){
	printf("\n1.Insert a value.\n");
	printf("2.Delete a value.\n");
	printf("3.Show the current queue.\n");
	printf("4.Clean the screen.\n");
	printf("5.Exit.\n");
	printf("Please enter your choice: ");
	
	scanf("%d", &choice);
	switch(choice){
	case 1:
	    printf("Please enter a value: ");
	    scanf("%d", &value);
	    enqueue(queue, value);
	    printf("The value you inserted to the queue was: %d\n", value);
	    break;
	    
	case 2:
	    value = dequeue(queue);
	    if (value == -1)
		printf("The queue is empty so that you can't remove any value from it.\n");
	    else
		printf("The value deleted was: %d\n", value);
	    break;
	    
	case 3:
	    printf("The values in the queue are: ");
	    for (i = 0; i < LENGTH; i++)
		printf("%d ", queue[i]);
	    printf("\n");
	    break;
	    
	case 4:
	    system("clear");
	    break;
	   
	case 5:
	    break;
	}
    }

    return 0;
}

void enqueue(int queue[LENGTH], int value){
    if (head == tail + 1)
	printf("The queue is full so that you can't insert any value in it.\n");
    else {
	queue[tail] = value;
	if (tail == LENGTH - 1)
	    tail = 0;
	else 
	    tail++;
    }
}

int dequeue(int queue[LENGTH]){
    int value;
    if (head == tail)
	return -1;
    else {
	value = queue[head];
	queue[head] = 0;
	if (head == LENGTH - 1)
	    head = 0;
	else
	    head++;
	return value;
    }
}
