#include <stdio.h>
#include <string.h>

int main() {
	
	char buff[200];
	int len;
	int i;

	gets(buff);
	len = strlen(buff);

	for (i = 0; i < len - 1; i++) {
		printf("%d ", buff[i] - '@');
	}
	printf("%d\n", buff[i] - '@');
}