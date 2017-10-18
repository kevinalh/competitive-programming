/*
UVa
00272 - TEX Quotes
*/

#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	string input, tmp;
	while (getline(cin, tmp) {
        input += tmp;
    }
	string out = input;
	string outtmp;
	bool bandera = false;
	for (int i = 0; i<out.size(); i++) {
		if (out[i] == '\"') {
			if (bandera == false) {
				out[i] = '`';
				outtmp = '`' + string(out.begin() + i, out.end());
				out = string(out.begin(), out.begin() + i) + outtmp;
				i++;
				bandera = true;
			}
			else {
				out[i] = '\'';
				outtmp = '\'' + string(out.begin() + i, out.end());
				out = string(out.begin(), out.begin() + i) + outtmp;
				i++;
				bandera = false;
			}

		}
	}
	cout << out << endl;
	return 0;
}