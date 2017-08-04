#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int t, tmp, i;
    vector<int> a;
    cin >> t;
    for(i = 1; i <= t; ++i) {
        cin >> tmp;
        a.push_back(tmp);
        cin >> tmp;
        a.push_back(tmp);
        cin >> tmp;
        a.push_back(tmp);
        sort(a.begin(), a.end());
        cout << "Case " << i << ": " << a[1] << endl;
        a.clear();
    }
    return 0;
}
