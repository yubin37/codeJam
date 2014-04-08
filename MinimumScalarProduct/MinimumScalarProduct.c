#include <stdio.h>
#include <stdlib.h>
int comp1(const int *p, const int *q)
{
	if (*p < *q)
		return 1;
	else if (*p > *q)
		return -1;
	else
		return 0;
}

int comp2(const int *p, const int *q)
{
	if (*p < *q)
		return -1;
	else if (*p > *q)
		return 1;
	else
		return 0;
}

int main(void)
{
	int t;
	scanf("%d", &t);
	int k;
	for (k = 1; k <= t; k++) {
		int length;
		scanf("%d", &length);
		int *a = (int*)malloc(sizeof(int) * length);
		int *b = (int *)malloc(sizeof(int) * length);
		int i;
		long long int result = 0;
		for (i = 0; i < length; i++)
			scanf("%d", &a[i]);
		for (i = 0; i < length; i++)
			scanf("%d", &b[i]);
		qsort(a, length, sizeof(int), &comp1);
		qsort(b, length, sizeof(int), &comp2);
		for (i = 0; i < length; i++)
			result += (long long int)a[i] * (long long int)b[i];
		printf("Case #%d: %lld\n", k ,result);
	}
	return 0;
}
