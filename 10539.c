#include <stdio.h>

int main() {
	int N;
	int A[101];
	int B[101];
	int sum;
	int temp;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &B[i]);
	}

	temp = 0;
	for (int i = 1; i <= N; i++) {
		sum = B[i] * i;
		A[i] = sum - temp;
		temp += A[i];
	}

	for (int i = 1; i < N; i++)
		printf("%d ", A[i]);
	printf("%d\n", A[N]);

	return 0;
}