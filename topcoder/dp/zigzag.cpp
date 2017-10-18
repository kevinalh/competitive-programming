#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define FOR(i, j, k) for(int (i)=(j); (i)<(k); (i)++)
#define REP(j, k) FOR((j), 0, (k))
#define sqr(x) ((x)*(x))
#define endl "\n"
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;

class ZigZag {
	public:
		int longestZigZag(vector<int>);
};

int ZigZag::longestZigZag(vector<int> sequence){
	int n = sequence.size();
	int max = 1;
	vector<int> ls;
	vector<int> past;
	ls.resize(n);
	past.resize(n);
	REP(i, n) {
		ls[i] = 1;
		past[i] = 0;
		for(int j=i-1; j>=0; --j) {
			if((ls[j] == 1 ||
						((sequence[i]-sequence[j])*(sequence[j]-past[j]) < 0)) &&
					(ls[j]+1 > ls[i])) {
				ls[i] = ls[j] + 1;
				past[i] = sequence[j];
				if(ls[i] > max) max = ls[i];
			}
		}
	}
	return max;
}

int main() {
	ZigZag a;
	vector<vector<int>> tests;
	tests.PB({ 1, 7, 4, 9, 2, 5 });
	tests.PB({44});
	tests.PB({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
	tests.PB({ 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 });
	tests.PB({ 374, 40, 854, 203, 203, 156, 362, 279, 812, 955, 600, 947, 978, 46, 100, 953, 670, 862, 568, 188, 67, 669, 810, 704, 52, 861, 49, 640, 370, 908, 477, 245, 413, 109, 659, 401, 483, 308, 609, 120, 249, 22, 176, 279, 23, 22, 617, 462, 459, 244 });
	REP(i, 5) {
		cout << a.longestZigZag(tests[i]) << endl;
	}
	return 0;
}
