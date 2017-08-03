/*
Codeforces
259B - Little Elephant and Magic Square
*/

#include <vector>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

int main() {
    int matrix[3][3];
    int i, j;
    int sigma = 0;
    /* The sum of all the values given is 2*sigma */
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            cin >> matrix[i][j];
            sigma += matrix[i][j];
        }
    }
    sigma /= 2;
    matrix[0][0] = sigma - matrix[0][1] - matrix[0][2];
    matrix[1][1] = sigma - matrix[1][0] - matrix[1][2];
    matrix[2][2] = sigma - matrix[2][0] - matrix[2][1];
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}