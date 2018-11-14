#include <stdio.h>

int main() {
	int t, T;
	int aray[10];
	int i;
	int sum;

	scanf("%d\n", &T);
	for (t = 0; t < T; t++) {
		for (i = 0; i < 9; i++) {
			scanf("%d ", &aray[i]);
		}
		scanf("%d", &aray[9]);

		sum = 0;
		for (i = 0; i < 10; i++) {
			if ((aray[i] % 2) != 0)
				sum += aray[i];
		}

		printf("#%d %d\n", t+1, sum);
	}

	return 0;
}