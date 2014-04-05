#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	int k;
	int T[4][4];
	char c;
	int isComplete;
	for (k = 1; k <= n; k++) {
		getchar();
		int i, j;
		isComplete = 1;
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				c = getchar();	
				if (c == '.')
					isComplete = 0;
				T[i][j]  = c;
			}
			getchar();
		}
		int T1Won, T2Won;
		for (i = 0; i < 4; i++) {
			T1Won = T2Won = 1;
			for (j = 0; j < 4; j++) {
				if (T[i][j] != 'X' && T[i][j] != 'T') 
					T1Won = 0;
				if (T[i][j] != 'O' && T[i][j] != 'T')
					T2Won = 0;
			}
			if (T1Won == 1 || T2Won == 1)
				break;
			T1Won = T2Won = 1;
			for (j = 0; j < 4; j++) {
				if (T[j][i] != 'X' && T[j][i] != 'T') 
					T1Won = 0;
				if (T[j][i] != 'O' && T[j][i] != 'T')
					T2Won = 0;
			}
			if (T1Won == 1 || T2Won == 1)
				break;
		}
		if (T1Won == T2Won) {
			T1Won = T2Won = 1;
			for (i = 0; i < 4; i++) {
				if (T[i][3 - i] != 'X' && T[i][3 - i] != 'T')
					T1Won = 0;
				if (T[i][3 - i] != 'O' && T[i][3 - i] != 'T')
					T2Won = 0;
			}
			if (T1Won == 0 && T2Won == 0) {
				T1Won = T2Won = 1;
				for (i = 0; i < 4; i++) {
					if (T[i][i] != 'X' && T[i][i] != 'T')
						T1Won = 0;
					if (T[i][i] != 'O' && T[i][i] != 'T')
						T2Won = 0;
				}
			}
		}
		if (isComplete) {
			if (T1Won == 1)
				printf("Case #%d: X won\n", k);
			else if (T2Won == 1)
				printf("Case #%d: O won\n", k);
			else 
				printf("Case #%d: Draw\n", k);
		}
		else {
			if (T1Won == 1)
				printf("Case #%d: X won\n", k);
			else if (T2Won == 1)
				printf("Case #%d: O won\n", k);
			else 
				printf("Case #%d: Game has not completed\n", k);
		}
	}
	return 0;
}
