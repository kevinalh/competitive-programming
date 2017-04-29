#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <sstream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	set<string> words;
	set<string>::iterator it;
	string::iterator i, j;
	string line;
	while (getline(cin, line)) {
		i = line.begin();
		while (i != line.end()) {
			j = i;
			while (j != line.end()) {
				if (!isalpha(*j)) break;
				++j;
			}
			if (i != j) {
				string word(i, j);
				transform(word.begin(), word.end(), word.begin(), ::tolower);
				words.insert(word);
			}
			if (j == line.end()) break;
			i = j+1;
		}
	}
	for (it = words.begin(); it != words.end(); ++it) {
		cout << *it << endl;
	}
    return 0;
}
