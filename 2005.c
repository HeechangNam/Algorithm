#include <stdio.h>
#include <stdlib.h>

int main() {

	int t, T;
	int N;
	int* tri;
	int i, j;

	scanf("%d", &T);

	for (t = 0; t < T; t++) {
		
		scanf("%d", &N);
		tri = (int*)malloc(sizeof(int) * N);

		printf("#%d\n", t + 1);

		printf("1\n");
		for (i = 1; i < N; i++) {
			tri[0] = 1;
			tri[i] = 1;
			for (j = i - 1; j > 0; j--) {
				tri[j] = tri[j] + tri[j - 1];
			}

			for (j = 0; j < i; j++) {
				printf("%d ", tri[j]);
			}
			printf("%d\n", tri[j]);
		}
	}
	

	return 0;
}
