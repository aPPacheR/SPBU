
#include <iostream>

int main() {
	int n;
	do {
		std::cout << "Write number of pairs: ";  std::cin >> n;
		std::cout << std::endl;
	} while (n < 0);
	n = n * 2;
	for (int r = 0; r <= n / 4; r++) {
		std::cout << "Rabbits: " << r << ", Geese: " << (n - r * 4) / 2 << std::endl;
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}