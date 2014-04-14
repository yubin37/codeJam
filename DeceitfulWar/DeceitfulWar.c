#include <stdio.h>
#include <stdlib.h>

int comp(const float *p , const float *q)
{
	if (*p < *q)
		return -1;
	else if (*p > *q)
		return 1;
	else
		return 0;
}
int getResult(float *p, float *r, int n)
{
	int counter = 0;
	int i, j = 0;
	for (i = 0; i < n; i++) {
		if (j == n)
			break;
		if (r[i] > p[j]) {
			j++;
			counter++;
		}
		
	}
	return n - counter;
}
int main(void)
{
	int t;
	scanf("%d", &t);
	int k;
	for (k = 1; k <= t; k++) {
		int n;
		scanf("%d", &n);
		float *p = (float *)malloc(sizeof(float) * n);
		float *q = (float *)malloc(sizeof(float) * n);
		float *r = (float *)malloc(sizeof(float) * n);

		int i;
		for (i = 0; i < n; i++)
			scanf("%f", &p[i]);
		for (i = 0; i < n; i++) {
			scanf("%f", &q[i]);
			r[i] = q[i];
		}
		qsort(p, n, sizeof(float), &comp);
		qsort(q, n, sizeof(float), &comp);
		printf("Case #%d: %d %d\n", k, n - getResult(q, p, n), getResult(p, q, n));
	}
	return 0;
}

