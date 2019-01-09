#include <stdio.h>

#define UP 0
#define DN 1
#define LE 2
#define RI 3

int ans[20][20];
int N[20][20];
int dir;
int n;

void move() {
	
	switch (dir) {
	case UP:
		for (int j = 0; j < n; j++) {
			int i = 0;
			int k = 0;

			for (i = 0; i < n; i++) {
				if (N[i][j] != 0) {
					if (ans[k][j] == 0)
						ans[k][j] = N[i][j];
					else if (ans[k][j] == N[i][j]) {
						ans[k][j] += N[i][j];
						k++;
					}
					else {
						k++;
						ans[k][j] = N[i][j];
					}
				}
			}
		}
		break;
	case DN:
		for (int j = 0; j < n; j++) {
			int i;
			int k = n - 1;

			for (i = n - 1; i > -1; i--) {
				if (N[i][j] != 0) {
					if (ans[k][j] == 0)
						ans[k][j] = N[i][j];
					else if (ans[k][j] == N[i][j]) {
						ans[k][j] += N[i][j];
						k--;
					}
					else {
						k--;
						ans[k][j] = N[i][j];
					}
				}
			}
		}
		break;

	case LE:
		for (int i = 0; i < n; i++) {
			int j = 0;
			int k = 0;

			for (j = 0; j < n; j++) {
				if (N[i][j] != 0) {
					if (ans[i][k] == 0)
						ans[i][k] = N[i][j];
					else if (ans[i][k] == N[i][j]) {
						ans[i][k] += N[i][j];
						k++;
					}
					else {
						k++;
						ans[i][k] = N[i][j];
					}
				}
			}
		}
		break;

	case RI:
		for (int i = 0; i < n; i++) {
			int j = 0;
			int k = n - 1;

			for (j = n-1; j > -1; j--) {
				if (N[i][j] != 0) {
					if (ans[i][k] == 0)
						ans[i][k] = N[i][j];
					else if (ans[i][k] == N[i][j]) {
						ans[i][k] += N[i][j];
						k--;
					}
					else {
						k--;
						ans[i][k] = N[i][j];
					}
				}
			}
		}
		break;
	}
}
int main(void)
{
	int test_case;
	int T;
	char dir_buf[10];

	freopen("input.txt", "r", stdin);
	
	setbuf(stdout, NULL);
	scanf("%d", &T);
	
	for (test_case = 1; test_case <= T; ++test_case)
	{

		scanf("%d %s", &n, &dir_buf);

		if (dir_buf[0] == 'u')
			dir = UP;
		else if (dir_buf[0] == 'd')
			dir = DN;
		else if (dir_buf[0] == 'l')
			dir = LE;
		else if (dir_buf[0] == 'r')
			dir = RI;
		else {
			printf("ERROR!\n");
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &N[i][j]);
				ans[i][j] = 0;
			}
		}

		move();

		printf("#%d\n", test_case);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d", ans[i][j]);

				if (j != n - 1)
					printf(" ");
				else
					printf("\n");
			}
		}
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}