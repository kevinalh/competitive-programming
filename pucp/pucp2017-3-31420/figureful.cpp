#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    long long i, n, t;
    long long a, b;
    string tmp;
    map<pair<long long, long long>, string >::iterator j;
    pair<long long, long long> tmp2;
    map<pair<long long, long long>, string> nom; 
    cin >> n;
    for(i = 0; i < n; ++i) {
        cin >> a >> b >> tmp;
        nom[make_pair(a, b)] = tmp;
    }
    cin >> t;
    for(i = 0; i < t; ++i) {
        cin >> a >> b;
        tmp2 = make_pair(a, b);
        cout << nom.find(tmp2)->second << endl;
    }
    return 0;
}