/*
길이가 짧아서 그냥 해도 되겠다.
모든 경우의 수 계산.
*/

#include <stdio.h>
#include <stdlib.h>

#define MIN -2147483647 - 1
#define MAX 2147483647

int N;
int* opend;
int op[4];
int max = MIN;
int min = MAX;

void dfs(int c, int v) {
	if (c == N) {
		min = min < v ? min : v;
		max = max > v ? max : v;
		return;
	}

	if (op[0]) --op[0], dfs(c + 1, v + opend[c]), ++op[0];
	if (op[1]) --op[1], dfs(c + 1, v - opend[c]), ++op[1];
	if (op[2]) --op[2], dfs(c + 1, v * opend[c]), ++op[2];
	if (op[3]) --op[3], dfs(c + 1, v / opend[c]), ++op[3];
}
int main() {

	scanf("%d\n", &N);
	
	opend = (int*)malloc(sizeof(int*) * N);

	for (int i = 0; i < N; i++)
		scanf("%d", &opend[i]);

	for (int i = 0; i < 4; i++) {
		scanf("%d", &op[i]);
	}
		
	dfs(1, opend[0]);


	printf("%d\n", max);
	printf("%d\n", min);

	free(opend);
	return 0;
}