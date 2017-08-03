/*
Codeforces
177B2 - Rectangular Game
*/

#include <vector>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

long long maxdivisor(long long a) {
    long long i;
    long long j = sqrt(a);
    for(i = 2; i <= j; ++i) {
        if(a % i == 0) return a/i;
    }
    return 1;
}

int main() {
    long long n, c;
    cin >> n;
    c = n;
    while(n > 1) {
        n = maxdivisor(n);
        c += n;
    }
    cout << c << endl;
    return 0;
}