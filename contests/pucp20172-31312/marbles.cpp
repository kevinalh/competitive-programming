/*
SPOJ
Marbles
*/

#include <vector>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

long long comb(long long n, long long k) {
    if(k > n) return 0;
    if(k > n - k) k = n - k;
    long long i;
    __int128 f = 1;
    for(i = 1; i <= k; ++i) {
        f *= n;
        f /= i;
        --n;
    }
    return f;
}

int main() {
    int i, T;
    long long n, k;
    cin >> T;
    for(i = 0; i < T; i++) {
        cin >> n >> k;
        cout << comb(n-1, n-k) << endl;
    }
    return 0;
}