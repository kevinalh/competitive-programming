#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <queue>
#include <map>

#define max(a, b) ((a) < (b)) ? (b) : (a)

#define MAXN 20500
long long ways[MAXN];
long long op[22];

using namespace std;

int main() {
	long long m, n, i, j;
	long long tmp = 1;
	i = 0;
	while(tmp < 9261) {
		tmp = (i+1)*(i+1)*(i+1);
		op[i] = tmp;
		i++;
	}
	n = MAXN-10000;
	ways[0] = 1;
	for(i = 1; i <= n; ++i) {
		ways[i] = 0;
	}
	for(j = 0; j < 21; ++j) {
		for(i = 0; i <= n; ++i) {
			ways[i+op[j]] += ways[i];
		}
	}
	while(cin >> n) {
		m = ways[n];
		cout << m << endl;
	}
	return 0;
}