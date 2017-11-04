#include <vector>
#include <queue>
#include <random>
#include <string>
#include <iostream>

using namespace std;

int main() {
    int i, j;
    vector<string> s;
    string tmp;
    char let;
    s.reserve(101);
    random_device rd;
    mt19937 eng(rd());
    uniform_int_distribution<> distr(1, 100);
    uniform_int_distribution<> d2((int) 'a', (int) 'z');
    for(i = 0; i < 100; ++i) {
        int rlength = distr(eng);
        tmp.clear();
        for(j = 0; j < rlength; ++j) {
            let = (char) d2(eng);
            tmp.push_back(let);
        }
        s.push_back(tmp);
    }
    for(i = 0; i < 100; ++i) {
        cout << s[i] << endl;
    }
    return 0;
}
