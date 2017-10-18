#include <iostream>
#include <cctype>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> seq;
vector<int> ms;

int main() {
    int t, n, sz;
    unsigned long long sum;
    cin >> t;
    while(t--) {
        sum = 0;
        seq.clear();
        ms.clear();
        cin >> n;
        seq.resize(n+1);
        ms.resize(n+1);
        for(int i = 0; i < n; ++i) {
            cin >> seq[i];
        }
        sort(seq.begin(), seq.end());
        for(int i = 0; i < n; ++i) {
            if(i % 2 == 0) ms[(n/2) + (i/2)] = seq[i];
            else ms[(n/2) - (i+1)/2 - 1] = seq[i];
            if(i != n-1) sum += seq[i]*seq[i+1];
        }
        cout << sum << endl;
        for(int i = 0; i < n; ++i) {
            cout << seq[i] << " ";
        }
        cout << endl;
    }
}
