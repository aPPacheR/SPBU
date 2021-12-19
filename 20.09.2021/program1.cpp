#include <iostream>

int main(int argc, char** argv) {

	unsigned long long S = 0;
	unsigned long long int min = -1;
	int n = 0;
	for (unsigned long long i = 0; i < 1000000; i++) {
		S = i * i;
		if (S % 1000000 == 269696)
			if (S < min) {
				min = S;
				n = i;
			}
	}
	std::cout << " Min number: " << n << ", min square : " << min << std::endl;
	std::cout << std::endl;
	system("pause");
	return 0;
}