#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>

using namespace std;

int main() {
    string tmp;
    int n, i, a, b, sum;
    int jolly[3001];
    while(1) {
        getline(cin, tmp);
        sum = 0;
        if(tmp.size() == 0) break;
        istringstream s(tmp);
        s >> n;
        s >> a;
        memset(jolly, 0, 3001*sizeof(int));
        for(i = 1; i < n; ++i) {
            s >> b;
            jolly[abs(a-b)] = 1;
            a = b;      
        }
        for(i = 1; i < n; ++i) {
            sum += jolly[i];
        }
        if(sum == n-1) {
            cout << "Jolly" << endl;
        } else {
            cout << "Not jolly" << endl;
        }
    }
    return 0;
}