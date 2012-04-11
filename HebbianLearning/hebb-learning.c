#include <stdio.h>

#define NUMBER 3  /* the number of input units */

struct node {
    float weight[NUMBER];
};

/* Implementation of Hebbian learning method. */
int main(){
    float input[NUMBER], temp[NUMBER];
    float net = 0.0, lr = 0.1, sum = 1.0;
    int n, i, j, c = 0;
    struct node node1, node2, node3;
    
    /* initialize the weights */
    for (i = 0; i < NUMBER; i++)
	node1.weight[i] = 0.1;
    for (i = 0; i < NUMBER; i++)
	node2.weight[i] = 0.1;
    for (i = 0; i < NUMBER; i++)
	node3.weight[i] = 0.1;
    
    /* threshold value = 0, learning rate(lr) = 0.1, f(net) = net */
    while(sum > 0.01){
	c++;
	sum = 0.0;
	/* input values */
	printf("Please enter the input values: ");
	for (i = 0; i < NUMBER; i++){
	    scanf("%f", &input[i]);
	    net = net + input[i] * node1.weight[i];
	}
	for (i = 0; i < NUMBER; i++){
	    temp[i] = node1.weight[i];
	    node1.weight[i] = node1.weight[i] + lr * net * input[i];
	    printf("%f ", node1.weight[i]);
	}
	printf("\n");
	
	for (i = 0; i < NUMBER; i++)
	    sum = sum + (node1.weight[i] - temp[i]) * (node1.weight[i] - temp[i]);
	sum = sum / NUMBER;
	net = 0;
    }

    return 0;
}
