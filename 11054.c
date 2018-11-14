#include <stdio.h>
#include <stdlib.h>

int N;

int* number;
int* dp;

int num;
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
		num = 0;
		for (int j = 0; j < i; j++) {
			if (number[i] > number[j]) {
				if (num < dp[j])
					num = dp[j];
			}
		}

		dp[i] = num + number[i];
		len_max = len_max < dp[i] ? dp[i] : len_max;
	}
	printf("%d\n", len_max);
	return 0;
}