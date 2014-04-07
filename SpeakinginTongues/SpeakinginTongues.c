#include <stdio.h>

int main(void)
{
	char maps[] = {'y', 'h', 'e', 's', 'o', 'c', 'v',
	               'x', 'd', 'u', 'i', 'g', 'l', 'b',
				   'k', 'r', 'z', 't', 'n', 'w',
				   'j', 'p', 'f', 'm', 'a', 'q'};
	int t;
	scanf("%d ", &t);
	int k;
	for (k = 1; k <= t; k++) {
		printf("Case #%d: ", k);
		char c;
		while (( c = getchar() ) != '\n' && (c != EOF)) {
			if (c == ' ')
				putchar(c);
			else
				putchar(maps[c - 'a']);
		}
		printf("\n");
	}

	return 0;
}
