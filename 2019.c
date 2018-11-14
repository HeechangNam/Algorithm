#include <stdio.h>

int main() {

	int i, n;
	int num;

	scanf("%d", &n);

	num = 1;
	printf("%d ", num);
	for (i = 1; i < n; i++) {
		num *= 2;
		printf("%d ", num);
	}
	printf("%d\n", num * 2);

	return 0;
}