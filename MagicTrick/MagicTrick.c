#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int  main(void)
{
	int t;
	scanf("%d", &t);
	int k;
	int frow, srow;
	int row1[4][4], row2[4][4];
	for (k = 1; k <= t; k++){
		memset(row1, 0, sizeof(int) * 16);
		memset(row2, 0, sizeof(int) * 16);
		scanf("%d", &frow);
		int i, j;
		for (i = 0; i < 4; i++) 
			for (j = 0; j < 4; j++) 
				scanf("%d ", &row1[i][j]);
		scanf("%d", &srow);
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
				scanf("%d", &row2[i][j]);
		int counter = 0;
		int result;
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
				if (row1[frow - 1][i] == row2[srow - 1][j]) {
					counter++;
					result = row1[frow - 1][i];
				}
		printf("Case #%d: ", k);
		if (counter == 0)
			printf("Volunteer cheated!\n");
		else if (counter == 1)
			printf("%d\n", result);
		else
			printf("Bad magician!\n");
	}
	return 0;
}

