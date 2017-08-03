#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

int p[101][101];
int voting[101];

int main() {
	int i, j, t, c, v, top, mostvoted, maxvotes, scd, w;
	cin >> t;
	while(t--) {
		cin >> c >> v;
		for(i = 0; i < 101; ++i) {
			voting[i] = 0;
		}
		maxvotes = 0;
		scd = -1;
		mostvoted = -1;
		for(i = 0; i < v; ++i) {
			cin >> top;
			top--;
			p[i][0] = top;
			voting[top]++;
			if(voting[top] > maxvotes) {
				maxvotes = voting[top];
				mostvoted = top;
			}
			for(j = 1; j < c; ++j) {
				cin >> top;
				top--;
				p[i][j] = top;
			}
		}
		if(2*maxvotes > v) {
			cout << mostvoted + 1 << " 1" << endl;
		} else {
			maxvotes = 0;
			for(i = 0; i < c; ++i) {
				if(i == mostvoted) continue;
				if(voting[i] > maxvotes) {
					maxvotes = voting[i];
					scd = i;
				}
			}
			/* scd is the number of the second most voted candidate */
			voting[mostvoted] = 0;
			voting[scd] = 0;
			for(i = 0; i < v; ++i) {
				for(j = 0; j < c; ++j) {
					if(p[i][j] == mostvoted) {
						voting[mostvoted]++;
						break;
					}
					else if(p[i][j] == scd) {
						voting[scd]++;
						break;
					}
				}
			}
			w = voting[mostvoted] > voting[scd] ? mostvoted : scd;
			cout << w + 1 << " 2" << endl;
		}
	}
	return 0;
}