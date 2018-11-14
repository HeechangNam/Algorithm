#include <stdio.h> 

int winner(int a, int b) {

	int result;

	if (a == 1) {
		if (b == 2)
			result = 0;
		else if (b == 3)
			result = 1;
	}
	else if (a == 2) {
		if (b == 3)
			result = 0;
		else if (b == 1)
			result = 1;
	}
	else {
		if (b == 1)
			result = 0;
		else if (b == 2)
			result = 1;
	}

	return result;
}

int main() {

	int a, b;
	int flag;

	scanf("%d %d", &a, &b);

	flag = winner(a, b);
	if (flag == 1)
		printf("A\n");
	else
		printf("B\n");

	return 0;
}