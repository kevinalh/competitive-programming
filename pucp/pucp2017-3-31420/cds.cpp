#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    unsigned long long i, j, n, m, sum;
    set<unsigned long long> cds;
    while(1) {
        sum = 0;
        cds.clear();
        cin >> n >> m;
        if(n == m && n == 0) break;
        for(i = 0; i < n; ++i) {
            cin >> j;
            cds.insert(j);
        }
        for(i = 0; i < m; ++i) {
            cin >> j;
            if(cds.find(j) != cds.end()) {
                ++sum;
            }
        }
        cout << sum << endl;
    }
    return 0;
}