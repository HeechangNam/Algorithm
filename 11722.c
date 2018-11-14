#include <stdio.h>
#include <stdlib.h>

int main() {

	int n;
	int* aray;
	int* DP;
	int i,j;
	int max = 0, min;

	scanf("%d", &n);

	aray = (int*)malloc(sizeof(int) * (n + 1));
	DP = (int*)malloc(sizeof(int) * (n + 1));

	for (i = 0; i < n; i++) {
		scanf("%d", &aray[i]);
	}
	DP[0] = 1;

	for (i = 1; i < n; i++) {
		min = 0;
		for (j = 0; j < i; j++) {
			if (aray[i] < aray[j]) {
				if (min < DP[j]) min = DP[j];
			}
		}
		DP[i] = min + 1;
		if (max < DP[i]) max = DP[i];
	}

	printf("%d\n", max);

	return 0;
}