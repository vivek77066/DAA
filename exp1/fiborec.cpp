#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

// Recursive function for Fibonacci
int fibonacci(int n) {
    // If n is zero or one, return the number itself
    if (n <= 1) {
        return n;
    }
    // Recursive call to n-1 and n-2
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    n = 5;
    auto start = high_resolution_clock::now();
    cout << fibonacci(n);
     auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<endl;
    cout << duration.count()<<"micosecond" << endl;
}