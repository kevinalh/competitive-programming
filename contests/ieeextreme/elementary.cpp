#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i=a;i<(b);i++)
#define REP(i, n) FOR(i, 0, n)
#define pb push_back
#define sz(v) v.size()
#define fastio() ios_base::sync_with_stdio(false);cin.tie(0);
#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;

int main() {
    vector<string> p;
    string tmp;
    ll n;
    cin >> n;
    p.reserve(n+1);
    REP(i, n+1) {
      getline(cin, tmp);
      p.pb(tmp);
    }
    REP(i, n+1){
      cout << p[i] << "\t";
      REP(j, p[i].length()) {
        cout << (int) p[i][j] - 'a' << " ";
      }
      cout << endl;
    }
    return 0;
}
