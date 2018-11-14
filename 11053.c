#include <stdio.h>
#include <stdlib.h>

int N;

int* number;
int* dp;

int len;
int len_max;

int main() {

	scanf("%d", &N);
	number = (int*)malloc(sizeof(int) * N);
	dp = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &number[i]);
		dp[i] = 0;
	}

	for (int i = 0; i < N; i++) {
		len = 0;
		for (int j = 0; j < i; j++) {
			if (number[i] > number[j]) {
				if (len < dp[j])
					len = dp[j];
			}
		}

		dp[i] = len + 1;
		len_max = len_max < dp[i] ? dp[i] : len_max;
	}
	printf("%d\n", len_max);
	return 0;
}