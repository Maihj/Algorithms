#include <stdio.h>

/* The implementation of Gauss elimination. */
int main(){
    int i, j, k, n, c = 0;
    float result;
    float a[100][100], b[100], l[100][100], x[100];
    
    printf("\n----------------------------------------------------------------------\n This algorithm is used to solve 'Ax = B' with Gauss elimination. \n----------------------------------------------------------------------\n");
    printf("Please enter the dimension of the matrix A: ");
    scanf("%d", &n);

    printf("Please enter A: ");
    for (i = 0; i < n; i++){
	for (j = 0; j < n; j++){
	    scanf("%f", &a[i][j]);
	}
    }
    for (i = 0; i < n; i++){
	if (a[i][i] == 0){
	    printf("Can't solve this linear equations by Gaussian-elimination.\n");
	    return 1;
	}
    }
    
    printf("please enter B: ");
    for (i = 0; i < n; i++){
	scanf("%f", &b[i]);
    }

    for (k = 0; k < n-1; k++){
	for (i = k+1; i < n; i++){
	    l[i][k] = a[i][k] / a[k][k];
	    c++;
	}
	for (i = k+1; i < n; i++){
	    for (j = k+1; j < n; j++){
		a[i][j] = a[i][j] - l[i][k] * a[k][j];
		c++;
	    }
	    b[i] = b[i] - l[i][k] * b[k];
	    c++;
	    a[i][k] = 0;
	}
    }

    printf("After converting, A(%d*%d) and B(%d*1) can be:\n", n, n, n);
    for (i = 0; i < n; i++){
	for (j = 0; j < n; j++){
	    printf("%.2f  ", a[i][j]);
	}
	printf("%.2f\n", b[i]);
    }

    printf("The solution to x is: ");
    x[n-1] = b[n-1] / a[n-1][n-1];
    c++;
    for (i = n-2; i >= 0; i--){
	result = 0.0;
	for (j = i+1; j < n; j++){
	    result = result + a[i][j] * x[j];
	    c++;
	}
	x[i] = (b[i] - result) / a[i][i];
	c++;
    }

    for (i = 0; i < n; i++){
	printf("%.2f  ", x[i]);
    }
    printf("\nThe number of times in multiplication and division is: %d\n", c);
    
    return 0;
}
