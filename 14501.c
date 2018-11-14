#include <stdio.h>
#include <stdlib.h>

int main() {
	int N;
	int** adjMatrix;
	int* distance;
	int result;

	scanf("%d", &N);

	adjMatrix = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++) {
		adjMatrix[i] = (int*)malloc(sizeof(int) * (N+1));
	}

	distance = (int*)malloc(sizeof(int) * (N+1));
	for (int i = 0; i < N; i++) distance[i] = 0;

	for (int i = 0; i < N; i++) {
		int t, p;
		scanf("%d %d", &t, &p);
		
		for (int j = 0; j < i; j++) adjMatrix[i][j] = -1;
		for (int j = i; (j < i + t) && (j <= N); j++) adjMatrix[i][j] = -1;
		for (int j = i + t; j <= N; j++) adjMatrix[i][j] = p;
	}

	for (int i = 0; i < N; i++) {
		for (int j = i; j <= N; j++) {
			if (adjMatrix[i][j] > 0) {
				distance[j] = max(distance[j], distance[i] + adjMatrix[i][j]);
			}
		}
	}

	result = 0;
	for (int i = 0; i <= N; i++) {
		result = max(result, distance[i]);
	}

	printf("%d\n", result);
	free(distance);
	for (int i = 0; i < N; i++) free(adjMatrix[i]);
	free(adjMatrix);

	return 0;
}