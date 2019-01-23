#include <stdio.h>

int main() {
	int total;
	int extra;
	int buf;

	scanf("%d\n", &total);

	extra = 0;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &buf);
		extra += buf;
	}

	printf("%d\n", total - extra);
}