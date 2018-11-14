#include <stdio.h>

int main() {
	int i, n;

	scanf("%d", &n);

	for (i = n; i > 0; i--) {
		printf("%d ", i);
	}
	printf("0\n");

}