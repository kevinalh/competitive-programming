/*
Codeforces
14C - Four Segments
*/

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int main() {
    long long rect[4][4];
    /*
    x1 = rect[i][0]
    x2 = rect[i][2]
    y1 = rect[i][1]
    y2 = rect[i][3]
    */
    int i, j, count, x, y;
    multiset<pair<long long, long long>> ver;
    set<pair<long long, long long>> versr;
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++) {
            cin >> rect[i][j];
        }
        // All the segments are required to be parallel to coordinate axes
        if(rect[i][0] != rect[i][2] && rect[i][1] != rect[i][3]) {
            cout << "NO" << endl;
            return 0;
        }
        // We save the endpoints of each segment
        ver.insert(make_pair(rect[i][0], rect[i][1]));
        ver.insert(make_pair(rect[i][2], rect[i][3]));
        versr.insert(make_pair(rect[i][0], rect[i][1]));
        versr.insert(make_pair(rect[i][2], rect[i][3]));
    }
    set<pair<long long, long long>>::iterator it;
    for(it = versr.begin(); it != versr.end(); ++it) {
        count = ver.count(*it);
        if(count != 2) {
            cout << "NO" << endl;
            return 0;
        }
    }
    multiset<pair<long long, long long>>::iterator it2, it3;
    int count1;
    // There are exactly 4 points connected by the segments.
    // Now check that no more than 2 are collinear.
    for(it2 = versr.begin(); it2 != versr.end(); ++it2) {
        count = 0;
        count1 = 0;
        x = it2->first;
        y = it2->second;
        for(it3 = versr.begin(); it3 != versr.end(); ++it3) {
            if(it3 == it2) continue;
            if(it3->first == x) ++count;
            if(it3->second == y) ++count1;
        }
        if(count!=1 || count1!=1) {
            cout << "NO" << endl;
            return 0;
        }
    }
    // Finally check that the segments enclose a region of positive area
    x = 0; y = 0;
    for(i = 0; i < 4; i++) {
        y += abs(rect[i][1] - rect[i][3]);
        x += abs(rect[i][0] - rect[i][2]);
    }
    if(x*y == 0) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}