/*

month[13]에는 i월0일의 요일이 입력되어 있다.
1월 1일이 금요일이므로 month[1]의 값은 목요일인 3이 들어감
요일은 month[m]+d/7의 값을 리턴한다.
*/

#include <stdio.h>
#include <stdlib.h>

int month[13] = { 0, 3, 6, 0, 3, 5, 1, 3, 6, 2, 4, 0, 2 };

int main() {

	int t, T;
	int m, d;
	//freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (t = 1; t <= T; t++) {
		scanf("%d %d", &m, &d);
		printf("#%d %d\n", t, (month[m] + d) % 7);
	}

	return 0;
}