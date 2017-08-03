#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long i, n, k, test, tests, candy, max;
    set<long long>::iterator it_i, it_f, it;
    multiset<long long> candyset;
    cin >> tests;
    for(test = 0; test < tests; ++test) {
        queue<multiset<long long>::iterator> candies;
        candyset.clear();
        cin >> n >> k;
        for(i = 0; i < k; ++i) {
            cin >> candy;
            if(i == 0) {
                it = candyset.insert(candy);
                candies.push(it);
            }
            else {
                it = candyset.insert(it, candy);
                candies.push(it);
            }
        }
        cout << *candyset.rbegin() << " ";
        for(i = k; i < n; ++i) {
            cin >> candy;
            it = candyset.insert(it, candy);
            candies.push(it);
            candyset.erase(candies.front());
            candies.pop();
            cout << *candyset.rbegin() << " ";
        }
        cout << "\n";
    }
    return 0;
}
