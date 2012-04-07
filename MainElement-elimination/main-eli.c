#include <stdio.h>

/* To reduce the error, the main element elimination method works better than Gaussian elimination. */
int main(){
    float a[100][100], l[100][100], b[100], x[100];
    float max, temp, result;
    int n, i, j, k, r, c = 0;
    
    printf("\n----------------------------------------------------------------------------\n This algorithm is used to solve 'Ax = B' with the main element elimination. \n----------------------------------------------------------------------------\n");
    printf("Please enter the dimension of A: ");
    scanf("%d", &n);
    printf("Please enter the elements in A: ");
    for (i = 0; i < n; i++){
	for (j = 0; j < n; j++)
	    scanf("%f", &a[i][j]);
    }
    printf("Please enter the elements in B: ");
    for (i = 0; i < n; i++)
	scanf("%f", &b[i]);
    
    for (k = 0; k < n-1; k++){
	/* select the maximum in one column */
	r = k;
	max = a[k][k];
	for (i = k+1; i < n; i++){
	    if (max < a[i][k]){
		r = i;
		max = a[i][k];
	    }
	}
	/* exchange row r and row k if necessary */
	if (r != k){
	    for (i = k; i < n; i++){
		temp = a[r][i];
		a[r][i] = a[k][i];
		a[k][i] = temp;
	    }
	    temp = b[r];
	    b[r] = b[k];
	    b[k] = temp;
	}
	/* elimination */
	for (i = k+1; i < n; i++){
	    l[i][k] = a[i][k] / a[k][k];
	    c++;
	}
	for (i = k+1; i < n; i++){
	    b[i] = b[i] - l[i][k] * b[k];
	    c++;
	    for (j = k+1; j < n; j++){
		a[i][j] = a[i][j] - l[i][k] * a[k][j];
		c++;
	    }
	    a[i][k] = 0;
	}
    }

    printf("After converting, A(%d*%d) and B(%d*1) can be:\n", n, n, n);
    for (i = 0; i < n; i++){
	for (j = 0; j < n; j++){
	    printf("%.2f ",a[i][j]);
	}
	printf("%.2f\n", b[i]);
    }

    /* the result */
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
