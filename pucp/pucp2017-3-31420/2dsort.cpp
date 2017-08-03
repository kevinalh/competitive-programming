#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <sstream>
#include <cstdio>

using namespace std;

bool lex(pair<long long, long long> a, pair<long long, long long> b) {
    return (a.first < b.first) || (a.first == b.first && a.second > b.second);
}

int main() {
    int tests, test;
    long long n, a, b, i;
    vector<pair<long long, long long>> num;
    scanf("%d", &tests);
    for(test = 0; test < tests; ++test){
        scanf("%lld", &n);
        num.clear();
        num.reserve(n+1);
        for(i = 0; i < n; ++i) {
            scanf("%lld %lld", &a, &b);
            num.push_back(make_pair(a, b));
        }
        sort(num.begin(), num.end(), lex);
        for(i = 0; i < n; ++i) {
            printf("%lld %lld\n", num[i].first, num[i].second);
        }
    }
    return 0;
}