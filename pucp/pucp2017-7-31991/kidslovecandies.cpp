#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int T, N, K, i, candy, kids;
	// vector<int> candies;
	cin >> T;
	while(T--) {
		// vector.clear();
		cin >> N >> K;
		// vector.reserve(N+1);
		kids = 0;
		for(i = 0; i < N; ++i) {
			cin >> candy;
			kids += candy/K;
			// vector.push(candy);
		}
		cout << kids << endl;
	}
	return 0;
}