/*
ACM ICPC 2009–2010, NEERC, Northern Subregional Contest
Problem K. Kripke Model
*/
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
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define MAXN 10005

int n, m, k;
int a, b;
bool s[MAXN][28]; // States
vector<vi> g;

void read_graph() {
	cin >> n >> m >> k;
	int c, s1, t1;
	char l, a1, b1;
	g.resize(n);
	REP(i, n) {
		cin >> c;
		REP(j, c) {
			cin >> l;
			s[i][(int)l-'a'] = true;
		}
		// g[i].PB(i);
	}
	REP(i, m) {
		cin >> s1 >> t1;
		g[s1-1].PB(t1-1);
	}
	scanf(" E(%cU(AG%c))", &a1, &b1);
	a = a1 - 'a';
	b = b1 - 'a';
	return;
}

int main() {
	read_graph();
	cout << a << " " << b << endl;
	return 0;
}
