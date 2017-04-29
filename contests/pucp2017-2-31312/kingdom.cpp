/*
Codeforces
99A - Help Far Away Kingdom
*/

#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

bool punto(char c) {
	return c == '.';
}

int main() {
	string num;
	getline(cin, num);
	string::iterator dot;
	dot = find_if(num.begin(), num.end(), punto);
	if(*(dot-1) == '9') {
		cout << "GOTO Vasilisa.";
	} else if(*(dot+1) < '5') {
		cout << num.substr(0, distance(num.begin(), dot));
	} else {
		*(dot-1) = *(dot-1) + 1;
		cout << num.substr(0, distance(num.begin(), dot));
	}
	cout << endl;
	return 0;
}