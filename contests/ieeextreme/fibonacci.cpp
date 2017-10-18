#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

void exponent(ull);
void squarematrix();

int a[2][2];

void squarematrix() {
  int i, j;
  a[0][0] = (a[0][0]*a[0][0] + a[0][1]*a[1][0]);
  a[0][1] = (a[0][0]*a[0][1] + a[0][1]*a[1][1]);
  a[1][0] = (a[1][0]*a[0][0] + a[1][1]*a[1][0]);
  a[1][1] = (a[1][0]*a[0][1] + a[1][1]*a[1][1]);
  return;
}

void exponent(ull n) {
  int b[2][2];
  if(n == 0) {
    a[0][0] = 1;
    a[1][1] = 1;
    a[0][1] = 0;
    a[1][0] = 0;
    return;
  }
  else if(n == 1) return;
  if(n % 2 == 0) {
    squarematrix();
    exponent(n/2);
  }
  else {
    b[0][0] = a[0][0];
    b[0][1] = a[0][1];
    b[1][0] = a[1][0];
    b[1][1] = a[1][1];
    squarematrix();
    exponent((n-1)/2);
    a[0][0] = (b[0][0]*a[0][0] + b[0][1]*a[1][0]);
    a[0][1] = (b[0][0]*a[0][1] + b[0][1]*a[1][1]);
    a[1][0] = (b[1][0]*a[0][0] + b[1][1]*a[1][0]);
    a[1][1] = (b[1][0]*a[0][1] + b[1][1]*a[1][1]);
  }
  return;
}

int main() {
  int t;
  ull m;
  cin >> t;
  while (t--) {
    cin >> m;
    a[0][0] = 1;
    a[1][0] = 1;
    a[0][1] = 1;
    a[1][1] = 0;
    exponent(m);
    cout << a[1][1] << endl;
  }
  return 0;
}
