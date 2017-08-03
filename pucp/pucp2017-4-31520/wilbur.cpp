#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <cstring>

#define ll long long
#define NMAX 200000

using namespace std;

int main() {
	ll i, j, n, tmp, tmp2;
	ll steps = 0;
	cin >> n;
	tmp2 = 0;
	for(i = 0; i < n; ++i) {
		cin >> tmp;
		steps += abs(tmp2 - tmp);
		tmp2 += tmp - tmp2;
	}
	cout << steps;
	return 0;
}