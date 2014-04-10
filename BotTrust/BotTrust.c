#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	int t;
	scanf("%d", &t);
	int k;
	for (k = 1; k <= t; k++) {
		int n;
		scanf("%d", &n);
		char *r = (char *)malloc(sizeof(char) * n);
		int *p = (int *)malloc(sizeof(int) * n);
		int i;
		for (i = 0; i < n; i++)
			scanf(" %c %d", &r[i], &p[i]);
		int opos = 1, bpos = 1;
		int ostep = 0, bstep = 0;
		int counter = 0;
		if (r[0] == 'B') {
			bstep = p[0];
			counter += bstep;
			bpos = p[0];
		} else {
			ostep = p[0];
			counter += ostep;
			opos = p[0];
		}
		for (i = 1; i < n; i++) {
			if (r[i] == 'B') {
				if (r[i - 1] == 'O') {
					if (abs(p[i] - bpos) <= ostep) {
						bstep = 1;
						counter += 1;
						ostep  = 0;
						bpos = p[i];
					} else {
						bstep = abs(p[i] - bpos) - ostep + 1;
						ostep = 0;
						bpos = p[i];
						counter += bstep;
					}
				} else {
					bstep += abs(p[i] - bpos) + 1;
					counter += abs(p[i] - bpos) + 1;
					bpos = p[i];
				}
			} else {
				if (r[i - 1] == 'B') {
					if (abs(p[i] - opos) <= bstep) {
						ostep = 1;
						counter += 1;
						bstep  = 0;
						opos = p[i];
					} else {
						ostep = abs(p[i] - opos) - bstep + 1;
						bstep = 0;
						opos = p[i];
						counter += ostep;
					}
				} else {
					ostep += abs( p[i] - opos ) + 1;
					counter += abs(p[i] - opos) + 1;
					opos = p[i];
				}
			}
		}

		printf("Case #%d: %d\n", k, counter);
	}
	return 0;
}
