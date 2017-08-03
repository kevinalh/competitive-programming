#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <cstring>

#define ll long long

using namespace std;

int main() {
	ll n, m;
	ll maxteams = 0, res = 0;
	cin >>  n >> m;
	ll maxgroup = m > n ? m : n;
	ll mingroup = m > n ? n : m;
	/* all the possible teams of type a or b */
	maxteams = min(maxgroup / 2, mingroup);
	/* maybe one more team */
	if(maxgroup % 2 != 0 && mingroup - maxgroup/2 > 0 && n+m >= 3) {
		++maxteams;
	}		
	cout << maxteams << endl;
	return 0;
}

4 4
4 3
3 3
2 2
1 2
1 1