#include <stdio.h>

int main() {

	int t, T;
	int a, b;
	int m, r;

	scanf("%d\n", &T);

	for (t = 0; t < T; t++) {

		scanf("%d %d", &a, &b);

		m = a / b;
		r = a % b;

		printf("#%d %d %d\n", t + 1, m, r);
	}
}