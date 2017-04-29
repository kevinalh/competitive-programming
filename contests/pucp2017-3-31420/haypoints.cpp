#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <sstream>

using namespace std;

int main() {
    unsigned long long i, j, n, m;
    string tmp;
    vector<string> palabras;
    unsigned long long value;
    map<string, unsigned long long> dict;
    map<string, unsigned long long>::iterator it;
    cin >> m >> n;
    for(i = 0; i < m; ++i) {
        cin >> tmp >> value;
        dict[tmp] = value;
    }
    for(i = 0; i < n; ++i) {
        value = 0;
        while(1) {
            cin >> tmp;
            if(tmp.compare(".") == 0) break;
            it = dict.find(tmp);
            if(it != dict.end()) {
                value += it->second;
            }
        }
        cout << value << endl;
    }
    return 0;
}