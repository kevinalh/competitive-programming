#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <set>

using namespace std;

#define MAXN 200005

typedef struct gr {
    vector<long long> edges;
    long long n;
    int fue;
} gr;

long long c, p, x, l;
gr ct[MAXN];
queue<long long> q;
set<long long> cj;

int main() {
    long long a, b, i, k, l, j, cont, bnd, bnd2;
    cin >> c >> p >> x >> l;
    for(i = 0; i < MAXN; ++i) {
        ct[i].n = 0;
        ct[i].fue = 0;
    }
    while(p--) {
        cin >> a >> b;
        ct[a-1].edges.push_back(b-1);
        ct[a-1].n++;
        ct[b-1].edges.push_back(a-1);
        ct[b-1].n++;
    }
    for(cont = 0; cont < 5; ++cont) {
        cj.insert(l-1);
        q.push(l-1);
        while(!q.empty()) {
            i = q.front();
            q.pop();
            bnd = 0;
            if((double) ct[i].n <=  (double) ct[i].edges.size() / 2 || i == l-1) {
                if(ct[i].fue == 0) {
                    ct[i].fue = 1;
                    bnd = 1;
                } 
                for(k = 0; k < ct[i].edges.size(); ++k) {
                    j = ct[i].edges[k];
                    if(bnd) ct[j].n--;
                    if(cj.find(j) == cj.end()) {
                        cj.insert(j);
                        q.push(j);
                    }
                }
            }
        }
        cj.clear();
    }
    if(ct[x-1].fue == 1) {
        cout << "leave" << endl;
    }
    else {
        cout << "stay" << endl;
    }
    return 0;
}
