/*
strings[5][16]을 선언하고
5줄 읽는다.
각 캐릭터가 A~Z, a~z, 0~9이면 출력한다.
*/

#include <stdio.h>
#include <stdlib.h>

char** strings;

int check(char c) {
	if (c >= 'A' && c <= 'Z')
		return 1;
	else if (c >= 'a' && c <= 'z')
		return 1;
	else if (c >= '0' && c <= '9')
		return 1;
	else
		return 0;
}

int main() {

	int t, T;
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (t = 1; t <= T; t++) {

		strings = (char**)malloc(sizeof(char*) * 5);
		for (int i = 0; i < 5; i++) {
			strings[i] = (char*)malloc(sizeof(char) * 16);
			scanf("%s", strings[i]);
		}

		printf("#%d ", t);
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 5; j++) {
				if (check(strings[j][i]))
					printf("%c", strings[j][i]);
			}
		}
		printf("\n");

		for (int i = 0; i < 5; i++)
			free(strings[i]);
		free(strings);
	}

	return 0;
}