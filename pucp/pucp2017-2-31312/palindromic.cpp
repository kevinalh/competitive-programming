/*
Codeforces
108A - Palindromic Times
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {
	int a, b, i, j;
	cin >> a;
	cin.ignore();
	cin >> b;
	for(i = a; i < 24; i++) {
		if(i == a) {
			j = b+1;
		}
		else j = 0;
		for(; j < 60; j++) {
			if(i%10 == j/10 && i/10 == j%10) {
				if(i/10 == 0) cout << "0";
				cout << i;
				cout << ":";
				if(j/10 == 0) cout << "0";
				cout << j << endl;
				return 0;
			}
		}
	}
	cout << "00:00" << endl;
	return 0;
}