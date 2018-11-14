#include <stdio.h>
#include <stdlib.h>

int* taste;
int* score;
int max;
int N, L;

void choice(int n, int l, int t) {
	int curl = l+score[n];
	int curt = t+taste[n];
	
	if (curl > L || n > N)
		return;

	max = max > curt ? max : curt;
	choice(n + 1, curl, curt);


	return;
}

int main() {

	int t, T;

	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (t = 1; t <= T; t++) {
		scanf("%d %d", &N, &L);

		taste = (int*)malloc(sizeof(int) * (N+1));
		score = (int*)malloc(sizeof(int) * (N+1));
		taste[0] = score[0] = max = 0;
		for (int i = 1; i <= N; i++) {
			scanf("%d %d", &taste[i], &score[i]);
		}

		choice(0, 0, 0);

		printf("#%d %d\n", t, max);

		free(taste); free(score);
	}
	return 0;
}