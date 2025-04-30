#include <chrono>
#include <iostream>

class ScopedTimer {
    const char* label;
    std::chrono::high_resolution_clock::time_point start;
public:
    explicit ScopedTimer(const char* label)
        : label(label), start(std::chrono::high_resolution_clock::now()) {}

    ~ScopedTimer() {
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end - start;
        std::cout << label << ": " << elapsed.count() << " ms\n";
    }
};

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

    {
        ScopedTimer total_timer("Total time");
        for (int i = 2; i <= N; ++i) {
            ScopedTimer loop_timer("  isPrime");
            is_prime = isPrime(i);
            if (is_prime) std::cout << i << " is prime\n";
        }
    }

    return 0;
}
