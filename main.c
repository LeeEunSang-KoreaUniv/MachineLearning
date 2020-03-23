#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"


int main() {
	Matrix* X = Transpose(NewMatrix(4, 2));
	ShowMatrix(X);
	Matrix* Y = NewMatrix(4, 1);
	ShowMatrix(Y);
	Matrix* theta = NewMatrix(2, 1);
	double alpha = 0;
	printf("Learning rate Input: ");
	scanf_s("%lg", &alpha);
	theta = Gradient_Descent(theta, X, Y, alpha);
	
	return 0;
}