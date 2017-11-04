#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main() {
	int T;
	int x1, x2, y1, y2, r1, r2;
	double dc, d;
	cin >> T;
	while(T--) {
		cin >> r1 >> x1 >> y1 >> r2 >> x2 >> y2;
		dc = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
		if(dc + (double) r2 <= (double) r1) {
			cout << "Rich";
		}
		else {
			cout << "Dead";
		}
		cout << endl;
	}
	return 0;
}
