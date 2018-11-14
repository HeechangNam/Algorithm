#include <stdio.h>
#include <stdlib.h>

int N;
int min = 9999999;


void dfs(int cnt, int num) {

	if (num == 1) {
		min = min < cnt ? min : cnt;
		return;
	}

	if (cnt > min || num < 1)
		return;

	if ((num % 3) == 0)
		dfs(cnt + 1, num / 3);

	if ((num % 2) == 0)
		dfs(cnt + 1, num / 2);

	dfs(cnt + 1, num - 1);
}
int main() {

	scanf("%d", &N);

	dfs(0, N);
	
	printf("%d\n", min);
	return 0;
}