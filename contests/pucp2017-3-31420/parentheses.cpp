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
#include <stack>

using namespace std;

bool correct(string s) {
	stack<char> par;
	int i, j, len;
	len = s.length();
	for(i = 0; i < len; ++i) {
		switch(s[i]) {
			case '(':
				par.push('(');
				break;
			case '[':
				par.push('[');
				break;
			case ')':
				if(par.empty() || par.top() == '[')
					return false;
				par.pop();
				break;
			case ']':
				if(par.empty() || par.top() == '(')
					return false;
				par.pop();
				break;
			default:
				return false;
		}
	}
	if(par.empty())
		return true;
	else return false;
}

int main() {
    unsigned long long n, i;
	string s;
	getline(cin, s);
	n = stol(s, nullptr, 10);
    for(i = 0; i < n; ++i) {
		s.clear();
		getline(cin, s);
		if (correct(s)) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
    }
    return 0;
}
