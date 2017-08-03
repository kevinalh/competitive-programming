#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <queue>
#include <map>

#define max(a, b) ((a) < (b)) ? (b) : (a)

#define MAXN 30200
long long ways[MAXN];

using namespace std;

int main() {
	long long op[6] = {50, 25, 10, 5, 1};
	long long m, n, i, j;
	long long tmp;
	n = MAXN-150;
	ways[0] = 1;
	for(i = 1; i <= n; ++i) {
		ways[i] = 0;
	}
	for(j = 0; j < 5; ++j) {
		for(i = 0; i <= n; ++i) {
			ways[i+op[j]] += ways[i];
		}
	}
	while(cin >> n) {
		m = ways[n];
		if(m == 1) {
			cout << "There is only 1 way ";
		}
		else {
			cout << "There are " << m << " ways ";
		}
		cout << "to produce " << n << " cents change." << endl;
	}
	return 0;
}