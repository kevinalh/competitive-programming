#include <iostream>
#include <vector>

#define N 22002
#define CH 50

using namespace std;

int f1, f2, f3;

typedef vector<int> bigint;

bigint sumbigint(bigint a, bigint b) {
    bigint c;
    c.resize(a.size() + 1);
    unsigned long long it;
    for(it = 0; it < a.size(); ++it) {
        if(a[it] == 0 && b[it] == 0) {
          f1 = f2 = it;
          break;
        }
        c[it] = (c[it] + (a[it] + b[it])) % 10;
        c[it + 1] = (c[it] + a[it] + b[it]) / 10;
    }
    return c;
}

void printbigint(bigint a) {
    int i, flag = 0;
    for(i = a.size() - 1; i >= 0; --i) {
      if(a[i] == 0 && flag == 0) {
        continue;
      }
      else if(a[i] != 0 && flag == 0) {
        flag = 1;
      }
      cout << a[i];
    }
    cout << endl;
}

int main() {
    int i, t, n;
    bigint a1, a2, a3;
    cin >> t;
    while(t--) {
        cin >> n;
        a1.clear();
        a2.clear();
        a3.clear();
        a1.resize(CH);
        a2.resize(CH);
        a3.resize(CH);
        a1[0] = 1;
        a2[0] = 1;
        f1 = f2 = f3 = 1;
        a3 = a1;
        for(i = 2; i <= n; ++i) {
          a3 = sumbigint(a1, a2);
          a1 = a2;
          a2 = a3;
        }
        printbigint(a3);
    }
    return 0;
}
