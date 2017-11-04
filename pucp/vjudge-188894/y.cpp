#include <vector>
#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>

/* Y - Football */

using namespace std;

int main() {
	long long i, n, g, s, r, points;
	vector<long long> m;
	vector<long long>::reverse_iterator it;
	m.reserve(100005);
	while(cin >> n >> g) {
		m.clear();
		points = 0;
		for(i = 0; i < n; ++i) {
			cin >> s >> r;
			if(s-r > 0) points += 3;
			if(s-r == 0) points += 1;
			if(s-r <= 0) m.push_back(s-r);
		}
		sort(m.begin(), m.end());
		for(it = m.rbegin(); it != m.rend(); ++it) {
			if(g <= 0) break;
			if(*it == 0) {
				g--;
				points += 2;
			}
			else if(g >= -*it) {
					g += *it;
					points += 1;
					if(g > 0) {
						g--;
						points += 2;
					}
			}
		}
		cout << points << endl;
	}
	return 0;
}
