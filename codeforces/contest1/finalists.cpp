#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

#define MAXN 28

int main() {
	long long k;
	vector<long long> r;
	long long i, tmp;
	cin >> k;
	r.reserve(k+1);
	for(i = 0; i < k; ++i) {
		cin >> tmp;
		r.push_back(tmp);
	}
	sort(r.begin(), r.end());
	long long d = 0, flag = 0;
	for(i = 0; i < k; ++i) {
		if(r[i] > 25) {
			if(flag == 0) {
				d = r[i] - 25;
				flag = 1;
			} else {
				d = d + r[i] - r[i-1];	
			}
		}
	}
	if(d <= 0) d = 0;
	cout << d << endl;
	return 0;
}
