/*
Codeforces
236B - Easy Number Challenge
> Incomplete
*/

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

#define MAXPRODUCT 1000001

map<long long, long long> factor;
bool numeros[MAXPRODUCT];

long long sumadiv() {
    int producto = 1;
    map<long long, long long>::iterator it;
    for(it = factor.begin(); it != factor.end(); ++it) {
        producto *= it->second + 1;
    }
    return producto;
}

void agregar(long long n) {
    ++factor[n];
}

void criba(long long n) {
    long long i, j;
    while(n % 2 == 0) {
        agregar(2);
        n /= 2;
    }
    for(i = 3; i <= (long long) sqrt(n); i += 2) {
        while(n % i == 0) {
            agregar(i);
            n /= i;
        }
    }
    if(n > 2) agregar(n);
    return;
}

void primos() {
    long long i, j;
    for(i = 2; i <= (long long) sqrt(MAXPRODUCT); ++i) {
        if(numeros[i]) {
            for(j = i*i; j <= MAXPRODUCT; j += i) {
                numeros[j] = false;
            }
        }
    }
}

void llenardeceros() {
    long long i;
    for(i = 0; i <= MAXPRODUCT; ++i) {
        if(numeros[i]) factor[i] = 0;
    }
}

int main() {
    long long a, b, c, i, j, k;
    cin >> a >> b >> c;
    long long modulo = 1073741824;
    long long suma = 0;
    memset(numeros, true, MAXPRODUCT*sizeof(bool));
    primos();
    for(i = 1; i <= a; i++) {
        for(j = 1; j <= b; j++) {
            for(k = 1; k <= c; k++) {
                llenardeceros();
                criba(i*j*k);
                suma += sumadiv();
                suma %= modulo;
            }
        }
    }
    cout << suma << endl;
    return 0;
}