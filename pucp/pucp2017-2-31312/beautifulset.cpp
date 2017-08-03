/*
Codeforces
268C - Beautiful Set of Points
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
	int n, m, y, i;
	vector<pair<int, int> > num;
	cin >> n >> m;
	for(y = m; y >= 0; --y) {
		if(m - y > n) break;
		num.push_back(make_pair(m - y, y));
	}
	int tam = num.size();
	cout << tam << endl;
	for(i = 0; i < tam; ++i) {
		cout << num[i].first << " " << num[i].second << endl;
	}
	return 0;
}