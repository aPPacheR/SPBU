#include <iostream>

int main()
{
	size_t row, col;
	std::cin >> row >> col;
	unsigned int** M = new unsigned int* [row];
	for (size_t i = 0; i < row; ++i) M[i] = new unsigned int[col];
	size_t x0 = 0, y0 = 0, x1 = col - 1, y1 = row - 1, x = 0, y = 0;
	unsigned int count = 1;
	while (y0 <= y1) {
		while (x < x1 && count <= row*col) M[y][x++] = count++;
		y0++;
		while (y < y1 && count <= row*col) M[y++][x] = count++;
		x1--;
		while (x > x0 && count <= row*col) M[y][x--] = count++;
		y1--;
		while (y > y0 && count <= row*col) M[y--][x] = count++;
		x0++;
	}
	if(count <= row*col) M[y][x] = count;
	for (size_t i = 0; i < row; ++i) {
		for (size_t j = 0; j < col; ++j) {
			std::cout << M[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	for (size_t i = 0; i < row; ++i) delete[] M[i];
	delete[] M;
}
