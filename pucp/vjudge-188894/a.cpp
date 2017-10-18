#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int m;

int mk(int b) {
	return m < b ? m : b;
}

int main() {
	int a[4];
	while(cin >> a[0] >> a[1] >> a[2] >> a[3]) {
		m = abs(a[0] + a[1] - a[2] - a[3]);
		m = mk(abs(a[0] + a[2] - a[3] - a[1]));
		m = mk(abs(a[0] + a[3] - a[1] - a[2]));
		cout << m << endl;
	}	
	return 0;
}
