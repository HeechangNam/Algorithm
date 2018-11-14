#include <stdio.h>

int clap_check(int i) {

	int flag = 0;

	if (i == 0)
		return 0;
	else {
		if (((i % 10) == 3) || ((i % 10) == 6) || ((i % 10) == 9)) {
			printf("-");
			flag = 1;
		}

		i /= 10;

		return flag + clap_check(i);
	}
}

int main() {

	int i, n;
	int flag;

	scanf("%d\n", &n);

	printf("1 2");
	for (i = 3; i <= n; i++) {

		printf(" ");

		flag = clap_check(i);
		if (flag == 0)
			printf("%d", i);

	}
	printf("\n");

	return 0;
}