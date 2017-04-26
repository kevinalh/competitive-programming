/*
Codeforces
3A - Shortest path of the king
*/

#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;

pair<int, int> s, t;

void movement(int x, int y) {
    if(x==-1 && y==0) cout << "L" << endl;
    if(x==1 && y==0) cout << "R" << endl;
    if(x==0 && y==-1) cout << "D" << endl;
    if(x==0 && y==1) cout << "U" << endl;
    if(x==-1 && y==-1) cout << "LD" << endl;
    if(x==-1 && y==1) cout << "LU" << endl;
    if(x==1 && y==-1) cout << "RD" << endl;
    if(x==1 && y==1) cout << "RU" << endl;
    return;
}

int main() {
    /* first: fila */
    /* second: columna */
    char a;
    int b, i, j, dist, minimum, x, y;
    cin >> a >> b;
    s.first = 8 - b;
    s.second = a - 'a';
    cin >> a >> b;
    t.first = 8 - b;
    t.second = a - 'a';
    pair<int, int> pos(s);
    pair<int, int> mv;
    vector<pair<int, int>> movimientos;
    while(pos != t) {
        minimum = numeric_limits<int>::max();
        x = 0;
        y = 0;
        for(i = -1; i < 2; i++) {
            for(j = -1; j < 2; j++) {
                if(i == 0 && j == 0) continue;
                if(pos.first+i>=0 && pos.second+j>=0 && pos.first+i<8 && pos.second+j<8) {
                    dist = abs(pos.first+i-t.first) + abs(pos.second+j-t.second);
                    if(dist < minimum) {
                        minimum = dist;
                        x = i;
                        y = j;
                    }
                }
            }
        }
        mv.first = x;
        mv.second = y;
        pos.first += x;
        pos.second += y;
        movimientos.push_back(mv);
    }
    int tam = movimientos.size();
    cout << tam << endl;
    for(i = 0; i < tam; i++) {
        movement(movimientos[i].second, -movimientos[i].first);
    }
    return 0;
}