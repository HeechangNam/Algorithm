/*
BitMask¹®Á¦!
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {

	int k, l, M, x, S = 0;

	freopen("input.txt", "r", stdin);
	scanf("%d\n", &M);

	for (int i = 0; i < M; i++) {
		char arr[10];
		scanf("%s", arr);

		if (arr[1] == 'd') {
			scanf("%d", &x);
			S |= (1 << x);
		}
		else if (arr[1] == 'l') {
			S = (1 << 22) - 1;
		}
		else if (arr[1] == 'e') {
			scanf("%d", &x);
			S &= ~(1 << x);
		}
		else if (arr[1] == 'm') {
			S = 0;
		}
		else if (arr[1] == 'h') {
			scanf("%d", &x);
			printf("%d\n", S & (1 << x) ? 1 : 0);
		}
		else if (arr[1] == 'o') {
			scanf("%d", &x);
			S ^= (1 << x);
		}
	}

	return 0;
}