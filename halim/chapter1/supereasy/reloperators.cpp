/*
UVa
11172 - Relational Operators
*/

#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

int main() {
    int t, a, b;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        if(a < b) cout << "<";
        else if(a > b) cout << ">";
        else cout << "=";
        cout << endl;
    }
	return 0;
}
