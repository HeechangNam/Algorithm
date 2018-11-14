#include <stdio.h>
#include <stdlib.h>

int N;

int* number;
int* dp;

int sum;
int sum_max;

int main() {

	scanf("%d", &N);
	number = (int*)malloc(sizeof(int) * N);
	dp = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &number[i]);
		dp[i] = 0;
	}

	for (int i = 0; i < N; i++) {
		sum = 0;
		for (int j = 0; j < i; j++) {
			if (number[i] > number[j]) {
				if (sum < dp[j])
					sum = dp[j];
			}
		}

		dp[i] = sum + number[i];
		sum_max = sum_max < dp[i] ? dp[i] : sum_max;
	}
	printf("%d\n", sum_max);
	return 0;
}