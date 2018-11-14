/*
inputData는 flag[N][M]에 저장된다.
color[N][3]의 배열은 N번째의 행이 특정 색으로 바뀔 때 칠해지는 칸의 갯수를 저장한다.
즉, color[N][0]은 N번째의 행이 흰색일 때 칠해지는 칸의 갯수를 color[N][B]는 파란색일 때 칠해지는 칸의 갯수를 저장한다.

1. flag 초기화 후, 값에 맞게 color도 초기화 해준다.
2. color[1]~color[N-2]까지의 최소값을 찾는다. - DFS 완전탐색
3. 마지막에 color[0][0]과 color[N-1][2]의 값을 더한다.
*/

#include <stdio.h>
#include <stdlib.h>

#define W 0
#define B 1
#define R 2

char** flag;
int** color;
int N, M;
int result;

void DFS(int row, int col, int val) {

	if (row > N - 2)
		return;

	switch (col) {
	case W:
		val += color[row][W];
		if (row == N - 2) {
			return;
		}
		else {
			DFS(row + 1, W, val);
			DFS(row + 1, B, val);

		}
		break;
	case B:
		val += color[row][B];
		if (row == N - 2)
			result = result > val ? val : result;
		else {
			DFS(row + 1, B, val);
			DFS(row + 1, R, val);
		}
		break;
	case R:
		val += color[row][R];
		if (row == N - 2)
			result = result > val ? val : result;
		else
			DFS(row + 1, R, val);
	}
}

int main(void)
{
	int test_case;
	int T;

	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d\n", &N, &M);
		flag = (char**)malloc(sizeof(char*) * N);
		color = (int**)malloc(sizeof(int*) * N);
		for (int i = 0; i < N; i++) {
			flag[i] = (char*)malloc(sizeof(char) * M);
			color[i] = (int*)malloc(sizeof(int) * 3);
		}
		// 1. 수행
		for (int i = 0; i < N; i++) {
			int notW = 0;
			int notB = 0;
			int notR = 0;

			for (int j = 0; j < M; j++) {
				if (j == M - 1)
					scanf("%c\n", &flag[i][j]);
				else
					scanf("%c", &flag[i][j]);
				switch (flag[i][j]) {
				case 'W':
					notB++;
					notR++;
					break;
				case 'B':
					notW++;
					notR++;
					break;
				case 'R':
					notW++;
					notB++;
					break;
				}
			}
			color[i][W] = notW;
			color[i][B] = notB;
			color[i][R] = notR;
		}

		//2. 수행
		result = 2147483647;
		DFS(1, W, 0);
		DFS(1, B, 0);

		// 3. 수행
		result += color[0][W] + color[N - 1][R];
		printf("#%d %d\n", test_case, result);


		for (int i = 0; i < N; i++) {
			free(flag[i]);
			free(color[i]);
		}
		free(flag);
		free(color);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}