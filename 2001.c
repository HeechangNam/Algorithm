#include <stdio.h>
#include <stdlib.h>

int main() {
	int t, T;
	int N, M;
	int** aray;
	int i, j;
	int k, l;
	int max;
	int sum;

	scanf("%d", &T);

	for (t = 0; t < T; t++) {

		scanf("%d %d", &N, &M);

		aray = (int**)malloc(sizeof(int*) * N);
		for (i = 0; i < N; i++) {
			aray[i] = (int*)malloc(sizeof(int) * N);
		}
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				scanf("%d", &aray[i][j]);
			}
		}

		max = 0;
		for (i = 0; i < N - M + 1; i++) {
			for (j = 0; j < N - M + 1; j++) {

				sum = 0;
				for (k = i; k < i + M;k++) {
					for (l = j; l < j + M;l++) {
						sum += aray[k][l];
					}
				}

				if (max < sum)
					max = sum;
			}
		}


		printf("#%d %d\n", t + 1, max);
	}
}