#include <stdio.h>

int main() {
	int N, M;
	int target[101];
	int vote[101];
	int point[101];

	scanf("%d\n", &N);
	scanf("%d\n", &M);
	
	for (int i = 1; i <= M; i++)
		scanf("%d", &target[i]);

	for (int i = 1; i <= N; i++)
		point[i] = 0;

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {

			scanf("%d", &vote[j]);
			if (target[i] == vote[j])
				point[j]++;
			else
				point[target[i]]++;
		}
	}

	for (int i = 1; i <= N; i++) {
		printf("%d\n", point[i]);
	}
}