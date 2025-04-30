#include <iostream>

// Returns true if n is prime, false otherwise
inline bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if ((n & 1) == 0) return false;  // equivalent to n % 2 == 0

    // Only test odd divisors up to sqrt(n)
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    std::cout << "Enter the maximum number to check for primality: ";
    int N;
    std::cin >> N;

    for (int i = 2; i <= N; ++i) {
        if (isPrime(i)) {
            std::cout << i << " is prime\n";
        }
    }

    return 0;
}
