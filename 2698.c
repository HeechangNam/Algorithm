#include <stdio.h>

int main() {

	int aray[101][101][2] = { 0 };
	int T, t;
	int i, j;
	int n, k;

	aray[1][0][1] = 1;
	aray[1][0][0] = 1;

	for (i = 2; i < 101; i++) {
		for (j = 0; j < i; j++) {
			aray[i][j][0] = aray[i - 1][j][0] + aray[i - 1][j][1];
			aray[i][j][1] = aray[i - 1][j][0] + ((j > 0) ? aray[i - 1][j - 1][1] : 0);
		}
	}

	scanf("%d", &T);

	for (t = 0; t < T; t++) {
		scanf("%d %d", &n, &k);
		printf("%d\n", aray[n][k][0] + aray[n][k][1]);
	}

	return 0;
}