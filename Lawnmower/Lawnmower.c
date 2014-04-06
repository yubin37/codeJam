#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
int main(void)
{
	int t;
	scanf("%d", &t);
	int k;
	for (k = 1; k <= t; k++) {
		int n, m;
		scanf ("%d %d", &n, &m);
		int i, j;
		int **lawn = (int **)malloc(sizeof(int) * n);

		int *rowLargest = (int*)malloc(sizeof(int) * n);
		int *colLargest = (int*)malloc(sizeof(int) * m);
		memset(rowLargest, 0, sizeof(int) * n);
		memset(colLargest, 0, sizeof(int) * m);

		for (i = 0; i < n; i++) 
			lawn[i] = (int *)malloc(sizeof(int) * m);

		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++) {
				scanf("%d", &lawn[i][j]);
				if (lawn[i][j] > rowLargest[i])
					rowLargest[i] = lawn[i][j];
				if (lawn[i][j] > colLargest[j])
					colLargest[j] = lawn[i][j];
			}
		char result = 'T';
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				if (lawn[i][j] < rowLargest[i] &&
					lawn[i][j] < colLargest[j] ) {
					result = 'F';
					break;
				}
		if (result == 'T')
			printf("Case #%d: YES\n", k);
		else
			printf("Case #%d: NO\n", k);
	}
}
