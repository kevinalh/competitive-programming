#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <limits>
#include <queue>
#include <functional>

using namespace std;

int intmax = numeric_limits<int>::max();
typedef pair<int, int> npair;

int n, m;
int graph[105][105];
npair dst[105];

npair sumpairs(npair a, npair b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

int totalcost() {
    int cost = 0;
    int i, j;
    for(i = 1; i <= n; ++i) {
        if(dst[i].second == intmax) {
            cost = -1;
            break;
        }
        cost += dst[i].second;
    }
    return cost;
}

int dijkstra() {
    /* npair consists of (dist, mincost), so the total pair would be
    ((dist, mincost), language) */
    int i, j, curr;
    dst[0] = make_pair(0, 0);
    for(i = 1; i <= n; ++i) {
        dst[i] = make_pair(intmax, intmax);
    }
    priority_queue<pair<npair, int>, vector<pair<npair, int>>, greater<pair<npair, int>>> pq;
    pq.push(make_pair(make_pair(0,0), 0));
    while(!pq.empty()) {
        curr = pq.top().second;
        pq.pop();
        for(i = 0; i <= n; ++i) {
            if(graph[i][curr] < intmax && dst[i] > sumpairs(dst[curr], make_pair(1, graph[i][curr]))) {
                dst[i] = sumpairs(dst[curr], make_pair(1, graph[i][curr]));
                pq.push(make_pair(dst[i], i));
            }
        }
    }
    return totalcost();
}

int main() {
    /* n languages
    m translators */
    cin >> n >> m;
    map<string, int> lgs;
    int i, j, cost;
    string tmp1, tmp2;
    lgs["English"] = 0;
    for(j = 0; j <= n; ++j) {
        graph[0][j] = intmax;
    }
    for(i = 1; i <= n; ++i) {
        cin >> tmp1;
        lgs[tmp1] = i;
        for(j = 0; j <= n; ++j) {
            graph[i][j] = intmax;
        }
    }
    for(i = 0; i < m; ++i) {
        cin >> tmp1 >> tmp2 >> cost;
        graph[lgs[tmp1]][lgs[tmp2]] = cost;
        graph[lgs[tmp2]][lgs[tmp1]] = cost;
    }
    cost = dijkstra();
    if(cost == -1) {
        cout << "Impossible";
    } else {
        cout << cost;
    }
    cout << endl;
    return 0;
}