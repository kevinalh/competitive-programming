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
    long long i, j;
    string line, word, trans;
    map<string, string> dict;
    map<string, string>::iterator it;
    while(1) {
        getline(cin, line);
        if(line.size() == 0) break;
        istringstream s(line);
        s >> trans >> word;
        dict[word] = trans;
    }
    while(1) {
        getline(cin, line);
        if(line.size() == 0) break;
        it = dict.find(line);
        if(it != dict.end()) {
            cout << it->second << endl;
        } else {
            cout << "eh" << endl;
        }
    }
    return 0;
}