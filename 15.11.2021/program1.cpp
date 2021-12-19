#include <iostream>
#include "Header.h"

int main() {
	int n;
	do
	{
		std::cout << "Input size of square matrix: ";
		std::cin >> n;
	} while (n < 1);

	double** A = inputMatrix<double>(n, n);

	printMatrix(A, n, n, "A = \n");

	std::cout << "Determinant = " << determinant(A, n) << std::endl;

	try {
		double** B = inverseMatrix(A, n);
		printMatrix(B, n, n, "Inverse matrix = \n");
		deleteMatrix(B, n);
	}
	catch (const char c[]) {
		std::cout << "Error: " << c << std::endl;
	}
	catch (...) {
		std::cout << "Unknown error" << std::endl;
	}

	deleteMatrix(A, n);

	return 0;
}