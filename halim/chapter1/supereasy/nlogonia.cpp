#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int k, i, n, m, x, y;
    while (1) {
        cin >> k;
        if (k == 0) break;
        cin >> n >> m;
        for (i = 0; i < k; ++i) {
            cin >> x >> y;
            if (x == n || y == m) {
                cout << "divisa";
            }
            else {
                if (y > m) cout << "N";
                if (y < m) cout << "S";
                if (x > n) cout << "E";
                if (x < n) cout << "O";
            }
            cout << endl;
        }
    }
    return 0;
}
