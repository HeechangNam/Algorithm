#include <stdio.h>
#include <stdlib.h>

char* data;
int N;


/* 해당 캐릭터가 숫자인지 연산자인지 판별하는 함수
** 숫자이면 1 리턴
** 연산자이면 0 리턴 */
int thisis(char c) {
	int answer;

	if (c >= '0' && c <= '9')
		answer = 1;
	else
		answer = 0;
	
	return answer;
}

int search(int node) {
	int lc;
	int rc;
	int cur;

	if (node > N)
		return -1;

	lc = search(node * 2);
	rc = search((node * 2) + 1);
	cur = thisis(data[node]);

	return lc*rc*cur;

}

int main() {

	int t;
	int T = 10;
	int ans;
	int n;
	int i;
	char c;
	int g1, g2, g3;

	for (t = 0; t < T; t++) {
		
		scanf("%d", &N);
		data = (char*)malloc(sizeof(char*) * (N + 1));

		for (i = 1; i <= N; i++) {
			scanf("%d %c %d %d", &g1, &c, &g2, &g3);
			data[i] = c;
		}

		if (N % 2 == 0)
			ans = 0;
		else {
			ans = search(1);
		}


		printf("#%d %d", t + 1, ans);
	}

}