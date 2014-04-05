#include <stdio.h>
#include <stdlib.h>

int values[9] = {-1, 2, 5, 8, 11, 14, 18, 21, 25};

int findValue(char c)
{
	if (c - 'a' < 0)
		return -1;
	int i;
	for (i = 0; i < 9; i++)
		if (c - 'a' <= values[i])
			return i;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	int i;
	getchar();
	for (i = 1; i <= n; i++) {
		int prevIndex = -2;
		char c;
		while ((c = getchar() ) != '\n' && c != EOF) {
			if (-2 == prevIndex) 
				printf("Case #%d: ", i);
			int index = findValue(c);
			if (index == prevIndex)
				printf(" ");
			else
				prevIndex = index;
			if (-1 == index)
				printf("0");
			else {
				int j;
				for (j = 0; j < c - 'a' - values[index - 1]; j++) {
					printf("%d", index + 1);
				}
			}
		}
		printf("\n");
	}
	return 0;
}
