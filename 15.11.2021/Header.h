#pragma once
#include <iostream>

double determinant(double** A, int n);

double** inverseMatrix(double** A, int n);

template <typename T>
T** minorMatrix(T** A, int n, int row, int col);

template <typename T>
void swapColumns(T** M, double n, int col1, int col2);

template <typename T>
void printMatrix(T** M, int rows, int columns, const char pre[]);

template <typename T>
T** createMatrix(int n, int m);

template <typename T>
T** inputMatrix(int n, int m);

template <typename T>
void deleteMatrix(T** M, int n);

template <typename T>
T** copyMatrix(T** M, int n, int m);

double determinant(double** A, int n) {
	double** M = copyMatrix(A, n, n);
	bool flag;
	int rememb = 0;
	short int signofdet = 1;
	double koef;

	for (int i = 0; i < n - 1; ++i) {

		if (M[i][i] == 0) {
			flag = true;
			for (int j = i + 1; j < n; ++j) {
				if (M[i][j] != 0) {
					flag = false;
					rememb = j;
					break;
				}
			}

			if (flag) {
				deleteMatrix(M, n);
				return 0;
			}
			swapColumns(M, n, i, rememb);
			signofdet *= -1;
		}

		for (int k = i + 1; k < n; ++k) {

			koef = M[k][i] / M[i][i];

			for (int j = i; j < n; ++j) {
				M[k][j] = M[k][j] - koef * M[i][j];
			}

		}
	}

	double result = 1;

	for (int i = 0; i < n; ++i) {
		result *= M[i][i];
	}

	deleteMatrix(M, n);

	if (result == 0) {
		return 0;
	}
	else {
		return result * signofdet;
	}
}

double** inverseMatrix(double** A, int n) {

	double** M = createMatrix<double>(n, n);
	double det = determinant(A, n);

	if (det == 0) {
		throw "Determinant of input matrix is equal to 0";
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			double** T = minorMatrix(A, n, j, i);
			M[i][j] = double(determinant(T, n - 1)) / det;
			deleteMatrix(T, n - 1);

			if ((i + j) % 2) M[i][j] *= -1;

			if (M[i][j] == 0) {
				M[i][j] = 0;
			}

		}
	}

	return M;
}

template <typename T>
T** minorMatrix(T** A, int n, int row, int col) {

	T** B = createMatrix<T>(n - 1, n - 1);

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			B[i][j] = A[i][j];
		}

		for (int j = col + 1; j < n; ++j) {
			B[i][j - 1] = A[i][j];
		}
	}

	for (int i = row + 1; i < n; ++i) {
		for (int j = 0; j < col; ++j) {
			B[i - 1][j] = A[i][j];
		}

		for (int j = col + 1; j < n; ++j) {
			B[i - 1][j - 1] = A[i][j];
		}
	}
	return B;
}

template <typename T>
void swapColumns(T** M, double n, int col1, int col2) {
	for (int i = 0; i < n; ++i) {
		std::swap(M[i][col1], M[i][col2]);
	}
}

template <typename T>
void printMatrix(T** M, int rows, int columns, const char pre[]) {
	std::cout << pre;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			std::cout << M[i][j] << '\t';
		}
		std::cout << std::endl;
	}
}

template <typename T>
T** createMatrix(int n, int m)
{
	T** M = new T * [n];
	for (int i = 0; i < n; ++i)
	{
		M[i] = new T[m];
	}
	return M;
}

template <typename T>
T** inputMatrix(int n, int m)
{
	T** M = createMatrix<T>(n, m);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			std::cout << '(' << i + 1 << ", " << j + 1 << "): ";
			std::cin >> M[i][j];
		}
	}
	return M;
}

template <typename T>
void deleteMatrix(T** M, int n)
{
	for (int i = 0; i < n; ++i)
	{
		delete[] M[i];
	}
	delete[] M;
}

template <typename T>
T** copyMatrix(T** M, int n, int m)
{
	T** A = createMatrix<T>(n, m);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			A[i][j] = T(M[i][j]);
		}
	}
	return A;
}