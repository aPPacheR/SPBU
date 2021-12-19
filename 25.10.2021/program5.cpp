#include <iostream>
#include <time.h>

void fillArray(int n, int arr[]) {

    srand(time(NULL));
    int flag, temp;

    for (int i = 0; i < n; ) {

        flag = 0;
        temp = rand() % (n + 1); //текущее число

        for (int j = 0; j < i; ++j) {
            if (arr[j] == temp) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            arr[i] = temp;
            ++i;
        }
    }
}


int main() {
    int n;

    do {
        std::cout << "Input length of array: ";
        std::cin >> n;
    } while (n < 2);

    int* arr = new int[n];

    fillArray(n, arr);

    int summexp = (n * (n + 1)) / 2;
    int summreal = 0;

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
        summreal += arr[i];
    }

    std::cout << std::endl;
    std::cout << "Отсутствующее число: " << summexp - summreal << std::endl;

    delete[] arr;

    return 0;
}
