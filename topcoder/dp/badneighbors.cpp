#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define FOR(i, j, k) for(int (i)=(j); (i)<(k); (i)++)
#define REP(j, k) FOR((j), 0, (k))
#define sqr(x) ((x)*(x))
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) > (y)) ? (y) : (x))
#define endl "\n"
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;

class BadNeighbors {
	public:
		int maxDonations(vector<int>);
};

int review(int l, int k, int n) {
	l = MAX(l, k);
	if(l == (k+1)%n || l == (k-1)%n) l = k;
	return l;
}

int BadNeighbors::maxDonations(vector<int> donations) {
	int n = donations.size();
	int max = *max_element(donations.begin(), donations.end());
	int l1, l2;
	vector<int> lmax(donations);
	REP(k, 3) {
		lmax = donations;
		for(int i = k+2; i < n; ++i) {
			if(i == n-1 && k == 0) continue;
			l1 = review(i-2, k, n);
			l2 = review(i-3, k, n);
			lmax[i] = MAX(lmax[l1], lmax[l2]) + donations[i];
			if(lmax[i] > max) max = lmax[i]; 
		}
	}
	return max;
}

int main() {
	BadNeighbors a;
	int t = 5;
	vector<vector<int>> tests;
	tests.PB({ 10, 3, 2, 5, 7, 8 });
	tests.PB({ 11, 15 });
	tests.PB({ 7, 7, 7, 7, 7, 7, 7 });
	tests.PB({ 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 });
	tests.PB({ 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61, 6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397, 52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 });
	REP(i, t) {
		cout << a.maxDonations(tests[i]) << endl;
	}
}
