#include <iostream>
#include <vector>
#include <string>
#include <map>

#define MAXN 21

using namespace std;

int n;
int x[MAXN], y[MAXN], z[MAXN], r[MAXN], v[MAXN];

int main() {
    cin >> n;
    int i;
    for(i = 0; i < n; ++i) {
        /* x, y, z coordinates of center,
        r radius,
        v volume in ml */
        cin >> x[i] >> y[i] >> z[i] >> r[i] >> v[i];
    }
    /* Top glass is filled at 100 ml/s */
    return 0;
}