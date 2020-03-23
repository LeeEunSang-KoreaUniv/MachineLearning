#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"



Matrix* NewMatrix(int r, int c) {
	Matrix* mat = NULL;
	mat = (Matrix*)malloc(sizeof(Matrix));
	if (mat != NULL) {
		mat->row_level = r;
		mat->column_level = c;
		for (int i = 0; i < r; i++) {
			printf("%d번째 행: ", i + 1);
			for (int j = 0; j < c; j++) {
				scanf_s("%lg", &((mat->matrix)[i][j]));
			}
		}
		printf("[%d x %d] 크기의 행렬을 생성하였습니다. \n\n", mat->row_level, mat->column_level);
		return mat;
	}
	else {
		printf("에러1, 메모리 할당에 실패하였습니다. \n");
		return NULL;
	}
}

void ShowMatrix(Matrix* mat) {
	if (mat != NULL) {
		printf("<Matrix> \n");
		printf("크기: [%d x %d] \n", mat->row_level, mat->column_level);
		for (int i = 0; i < mat->row_level; i++) {
			printf("[  ");
			for (int j = 0; j < mat->column_level; j++) {
				printf("%lg  ", ((mat->matrix)[i][j]));
			}
			printf("]\n");
		}
		printf("\n\n");
	}
	else {
		printf("에러2, 전달된 행렬이 없습니다. \n");
	}
}

int IS_it_Zero_Matrix(Matrix* mat) {
	if (mat != NULL) {
		for (int i = 0; i < mat->row_level; i++) {
			for (int j = 0; j < mat->column_level; j++) {
				if ((mat->matrix)[i][j] != 0) {
					return 0;
				}
			}
		}
		return 1;
	}
	else {
		printf("에러3, 전달된 행렬이 적절하지 않습니다. \n");
		return 0;
	}
}

int IS_it_Same_Matrix(Matrix* mat1, Matrix* mat2) {
	if (mat1 != NULL && mat2 != NULL && mat1->row_level == mat2->row_level && mat1->column_level == mat2->column_level) {
		for (int i = 0; i < mat1->row_level; i++) {
			for (int j = 0; j < mat1->column_level; j++) {
				if ((mat1->matrix)[i][j] != (mat2->matrix)[i][j]) {
					return 0;
				}
			}
		}
		return 1;
	}
	else {
		printf("에러4, 전달된 행렬이 적절하지 않습니다. \n");
		return 0;
	}
}



Matrix* Transpose(Matrix* mat1) {
	Matrix* mat2 = NULL;
	mat2 = (Matrix*)malloc(sizeof(Matrix));
	if (mat1 != NULL && mat2 != NULL) {
		for (int i = 0; i < mat1->column_level; i++) {
			for (int j = 0; j < mat1->row_level; j++) {
				(mat2->matrix)[i][j] = (mat1->matrix)[j][i];
			}
		}
		mat2->row_level = mat1->column_level;
		mat2->column_level = mat1->row_level;
		return mat2;
	}
	else {
		printf("에러5, 메모리 할당이 실패하였습니다. \n");
		return NULL;
	}
}

double Vector_Norm(Matrix* mat) {
	if (mat != NULL) {
		double sum = 0;
		for (int i = 0; i < mat->row_level; i++) {
			sum += (mat->matrix)[i][0] * (mat->matrix)[i][0];
		}
		return sqrt(sum);
	}
	else {
		printf("에러21, 전달된 행렬이 없습니다. \n");
		return 0;
	}
}
double Vector_dotproduct(double* v1, double* v2, int l) {
	double sum = 0;
	for (int i = 0; i < l; i++) {
		sum += (*(v1 + i)) * (*(v2 + i));
	}
	return sum;
}

Matrix* Matrix_Add(Matrix* mat1, Matrix* mat2) {
	if (mat1->row_level == mat2->row_level && mat1->column_level == mat2->column_level) {
		Matrix* mat3 = NULL;
		mat3 = (Matrix*)malloc(sizeof(Matrix));
		if (mat3 != NULL) {
			mat3->row_level = mat1->row_level;
			mat3->column_level = mat1->column_level;
			for (int i = 0; i < mat1->row_level; i++) {
				for (int j = 0; j < mat1->column_level; j++) {
					*(*((mat3->matrix) + i) + j) = (*(*((mat1->matrix) + i) + j)) + (*(*((mat2->matrix) + i) + j));
				}
			}
			return mat3;
		}
		else {
			printf("에러6, 메모리할당에 실패하였습니다. \n");
			return NULL;
		}
	}
	else {
		printf("에러7, 두 행렬의 차원이 행렬합을 하기에 적절하지 않습니다. \n");
		return NULL;
	}
}

Matrix* Matrix_Substract(Matrix* mat1, Matrix* mat2) {
	if (mat1->row_level == mat2->row_level && mat1->column_level == mat2->column_level) {
		Matrix* mat3 = NULL;
		mat3 = (Matrix*)malloc(sizeof(Matrix));
		if (mat3 != NULL) {
			mat3->row_level = mat1->row_level;
			mat3->column_level = mat1->column_level;
			for (int i = 0; i < mat1->row_level; i++) {
				for (int j = 0; j < mat1->column_level; j++) {
					*(*((mat3->matrix) + i) + j) = (*(*((mat1->matrix) + i) + j)) - (*(*((mat2->matrix) + i) + j));
				}
			}
			return mat3;
		}
		else {
			printf("에러8, 메모리할당에 실패하였습니다. \n");
			return NULL;
		}
	}
	else {
		printf("에러9, 두 행렬의 차원이 행렬합을 하기에 적절하지 않습니다. \n");
		return NULL;
	}
}

Matrix* Matrix_Multiply(Matrix* mat1, Matrix* mat2) {
	if (mat1->column_level == mat2->row_level) {
		Matrix* mat3 = NULL;
		mat3 = (Matrix*)malloc(sizeof(Matrix));
		if (mat3 != NULL) {
			mat3->row_level = mat1->row_level;
			mat3->column_level = mat2->column_level;
			Matrix* mat2_T = Transpose(mat2);
			for (int i = 0; i < mat3->row_level; i++) {
				for (int j = 0; j < mat3->column_level; j++) {
					*((*((mat3->matrix) + i)) + j) = Vector_dotproduct(*((mat1->matrix) + i), *((mat2_T->matrix) + j), mat1->column_level);
				}
			}
			free(mat2_T);
			return mat3;
		}
		else {
			printf("에러10, 메모리할당에 실패하였습니다. \n");
			return NULL;
		}
	}
	else {
		printf("에러11, 두 행렬의 차원이 행렬곱을 하기에 적절하지 않습니다. \n");
		return NULL;
	}
}

Matrix* Matrix_Wisemultiply(Matrix* mat1, Matrix* mat2) {
	if (mat1->row_level == mat2->row_level && mat1->column_level == mat2->column_level) {
		Matrix* mat3 = NULL;
		mat3 = (Matrix*)malloc(sizeof(Matrix));
		if (mat3 != NULL) {
			mat3->row_level = mat1->row_level;
			mat3->column_level = mat1->column_level;
			for (int i = 0; i < mat1->row_level; i++) {
				for (int j = 0; j < mat1->column_level; j++) {
					*(*((mat3->matrix) + i) + j) = (*(*((mat1->matrix) + i) + j)) * (*(*((mat2->matrix) + i) + j));
				}
			}
			return mat3;
		}
		else {
			printf("에러12, 메모리할당에 실패하였습니다. \n");
			return NULL;
		}
	}
	else {
		printf("에러13, 두 행렬의 차원이 행렬합을 하기에 적절하지 않습니다. \n");
		return NULL;
	}
}

double Matrix_element_multiply(Matrix* mat) {
	if (mat != NULL) {
		double result = 1;
		for (int i = 0; i < mat->row_level; i++) {
			for (int j = 0; j < mat->column_level; j++) {
				result *= (mat->matrix)[i][j];
			}
		}
		return result;

	}
	else {
		printf("에러20, 전달된 행렬이 적절하지 않습니다. \n");
		return 0;
	}
}


Matrix* Linear_Regression_h_function(Matrix* theta, Matrix* X) {
	if ((theta != NULL && X != NULL) && (theta->column_level == 1)) {
		Matrix* h_0x = NULL;
		Matrix* mat1 = NULL;
		mat1 = Transpose(X);
		h_0x = Matrix_Multiply(mat1, theta);
		free(mat1);
		if (h_0x != NULL) {
			return h_0x;
		}
		else {
			printf("에러14, 연산실패 \n");
			return NULL;
		}
	}
	else {
		printf("에러15, 전달된 행렬이 적절하지 않습니다. \n");
		return NULL;
	}
}

Matrix* Logistic_Regression_h_function(Matrix* theta, Matrix* X) {
	if ((theta != NULL && X != NULL) && (theta->column_level == 1)) {
		Matrix* h_0x = NULL;
		Matrix* mat1 = NULL;
		mat1 = Transpose(X);
		h_0x = Matrix_Multiply(mat1, theta);
		free(mat1);
		double result;
		for (int i = 0; i < h_0x->row_level; i++) {
			result = 0;
			result = 1 / (1 + exp(-((h_0x->matrix)[i][0])));
			(h_0x->matrix)[i][0] = result;
		}
		if (h_0x != NULL) {
			return h_0x;
		}
		else {
			printf("에러16, 연산실패 \n");
			return NULL;
		}
	}
	else {
		printf("에러17, 전달된 행렬이 적절하지 않습니다. \n");
		return NULL;
	}
}

Matrix* Gradient_Descent(Matrix* theta, Matrix* X, Matrix* Y, double alpha) {
	if (theta != NULL && X != NULL && Y != NULL) {
		int num = 0;
		double m = Y->row_level;
		printf("회귀의 종류를 정해주세요. \n   (0: Linear Regression) \n   (1: Logistic Regression) \n 입력: ");
		scanf_s("%d", &num);
		if (num == 0) {
			Matrix* mat1;
			Matrix* mat2;
			Matrix* mat3;
			while (1) {
				ShowMatrix(theta);
				mat1 = NULL;
				mat2 = NULL;
				mat3 = NULL;
				mat1 = Linear_Regression_h_function(theta, X);
				mat2 = Matrix_Substract(mat1, Y);
				mat3 = Matrix_Multiply(X, mat2);
				free(mat1);
				free(mat2);
				for (int i = 0; i < theta->row_level; i++) {
					(mat3->matrix)[i][0] = ((mat3->matrix)[i][0] * alpha) / m;
				}
				mat1= Matrix_Substract(theta, mat3);
				if (Vector_Norm(mat3) < 0.000001) {
					free(mat3);
					free(theta);
					theta = mat1;
					break;
				}
				else {
					free(mat3);
					free(theta);
					theta = mat1;
				}
			}
			printf("<gradient descent 종료> \n\n");
			ShowMatrix(theta);
			return theta;
		}
		else if (num == 1) {
			Matrix* mat1;
			Matrix* mat2;
			Matrix* mat3;
			while (1) {
				ShowMatrix(theta);
				mat1 = NULL;
				mat2 = NULL;
				mat3 = NULL;
				mat1 = Logistic_Regression_h_function(theta, X);
				mat2 = Matrix_Substract(mat1, Y);
				mat3 = Matrix_Multiply(X, mat2);
				free(mat1);
				free(mat2);
				for (int i = 0; i < theta->row_level; i++) {
					(mat3->matrix)[i][0] = ((mat3->matrix)[i][0] * alpha) / m;
				}
				mat1 = Matrix_Substract(theta, mat3);
				
				if (Vector_Norm(mat3) < 0.000001) {
					free(mat3);
					free(theta);
					theta = mat1;
					break;
				}
				else {
					free(mat3);
					free(theta);
					theta = mat1;
				}
			}
			printf("<gradient descent 종료>\n");
			ShowMatrix(theta);
			return theta;
		}
		else {
			printf("에러18, 입력된 정보가 적절하지 않습니다. \n");
		}
	}
	else {
		printf("에러19, 전달된 행렬이 적절하지 않습니다. \n");
		return NULL;
	}
}


