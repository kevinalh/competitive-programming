#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

#define MAXN 1005

int main() {
	int i, n, m, j, tmp;
	// n: number of candidates
	// m: number of courses
	cin >> n >> m;
	// v: number of openings of ith course
	// p: score of ith candidate
	// q: number of courses the ith candidate is interested in
	// c: list of courses in order of preference
	int v[MAXN];
	int p[MAXN];
	int q[MAXN];
	vector<int> c[MAXN];
	for(i = 0; i < m; ++i) {
		cin >> v[i];
	}
	priority_queue<pair<int,int> > ind;
	for(i = 0; i < n; ++i) {
		cin >> p[i] >> q[i];
		ind.push(make_pair(p[i], i));
		c[i].reserve(q[i]);
		for(j = 0; j < q[i]; ++j) {
			cin >> tmp;
			c[i].push_back(tmp);
		}
	}
	while(!ind.empty()) {
		// We get the index of the top score
		i << ind.top().second;
		ind.pop();

	}
	return 0;
}
