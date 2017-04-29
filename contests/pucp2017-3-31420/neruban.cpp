/*
SPOJ
DOTAA2 - Help Neruban
*/

#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <sstream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef struct hero {
    string name;
    int a;
    int v;
    int s;
} hero;

bool comp(hero x, hero y) {
    if(x.a <= y.a) {
        if(x.a < y.a) return true;
        if(x.v <= y.v) {
            if(x.v < y.v) return true;
            if(x.s >= y.s) {
                if(x.s > y.s) return true;
                if(x.name.compare(y.name) > 0) return true;
            }
        }
    }
    return false;
}

int main() {
    long long i, n;
    vector<hero> heroes;
    vector<hero>::reverse_iterator it;
    hero tmp;
    cin >> n;
    heroes.reserve(n);
    for(i = 0; i < n; ++i) {
        cin >> tmp.name >> tmp.a >> tmp.v >> tmp.s;
        heroes.push_back(tmp);
    }
    sort(heroes.begin(), heroes.end(), comp);
    for(it = heroes.rbegin(); it != heroes.rend(); ++it) {
        cout << it->name << endl;
    }
    return 0;
}
