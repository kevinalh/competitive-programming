/*
Codeforces
178A1 - Educational Game
*/

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long i, n, tmp, k, steps, t;
    cin >> n;
    vector<long long> a;
    a.reserve(n+1);
    for(i = 0; i < n; ++i) {
        cin >> tmp;
        a.push_back(tmp);
    }
    steps = 0;
    for(k = 0; k < n-1; ++k) {;
        t = floor(log(n-k-1)/log(2));
        while(a[k] > 0) {
            --a[k];
            ++a[k+pow(2,t)];
            ++steps;
        }
        cout << steps << endl;
    }
    return 0;
}