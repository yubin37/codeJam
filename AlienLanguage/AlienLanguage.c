#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main(void)
{
	int l, d, n;
	scanf("%d %d %d", &l, &d, &n);
	char **p = (char**)malloc(sizeof(char *) * d);
	int i, j;
	for (i = 0; i < d; i++) 
		p[i] = (char*)malloc(sizeof(char) * l);
	getchar();
	for (i = 0; i < d; i++) {
		for (j = 0; j < l; j++)
			p[i][j] = getchar();
		getchar();
	}

	int k;
	for (k = 1; k <= n; k++) {
		char **t = (char**)malloc(sizeof(char *) * l);
		for (i = 0; i < l; i++) {
			t[i] = (char*)malloc(sizeof(char) * 26);
			memset(t[i], (int)'0', sizeof(char) * 26);
		}
//		for (i = 0; i < l; i++)
//			for (j = 0; j < 26; j++)
//				t[i][j] = '0';
		
		char c;
		int mark = 1;
		i = 0;
		while ((c = getchar()) != '\n' && c != EOF) {
			if (c == '(') {
				mark = 0;
				continue;
			} else if (c == ')') {
				mark = 1;
				i++;
				continue;
			} else
				t[i][c - 'a'] = '1';
			if (mark == 1)
				i++;
		}
		
		int counter = 0;
		for (i = 0; i < d; i++) {
			for (j = 0; j < l; j++) {
				if (t[j][p[i][j] - 'a'] != '1')
					break;
			}
			if (j == l)
				counter++;
		}

		printf("Case #%d: %d\n", k, counter);
	}
	return 0;
}
