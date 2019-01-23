#include <stdio.h>

int main() {
	int ans_x;
	int ans_y;
	int input = 0;
	int buf = 0;

	for (int i = 0; i < 4; i++) {
		scanf("%d", &input);
		buf += input;
	}

	ans_x = buf / 60;
	ans_y = buf % 60;

	printf("%d\n", ans_x);
	printf("%d\n", ans_y);
}