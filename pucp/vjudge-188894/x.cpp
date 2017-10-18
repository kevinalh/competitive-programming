#include <vector>
#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int main() {
	unsigned long long s, as, bs;
	bitset<54> a, b;
	while(cin >> as >> bs) {
		a = as;
		b = bs;
		s = 0;
		while(a != b) {
			s += a.count();
			cout << a.count();
			a = a.to_ulong() + 1;
		}
		cout << " " << s << endl;
	}
	return 0;
}
