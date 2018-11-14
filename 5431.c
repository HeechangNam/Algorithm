/*

flag[N]을 동적할당하고 각 값은 1로 초기화한다
K만큼 읽어가면서 flag[k]를 0으로 set한다.
flag[i]가 1인 i를 출력한다.
*/

#include <stdio.h>
#include <stdlib.h>

int* flag;

int main() {

	int t, T;
	int N, K;
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (t = 1; t <= T; t++) {
		scanf("%d %d", &N, &K);
		flag = (int*)malloc(sizeof(int) * (N+1));
		for (int i = 0; i <= N; i++) {
			flag[i] = 1;
		}

		for (int i = 0; i < K; i++) {
			int k;
			scanf("%d", &k);
			flag[k] = 0;
		}

		printf("#%d ", t);
		for (int i = 1; i <= N; i++) {
			if (flag[i] == 1)
				printf("%d ", i);
		}
		printf("\n");
	}

	return 0;
}