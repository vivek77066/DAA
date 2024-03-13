#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    int i, n, t1 = 0, t2 = 1, nT;
    cin >> n;
    auto start = high_resolution_clock::now();
    for (i = 1; i <= n; ++i) {
        cout << t1 << " ";
        nT = t1 + t2;
        t1 = t2;
        t2 = nT;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<endl;
    cout << duration.count()<<"micosecond" << endl;
    return 0;
}