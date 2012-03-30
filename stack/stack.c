#include <stdio.h>
#include <stdlib.h>

/* Insert a value in the stack. */
void push(int stack[10], int value);
/* Delete a value from the stack. */
int pop(int stack[10]);
/* When the stack is emtpy. */
int top = -1;

/* Implement the stack by array. */
int main(){
    int stack[10];
    int i, value;

    /* Initialize the stack. */
    for (i = 0; i < 10; i++)
	stack[i] = 0;

    printf("---------------------------------------------\n            Stack\n---------------------------------------------\n");
    
    while (1){
	printf("Please enter your choice:\n");
	printf("1.Insert an element.\n");
	printf("2.Delete an element.\n");
	printf("3.Print the stack.\n");
	printf("4.Clear the screen.\n");
    
	scanf("%d", &i);
	
	switch(i){
	case 1:
	     printf("Please enter a value: ");
	     scanf("%d", &value);
	     push(stack, value);
	     printf("The value you inserted was %d.\n\n", value);
	     break;

	case 2:
	    printf("The value you deleted was %d.\n\n", pop(stack));
	    break;

	case 3:
	    printf("The values in the stack are: ");
	    for (i = 0; i < 10; i++)
		printf("%d ", stack[i]);
	    printf("\n\n");
	    break;

	case 4:
	    system("clear");
	    break;
	}
    }
    
    return 0;
}

/* Insert a value in the stack. */
void push(int stack[10], int value){
    if (top == 9)
	printf("The stack is full so that you can't insert any value to it anymore.\n");
    else {
	top++;
	stack[top] = value;
    }
}

/* Delete a value from the stack. */
int pop(int stack[10]){
    int value;
    if (top == -1){
	printf("The stack is empty so that you can't delete any value from it.\n");
	value = -1;
    }
    else {
	value = stack[top];
	stack[top] = 0;
	top--;
    }
    return value;
}
