#include <stdio.h>

int main() {

	int DP[11];
	int T,n;
	int i;

	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 4;

	for (i = 4; i < 11; i++) {
		DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
	}

	scanf("%d\n", &T);
	for (i = 0; i < T; i++) {
		scanf("%d", &n);
		printf("%d\n", DP[n]);
	}

	return 0;
}