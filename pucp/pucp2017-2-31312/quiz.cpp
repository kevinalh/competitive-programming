/*
Codeforces
120B - Quiz League
*/

#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <cstdio>
#include <bitset>

using namespace std;

#define MAXN 1001

int main() {
    int i, n, k, tmp;
    bitset<MAXN> spin;
    freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for(i = 0; i < n; i++) {
        cin >> tmp;
        spin.set(i, tmp);
    }
    freopen("output.txt", "w", stdout);
    i = k-1;
    do {
        if(spin[i]) break;
        i = (i+1)%n;
    } while(i != (k-1));
    cout << (int) i + 1 << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}