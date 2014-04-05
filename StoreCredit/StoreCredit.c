#include <stdio.h>
#include <stdlib.h>
typedef long long i64;
#define swap(a,b) {int temp = (a); (a) = (b); (b) = temp;}

int Partition(int a[], int p, int r, int c[])
{
	int key = a[r];
	int i;
	int j = p - 1;
	for (i = p; i < r; i++) {
		if (a[i] <= key) {
			j++;
			swap(a[j], a[i]);
			swap(c[j], c[i]);
		}
	}
	swap(a[j + 1], a[r]);
	swap(c[j + 1], c[r]);
	return j + 1;
}
void quickSort(int a[], int p, int r, int c[])
{
	if (p < r) {
		int q = Partition(a, p, r, c);
		quickSort(a, p, q - 1, c);
		quickSort(a, q + 1, r, c);
	}
}

int binarySearch(int a[], int p, int r, int target)
{
	for ( ; p <= r; ) {
		int mid = p + (r - p ) / 2;
		if (a[mid] == target)
			return mid;
		else if (a[mid] < target)
			p = mid + 1;
		else 
			r = mid - 1;
	}
	return -1;
}

int main() {
  int T; 
  scanf("%d", &T);
  int Ti;
  for (Ti = 1; Ti <= T; ++Ti) {
    int sum, n; 
	scanf("%d %d", &sum, &n);
	int *b = (int *)malloc(sizeof(int) * n);
	int *c = (int *)malloc(sizeof(int) * n);
	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		c[i] = i + 1;
	}
	quickSort(b, 0, n - 1, c);
	for (i = 0; i < n - 1; i++) {
		int index;
		if ((index = binarySearch(b, i + 1, n - 1, sum - b[i])) != -1) {
			if (c[i] < c[index])
				printf("Case #%d: %d %d\n", Ti, c[i], c[index]);
			else
				printf("Case #%d: %d %d\n", Ti, c[index], c[i]);
			break;
		}
	}
  }
  return 0;
}
