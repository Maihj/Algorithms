#include <stdio.h>

/* To reduce the error, the main element elimination method works better than Gaussian elimination. */
int main(){
    float a[100][100], l[100][100], b[100];
    float max, temp;
    int n, i, j, k, r;
    
    printf("Please enter the dimension of A: ");
    scanf("%d", &n);
    printf("Please enter the elements in A: ");
    for (i = 0; i < n; i++){
	for (j = 0; j < n; j++)
	    scanf("%f", &a[i][j]);
    }
    printf("Please enter the elements in b: ");
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
		temp = b[r];
		b[r] = b[k];
		b[k] = temp;
	    }
	}
	for (i = k+1; i < n; i++){
	    l[i][k] = a[i][k] / a[k][k];
	    b[i] = b[i] - l[i][k] * b[k];
	    for (j = k+1; j < n; j++)
		a[i][j] = a[i][j] - l[i][k] * a[k][j];
	    a[i][k] = 0;
	}
    }
    for (i = 0; i < n; i++){
	for (j = 0; j < n; j++){
	    printf("%f ",a[i][j]);
	}
	printf("%f\n", b[i]);
    }

    return 0;
}
