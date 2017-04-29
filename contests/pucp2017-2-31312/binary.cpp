/*
Codeforces
92B - Binary Number
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {
	string binario;
	cin >> binario;
	long pasos = 0;
	string::reverse_iterator it;
	string::iterator it2;
	while(binario.compare("1") != 0) {
		if(binario.back() == '1') {
			for(it = binario.rbegin(); it != binario.rend(); ++it) {
				if(*it == '0') {
					*it = '1';
					for(it2 = it.base(); it2 != binario.end(); ++it2) {
						*it2 = '0';
					}
					break;
				}
			}
			/* If they are all 1's' */
			if(it == binario.rend()) {
				for(it2 = binario.begin(); it2 != binario.end(); ++it2) {
					*it2 = '0';
				}
				binario.insert(0, 1, '1');
			}
		} else {
			binario.pop_back();
		}
		pasos++;
	}
	cout << pasos << endl;
	return 0;
}