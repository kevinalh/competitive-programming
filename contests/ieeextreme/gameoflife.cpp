#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i=a;i<(b);i++)
#define REP(i, n) FOR(i, 0, n)
#define pb push_back
#define sz(v) v.size()
#define fastio() ios_base::sync_with_stdio(false);cin.tie(0);
#define endl '\n'

#define P 3000

typedef long long ll;
typedef unsigned long long ull;

vector<vector<char> > b;
vector<vector<int> > neig;

vector<vector<vector<char> > > past;
vector<vector<char> > tmp;

vector<vector<vector<char> > >::iterator pit;

int n, m, c;

int modulo(int x, int y) {
  int r = x % y;
  return r < 0 ? r + y : r;
}

void play() {
  REP(i, n) {
    REP(j, m) {
      if(neig[i][j] < 2 || neig[i][j] > 3) b[i][j] = '-';
      else if(neig[i][j] == 3) b[i][j] = '*';
      tmp[i][j] = b[i][j];
    }
  }
  return;
}

int countn(int x, int y) {
  int count = 0;
  FOR(i, -1, 2) {
    FOR(j, -1, 2) {
      if(i == 0 && j == 0) continue;
      if(b[modulo(x+i, n)][modulo(y+j, m)] == '*') {
        count++;
      }
    }
  }
  return count;
}

void refreshn() {
  REP(i, n) {
    REP(j, m) {
      neig[i][j] = countn(i, j);
    }
  }
  return;
}

void printboard() {
  REP(i, n) {
    REP(j, m) {
      cout << b[i][j];
    }
    cout << endl;
  }
  return;
}

int checkperiodicity(int k) {
  REP(i, n) {
    REP(j, m) {
      if(b[i][j] != past[k][i][j]) return -1;
    }
  }
  return k;
}

int main() {
  int period, it;
  cin >> n >> m >> c;
  tmp.resize(n+1);
  b.resize(n+1);
  neig.resize(n+1);
  past.reserve(P+1);
  REP(i, n) {
    tmp[i].resize(m+1);
    b[i].resize(m+1);
    neig[i].resize(m+1);
    REP(j, m) {
      cin >> b[i][j];
    }
  }
  for(it = 0; it < c; ++it) {
    refreshn();
    play();

    if(it <= P + 1) {
      past.push_back(tmp);
    } else {
      REP(k, P) {
        period = checkperiodicity(k);
        if(period != -1) break;
      }
      if(period != -1) {
        break;
      }
      else {
        past.push_back(tmp);
        past.erase(past.begin());
      }
    }

  }
  if(c > P && period != -1) {
    b = past[((c - it) % (P - period)) + period];
  }
  printboard();
  return 0;
}
