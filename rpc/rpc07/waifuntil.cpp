#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#define MAXN 102

using namespace std;

int n, m, p;

int main() {
    /* n children, m toys, p toy categories */
    cin >> n >> m >> p;
    vector<int> chd[MAXN];
    int cat[MAXN], maxcat[MAXN];
    int i, k, toy;
    for(i = 0; i < n; ++i) {
        cin >> k;
        while(k--) {
            cin >> toy;
            chd[toy-1].push_back(i);
        }
    }
    for(i = 0; i < m; ++i) {
        /* 101th category: No category */
        cat[toy] = 101;
    }
    for(i = 0; i < p; ++i) {
        cin >> k;
        while(k--) {
            cin >> toy;
            cat[toy-1] = i;
        }
        cin >> maxcat[i];
    }
    return 0;
}