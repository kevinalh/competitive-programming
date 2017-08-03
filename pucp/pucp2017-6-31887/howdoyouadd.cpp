#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <queue>
#include <map>

#define max(a, b) ((a) < (b)) ? (b) : (a)

using namespace std;

int main() {
	long long ways, i, n, k, j, oways;
	while(1) {
		cin >> n >> k;
		if(n == k && k == 0) break;
		ways = 1;
		k--;
		/*
		for(i = k+1; i <= n; ++i) {
			ways = (ways*i)%1000000;
			ways = (ways/(i-k))%1000000;
		}
		*/
		for(i = n; i > n-k; --i) {
			oways = ways%1000000;
			for(j = 0; j < i; ++j) {
				ways = (ways+oways)%1000000;
			}
		}
		cout << ways << endl;
	}
	return 0;
}