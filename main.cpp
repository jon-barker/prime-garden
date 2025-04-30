#include <chrono>
#include <iostream>

// Returns true if n is prime, false otherwise
inline bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n == 3) return true;
    if ((n & 1) == 0) return false;  // equivalent to n % 2 == 0

    // Check for divisibility by 3
    if (n % 3 == 0) return false;

    // Only test odd divisors of the form 6k+1 and 6k+5 up to sqrt(n)
    // since all primes >5 have one of those forms
    for (int i = 5; i <= n / i; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0)
        return false;
    }
    return true;
}

int main() {
    std::cout << "Enter the maximum number to check for primality: ";
    int N;
    std::cin >> N;
    bool is_prime {false};

    std::chrono::duration<double, std::milli> total_ms {0};
    std::chrono::duration<double, std::milli> working_ms {0};

    auto total_start = std::chrono::high_resolution_clock::now();
    for (int i = 2; i <= N; ++i) {
        auto working_start = std::chrono::high_resolution_clock::now();
        is_prime = isPrime(i);
        auto working_end = std::chrono::high_resolution_clock::now();
        working_ms += (working_end - working_start);
        if (is_prime) {
            std::cout << i << " is prime\n";
        }
    }
    auto total_end = std::chrono::high_resolution_clock::now();
    total_ms = (total_end - total_start);

    std::cout << "Elapsed time: " << total_ms.count() << " ms\n";
    std::cout << "Working time: " << working_ms.count() << " ms\n";

    return 0;
}
