#include <stdio.h>

int main() {
	int input;
	scanf("%d", &input);

	if (input >= 90)
		printf("A\n");
	else if (input >= 80)
		printf("B\n");
	else if (input >= 70)
		printf("C\n");
	else if (input >= 60)
		printf("D\n");
	else
		printf("F\n");
}