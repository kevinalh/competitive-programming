/*
Codeforces
80B - Depression
*/

#include <vector>
#include <map>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int horas, minutos; // Digital clock
    cin >> horas;
    cin.ignore();
    cin >> minutos;
    int i;
    horas %= 12; // In this format?
    if(horas == 0 && minutos == 0) {
        cout << "0 0" << endl;
        return 0;
    }
    double h = (double) horas;
    double m = (double) minutos;
    double hgrados = (h + (m/60))*30;
    double mgrados = m*6;
    cout << hgrados << " " << mgrados << endl;
    return 0;
}