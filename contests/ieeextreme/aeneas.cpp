#include <iostream>
#include <cctype>
#include <string>
#include <cmath>

using namespace std;

#define N 'Z'+ 1
#define PI 3.14159265358979323846

double alph[N];
double dis[N][N];

int main() {
    unsigned int i, j, r;
    double d;
    string s;
    cin >> r;
    for(i = 'A'; i <= 'Z'; ++i) {
        getchar();
        getchar();
        cin >> alph[i];
        alph[i] *= PI/180.0;
    }
    for(i = 'A'; i <= 'Z'; ++i) {
      for(j = 'A'; j <= 'Z'; ++j) {
        dis[i][j] = i == j ? 0 :
        sqrt(pow(cos(alph[i]) - cos(alph[j]), 2) +
        pow(sin(alph[i]) - sin(alph[j]), 2));
      }
    }
    d = 0;
    getchar();
    /*
    getline(cin, s);
    for(string::iterator it = s.begin(); it != s.end(); ++it) {
        if(!isalpha(*it)) it = s.erase(it);
        if(it == s.end()) break;
        else *it = toupper(*it);
    }
    */
    s.reserve(1000005);
    char c = '\n';
    char c2 = toupper(getchar());
    while(c2 != '\n' && c2 != '\0') {
      if(isalpha(c2) && c != c2) {
          s.push_back(c2);
      }
      c = c2;
      c2 = toupper(getchar());
    }
    for(i = 1; i < s.length(); ++i) {
        d += dis[s[i]][s[i-1]];
    }
    d *= (double) r;
    d += r;
    cout << (long long) (d + 1) << endl;
    return 0;
}
