#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
	int i, j, n, k;
	int h, m;
	vector<pair<int,int> > ti, tf;
	cin >> n;
	ti.reserve(n+1);
	tf.reserve(n+1);
	for(i = 0; i < n; ++i) {
		scanf("%d:%d", &h, &m);
		ti.push_back(make_pair(h*60+m, i));
		scanf("%d:%d", &h, &m);
		tf.push_back(make_pair(h*60+m, i));
	}
	sort(tf.begin(), tf.end());
	cout << tf[0].second + 1;
	for(i = 0; i < n-1; ++i) {
		k = i;
		while(k < n-1) {
			j = tf[k+1].second;
			if(ti[j].first >= tf[i].first) {
				cout << " " << ti[j].second + 1;
				break;
			}
			k++;
		}
		i = k;
	}
	cout << endl;
	return 0;
}
