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
    vector<long long> num;
    map<long long, long long> rep;
    long long a;
    string line;
    while(1) {
        getline(cin, line);
        if(line.size() == 0) break;
        istringstream s(line);
        while(s >> a) {
            if(find(num.begin(), num.end(), a) != num.end()) {
                ++rep[a];
            } else {
                num.push_back(a);
                rep[a] = 1;
            }
        }
    }
    for(int i = 0; i < num.size(); ++i) {
        cout << num[i] << " " << rep[num[i]] << endl;
    }
    return 0;
}