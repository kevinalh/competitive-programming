/*
Codeforces
236A - Boy or Girl
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {
	string nombre;
	getline(cin, nombre);
	int i, j;
	int tm = nombre.size();
	int tm2 = 0;
	for(i = 0; i < tm; i++) {
		for(j = i+1; j < tm; j++) {
			if(nombre[i] == nombre[j])
				nombre[j] = 'X';
		}
	}
	for(i = 0; i < tm; i++) {
		if(nombre[i] != 'X') tm2++;
	}
	if(tm2 % 2 == 0) {
		cout << "CHAT WITH HER!" << endl;
	} else cout << "IGNORE HIM!" << endl;
	return 0;

}