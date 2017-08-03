#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

#define NMAX 1000010

int main() {
	int T;
	int x, y, i, j, len;
	char s[NMAX], op, ins[NMAX];
	char* tmp;
	scanf("%d", &T);
	while(T--) {
		scanf("%s", s);
		len = strlen(s);
		while(scanf("%c", &op) == 1) {
			if(op == 'E') {
				getchar(); // N
				getchar(); // D
				//getchar(); // \n
				break;
			}			
			else if(op == 'I') {
				scanf("%s %d", ins, &x);
				tmp = &s[x];
				strcat(ins, tmp);
				s[x] = '\0';
				strcat(s, ins);
			}
			else if(op == 'P') {
				scanf("%d %d", &x, &y);
				for(i = x; i <= y; ++i) {
					printf("%c", s[i]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}