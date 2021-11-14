#include <iostream>

void rhomb(int n) {
    int i, j, N;
    N = 2 * n - 1;
    int center = N / 2;
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            if (i <= center){
                if (j >= center - i && j <= center + i)
                    std::cout << "*";
                else
                    std::cout << " ";
            }
            else{
                if (j >= center + i - N + 1 && j <= center - i + N - 1)
                    std::cout << "*";
                else
                    std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

int main()
{
    int i, j, n, N, K;
    std::cout << "Write height: "; std::cin >> n;
    std::cout << "Write count: "; std::cin >> K;
    std::cout << std::endl;
    for (int k = 0; k < K; ++k) {
        rhomb(n);
    }
    system("PAUSE");
    return 0;
}