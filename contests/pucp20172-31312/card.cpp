/*
Codeforces
105A - Card Game
*/

#include <vector>
#include <utility>
#include <iostream>

using namespace std;

int rango(char c);

int main() {
	char suit;
	vector<pair<char, char> > cards;
	cards.resize(2);
	cin >> suit >> cards[0].first >> cards[0].second;
	cin >> cards[1].first >> cards[1].second;
	if((cards[0].second == cards[1].second && rango(cards[0].first) > rango(cards[1].first))
		|| (cards[0].second == suit && cards[1].second != suit)) {
		cout << "YES" << endl;
	} else cout << "NO" << endl;
	return 0;
	
}

int rango(char c) {
	switch(c) {
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
		case 'T':
			return 10;
		case 'J':
			return 11;
		case 'Q':
			return 12;
		case 'K':
			return 13;
		case 'A':
			return 14;
		default:
			return 0;
	}
}