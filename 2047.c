#include <stdio.h>
#include <string.h>

char upper(char c) {

	char result;

	result = c;
	if ((c >= 'a') && (c <= 'z')) {
		result = c - 32;
	}

	return result;
}

int main() {
	char str[80];
	int i, len;

	fgets(str, sizeof(str), stdin);

	len = strlen(str);

	for (i = 0; i < len; i++) {
		str[i] = upper(str[i]);
	}

	printf("%s\n", str);

	return 0;
}