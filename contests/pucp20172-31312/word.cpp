/*
Codeforces
59A - Word
*/

#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

#define MAXN 102

int main() {
    string s, up, low;
    cin >> s;
    int len = s.size();
    low.reserve(len+1);
    up.reserve(len+1);
    int mayusculas = 0;
    for(int i = 0; i < len; i++) {
        up.push_back(toupper(s[i]));
        low.push_back(tolower(s[i]));
        if(isupper(s[i])) mayusculas++;
    }
    if(mayusculas > len / 2) {
        cout << up << endl;
    } else {
        cout << low << endl;
    }
    return 0;
}