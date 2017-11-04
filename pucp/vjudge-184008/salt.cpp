#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
	long long T, n, x0, i;
	long long a[20], q[20];
	cin >> T;
	while(T--) {
		// n: amount of terms of polynomial
		// x0: quantity of extracted salt
		cin >> n >> x0;
		for(i = 0; i <= n; ++i) {
			cin >> a[i];
		}
		q[n] = a[n];
		for(i = n-1; i >= 0; --i) {
			q[i] = x0 * q[i+1] + a[i];
		}
		cout << q[0] << endl;
		for(i = 1; i <= n; ++i) {
			cout << q[i];
			if(i != n) cout << " ";
		}
		cout << endl;
	}
	return 0;
}
