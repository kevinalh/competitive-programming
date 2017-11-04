#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
	int i, j, n, k = 0;
	double x, y, x1, y1, x2, y2, x0, y0, x01, y01;
	double xp, yp;
	double d, p, a, total = 0;
	cin >> n;
	cin >> x1 >> y1 >> x >> y;
	x0 = x1;
	y0 = y1;
	x01 = x;
	y01 = y;
	for(i = 2; i <= n+1; ++i) {
		if(i < n) {
			cin >> x2 >> y2;
		}
		else if(i == n) {
			x2 = x0; y2 = y0;
		}
		else {
			x2 = x01; y2 = y01;
		}
		xp = x1 + 2*(x-x1);
		yp = y1 + 2*(y-y1);
		p = (xp-x)*(x2-x)+(yp-y)*(y2-y);
		d = (xp-x)*(y2-y)-(yp-y)*(x2-x);
		a = atan2(d, p);
		total += a;
		if(a < 0) {
			k++;
		}
		x1 = x; y1 = y; x = x2; y = y2;
	}
	if(total < 0) k = n - k;
	cout << k << endl;
	return 0;
}
