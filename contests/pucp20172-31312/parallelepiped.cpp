/*
Codeforces
224A - Parallelepiped
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
	int x, y, z;
	cin >> x >> y >> z;
	int suma = floor( 4*sqrt(x*y/z) + 4*sqrt(x*z/y) + 4*sqrt(z*y/x));
	cout << suma << endl;
	return 0;
}