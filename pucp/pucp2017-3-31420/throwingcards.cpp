#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <sstream>
#include <queue>

using namespace std;

int main() {
    int i, n;
    while(cin >> n && n != 0) {
        queue<int> q;
        for(i = 1; i <= n; ++i) {
            q.push(i);
        }
        cout << "Discarded cards:";
        while(q.size() >= 2) {
            if(q.size() != n) cout << ",";
            cout << " " << q.front();
            q.pop(); 
            q.push(q.front());
            q.pop();
        }
        cout << endl << "Remaining card: " << q.front() << endl;
    }
    return 0;
}