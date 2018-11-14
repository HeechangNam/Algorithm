/*
input data는 room이라는 2차원 배열에 저장한다.
N^2 크기의 1차원 배열 cnt는 0으로 초기화 되어있다.

room[0][0]부터 room[N][N]까지 탐색한다.
room[i][j]에 대해 cnt[room[i][j]-1]의 값이 1보다 크면 cnt[room[i][j]]의 값은 cnt[room[i][j]-1]의 -1이 된다.
1이하이면 아직 탐색되지 않은 것이므로 방을 몇 개 이동할 수 있는지 계산한다.
*/

#include <stdio.h>
#include <stdlib.h>

int N;
int** room;
int* cnt;

void passRoom(int i, int j, int value) {
	int flag = 0;

	if (i > 0 && flag == 0) {
		if (value + 1 == room[i - 1][j]) {
			passRoom(i - 1, j, room[i - 1][j]);
			flag = 1;
		}
	}

	if (j > 0 && flag == 0) {
		if (value + 1 == room[i][j - 1]) {
			passRoom(i, j - 1, room[i][j - 1]);
			flag = 1;
		}
	}

	if (i < N-1 && flag == 0) {
		if (value + 1 == room[i + 1][j]) {
			passRoom(i + 1, j, room[i + 1][j]);
			flag = 1;
		}
	}

	if (j < N-1 && flag == 0) {
		if (value + 1 == room[i][j + 1]) {
			passRoom(i, j + 1, room[i][j + 1]);
			flag = 1;
		}
	}

	if (flag == 0)
		cnt[value] = 1;
	else
		cnt[value] = cnt[value + 1] + 1;
}

int main(void)
{
	int test_case;
	int T;
	int result_number;
	int result_count;

	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d", &N);
		room = (int**)malloc(sizeof(int*)*N);
		for (int i = 0; i < N; i++)
			room[i] = (int*)malloc(sizeof(int) * N);
		cnt = (int*)malloc(sizeof(int)*(N*N + 1));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &room[i][j]);
				cnt[i*N + j + 1] = 0;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (cnt[room[i][j] - 1] > 1 && room[i][j] != 1)
					cnt[room[i][j]] = cnt[room[i][j] - 1] - 1;
				else
					passRoom(i,j,room[i][j]);
			}
		}

		result_number = 1;
		result_count = cnt[1];
		for (int i = 2; i <= N * N; i++) {
			if (cnt[result_number] < cnt[i]) {
				result_number = i;
				result_count = cnt[i];
			}
		}
		
		free(cnt);
		for (int i = 0; i < N; i++)
			free(room[i]);
		free(room);

		printf("#%d %d %d\n", test_case, result_number, result_count);

	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}