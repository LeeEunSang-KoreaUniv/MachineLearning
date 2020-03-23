#ifndef _MATRIX_
#define _MATRIX_


typedef struct {
	int row_level;
	int column_level;
	double matrix[100][100];
} Matrix;


Matrix* NewMatrix(int r, int c);
void ShowMatrix(Matrix* mat);
int IS_it_Zero_Matrix(Matrix* mat);
int IS_it_Same_Matrix(Matrix* mat1, Matrix* mat2);
Matrix* Transpose(Matrix* mat1);
double Vector_dotproduct(double* v1, double* v2, int l);
double Vector_Norm(Matrix* mat);
Matrix* Matrix_Add(Matrix* mat1, Matrix* mat2);
Matrix* Matrix_Substract(Matrix* mat1, Matrix* mat2);
Matrix* Matrix_Multiply(Matrix* mat1, Matrix* mat2);
Matrix* Matrix_Wisemultiply(Matrix* mat1, Matrix* mat2);
double Matrix_element_multiply(Matrix* mat);
Matrix* Linear_Regression_h_function(Matrix* theta, Matrix* X);
Matrix* Logistic_Regression_h_function(Matrix* theta, Matrix* X);
Matrix* Gradient_Descent(Matrix* theta, Matrix* X, Matrix* Y, double alpha);

#endif