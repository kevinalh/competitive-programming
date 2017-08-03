#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <queue>
#include <map>

#define max(a, b) ((a) < (b)) ? (b) : (a)

#define MAXN 10500

using namespace std;

int main() {
	long long n, i, j, a, bet, maxbet;
	while(1) {
		cin >> n;
		bet = 0;
		maxbet = 0;
		if(n == 0) break;
		for(i = 0; i < n; ++i) {
			cin >> a;
			bet += a;
			if(bet > maxbet) maxbet = bet;
			if(bet < 0) bet = 0;
		}
		if(maxbet > 0) {
			cout << "The maximum winning streak is " << maxbet << "." << endl;
		}
		else {
			cout << "Losing streak." << endl;
		}
	}
	return 0;
}