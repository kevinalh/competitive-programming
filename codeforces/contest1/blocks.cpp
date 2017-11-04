#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	long long n, s, d, t;
	cin >> n;
	s = (long long) sqrt(n);
	d = (long long) n - (s*s);
	d = (long long) ceil((double) d / (double) s);
	t = 4*s + 2*d;
	cout << t << endl;
	return 0;
}
