#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <queue>

using namespace std;

int main() {
	int t, ts, e, elements, cas = 0;
	queue<long long> colas[1002];
	queue<long long> colateams;
	set<long long> setteams;
	map<long long, int> teams;
	long long tmp, tmpteam;
	string command;
	while (cin >> ts) {
		if (ts == 0) break;
		++cas;
		teams.clear();
		setteams.clear();
		for (t = 0; t < ts; ++t) {
			colas[t] = queue<long long>();
			cin >> elements;
			for (e = 0; e < elements; ++e) {
				cin >> tmp;
				teams[tmp] = t;
			}
		}
		colateams = queue<long long>();
		cout << "Scenario #" << cas << endl;
		while (cin >> command) {
			if (command.compare("STOP") == 0) break;
			if (command.compare("ENQUEUE") == 0) {
				cin >> tmp;
				tmpteam = teams[tmp];
				colas[tmpteam].push(tmp);
				if (setteams.count(tmpteam) == 0) {
					colateams.push(tmpteam);
					setteams.insert(tmpteam);
				}
			}
			else if (command.compare("DEQUEUE") == 0) {
				tmpteam = colateams.front();
				tmp = colas[tmpteam].front();
				colas[tmpteam].pop();
				if (colas[tmpteam].empty()) {
					colateams.pop();
					setteams.erase(tmpteam);
				}
				cout << tmp << endl;
			}
		}
		cout << endl;
	}
	return 0;
}