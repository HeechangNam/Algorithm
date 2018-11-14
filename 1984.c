#include <stdio.h>

int main() {

	int t, T;
	int aray[10];
	int max, min, sum;
	int i;
	int avg;

	scanf("%d", &T);

	for (t = 0; t < T; t++) {
		
		for (i = 0; i < 9; i++)
			scanf("%d ", &aray[i]);
		scanf("%d", &aray[i]);

		min = aray[0];
		max = aray[0];

		sum = aray[0];
		for (i = 1; i < 10; i++) {
			if (min > aray[i])
				min = aray[i];
			if (max < aray[i])
				max = aray[i];
			sum += aray[i];
		}

		sum = sum - (min + max);

		avg = (sum / 8.0) + 0.5;

		printf("#%d %d\n", t + 1, avg);
	}

	return 0;
}