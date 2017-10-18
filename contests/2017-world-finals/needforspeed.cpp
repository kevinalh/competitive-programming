#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <limits>
#include <cmath>
#include <algorithm>

using namespace std;

vector<pair<double, double>> v;

int n;
double t;

double f(double x) {
    int i;
    double res = 0;
    for(i = 0; i < n; ++i) {
        res += v[i].first / (v[i].second + x);
    }
    res -= t;
    return res;
}

double der(double x) {
    int i;
    double res = 0;
    for(i = 0; i < n; ++i) {
        res -= v[i].first / ((v[i].second + x)*(v[i].second + x));
    }
    return res;
}

double newton(double g) {
    int i;
    double x = g;
    double grad = 0;
    int flag = 0;
    for(i = 0; i < 10000; ++i) {
        grad = der(x);
        if(abs(grad) <= 0.01) break;
        x = x - f(x)/der(x);
        if(f(x) <= 0.000001) {
            flag = 1;
            break;
        }
    }
    if(flag == 0) x = numeric_limits<double>::quiet_NaN();
    return x;
}

bool comp(pair<double, double> a, pair<double, double> b) {
    return a.second < b.second;
}

int main() {
    double tmp, tmp2;
    cin >> n >> t;
    v.reserve(n+1);
    int i, ds = 0;
    for(i = 0; i < n; ++i) {
        cin >> tmp >> tmp2;
        v.push_back(make_pair(tmp, tmp2));
        ds += tmp;
    }
    double x;
    int flag = 0;
    sort(v.begin(), v.end(), comp);
    double smin = v[0].second;
    x = newton(v[n-1].second+1);
    if(!isnan(x) && -x <= smin) flag = 1;
    if(flag == 0) {
        x = newton(v[0].second-1);
        if(!isnan(x) && -x <= smin) flag = 1;
    }
    if(flag == 0) {
        for(i = n-1; i >= 0; --i) {
            x = newton(-(v[i].second + v[i+1].second)/2);
            if(!isnan(x) && -x <= smin) {
                flag = 1;
                break;
            };
        }
    }
    cout << x << endl;;
    return 0;
}
