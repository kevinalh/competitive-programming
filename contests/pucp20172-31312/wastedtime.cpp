/*
Codeforces
127A - Wasted Time
*/

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int i, n, k;
    int a, b, x, y;
    double dist = 0;
    double time;
    cin >> n >> k;
    cin >> a >> b;
    for(i = 1; i < n; i++) {
        cin >> x >> y;
        dist += (double) sqrt((x-a)*(x-a) + (y-b)*(y-b));
        a = x;
        b = y;
    }
    time = (dist / 50) * k;
    cout << setprecision(9) << fixed << time << endl;
}