#include <bits/stdc++.h>
#include <cmath>

#define FOR(i, a, b) for(int i=a;i<(b);i++)
#define REP(i, n) FOR(i, 0, n)
#define pb push_back
#define sz(v) v.size()
#define fastio() ios_base::sync_with_stdio(false);cin.tie(0);
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define N 1000001

int primes2[N];
vector<int> primes;

void sieve() {
    ll j;
    REP(i, N) {
        primes2[i] = 1;
    }
    FOR(i, 2, (ll) sqrt(N)) {
        if(primes2[i] == 1) {
            j = i*i;
            while(j < N) {
                primes2[j] = 0;
                j += i;
            }
        }
    }
    FOR(i, 1, N) {
        if(primes2[i] == 1) {
            primes.pb(i);
        }
    }
    return;
}

int main() {
    ull t, a, b, d, pr, prct, mpi, q;
    sieve();
    cin >> t >> a >> b;
    REP(i, t) {
        cin >> d;
        q = 0;
        FOR(j, a, b+1) {
            mpi = 1;
            FOR(k, 2, sz(primes)) {
                if(k == d) continue;
                if(k > j) break;
                pr = 1;
                prct = 0;
                if(primes[k] == 1) {
                    pr = k;
                    while(pr <= i && i % pr == 0) {
                        pr *= pr;
                        prct++;
                    }
                    mpi *= (prct + 1);
                }
            }
            q += mpi;
        }
        cout << q << endl;
    }
    return 0;
}
