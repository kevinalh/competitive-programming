#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <queue>
#include <map>

#define max(a, b) ((a) < (b)) ? (b) : (a)

using namespace std;

#define MAXN 3005

int n, m;
long long t[MAXN][MAXN];

int main() {
	cin >> n >> m;
	char aux;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> aux;
			if(aux == '.') {
				t[i][j] = 1;
			} else {
				t[i][j] = 0;
			}
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			
		}
	}
	return 0;
}