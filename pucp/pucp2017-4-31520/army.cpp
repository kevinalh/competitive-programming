#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <cstring>

#define ll long long
#define MAXN 103

using namespace std;

int main() {
	int tmp = 0, n, a, b, i;
	int d[MAXN];
	d[0] = 0;
	cin >> n;
	for(i = 1; i <= n-1; ++i) {
		cin >> tmp;
		d[i] = tmp + d[i-1];
	}
	/* d[i] = years from rank 1 to rank i */
	cin >> a >> b;
	cout << (d[b-1] - d[a-1]) << endl;
	return 0;
}
