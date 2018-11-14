#include <stdio.h>
#include <stdlib.h>

int main() {

	int t, T;
	int N, K;

	int** aray;
	int* candidate;
	int i,j;
	int cnt;
	
	scanf("%d", &T);
	for (t = 0; t < T; t++) {

		scanf("%d %d", &N, &K);

		candidate = (int*)malloc(sizeof(int) * N);
		aray = (int**)malloc(sizeof(int*) * (N + 1));
		for (i = 0; i < N; i++)
			aray[i] = (int*)malloc(sizeof(int) * N);
			
		for (i = 0; i < N; i++) {
			candidate[i] = 0;
			for (j = 0; j < N; j++) {
				scanf("%d", &aray[i][j]);
			}
		}
		candidate[i] = 0;

		cnt = 0;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (aray[i][j] == 1) cnt++;

				if (aray[i][j] == 1 && ((j == N - 1) || (aray[i][j + 1] == 0))) {
					candidate[cnt]++;
					cnt = 0;
				}
			}
		}

		cnt = 0;
		for (j = 0; j < N; j++) {
			for (i = 0; i < N; i++) {
				if (aray[i][j] == 1) cnt++;

				if (aray[i][j] == 1 && ((i == N - 1) || (aray[i + 1][j] == 0))) {
					candidate[cnt]++;
					cnt = 0;
				}
			}
		}


		printf("#%d %d\n", t + 1, candidate[K]);
	}

	return 0;
}