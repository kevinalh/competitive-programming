#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int id[103];
int hall[103][103];

int main() {
	int T, i, j, n, m, k, l, c;
	cin >> T;
	for(i = 0; i <= 100; ++i) {
		id[i] = 0;
	}
	while(T--) {
		cin >> n >> m;
		for(i = 0; i < n; ++i) {
			for(j = 0; j < m; ++j) {
				cin >> c;
				hall[i][j] = c;
			}
		}
		for(i = 0; i < n; ++i) {
			for(j = 0; j < m; ++j) {
				c = hall[i][j];
				if(c == -1) continue;
				if(id[c] > 0) continue;
				for(k = -1; k < 2; ++k) {
					for(l = -1; l < 2; ++l) {
						if(k==0 && l==0) continue;
						if(i+k<0||i+k>=n||j+l>=m||j+l<0) continue;
						if(hall[i+k][j+l] == c) {
							id[c] = 1;
							break;
						}
					}
				}
			}
		}
		c = 0;
		for(i = 0; i <= 100; ++i) {
			c += id[i];
			id[i] = 0;
		}
		cout << c << endl;
	}
	return 0;
}