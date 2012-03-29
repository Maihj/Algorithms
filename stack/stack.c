#include <stdio.h>

void push(int stack[10], int value);
int pop(int stack[10]);

/* Implement the stack with array. */
int top = -1;
int main(){
    int stack[10];
    int i, value;

    for (i = 0; i < 10; i++)
	stack[i] = 0;

    printf("Please enter your choice:\n");
    printf("1.Push an element.\n");
    printf("2.Pop an element.\n");
    
    scanf("%d", &i);
    
    if (i == 1){
	printf("Please enter a value: ");
	scanf("%d", &value);
	push(stack, value);
    }
    else if (i == 2){
	pop(stack);
    }

    printf("The values in the stack are: ");
    for (i = 0; i < 10; i++){
	printf("%d ", stack[i]);
    }
    
    return 0;
}

void push(int stack[10], int value){
    if (top == 9)
	printf("The stack is full so that you can't push any value to it anymore.\n");
    else {
	top++;
	stack[top] = value;
    }
}

int pop(int stack[10]){
    if (top == -1){
	printf("The stack is empty so that you can't pop any value from it.");
	return;
    }
    else {
	top--;
	return stack[top + 1];
    }
}
