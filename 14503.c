#include <stdio.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0

int** room;
int count;

int dirx[4] = { -1,0,1,0 };
int diry[4] = { 0,1,0,-1 };

int main() {

	int N, M;
	int r, c, d;

	int curD, nextD;
	int turn;

	scanf("%d %d", &N, &M);

	room = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++) {
		room[i] = (int*)malloc(sizeof(int) * M);
	}

	scanf("%d %d %d", &r, &c, &d);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &room[i][j]);
		}
	}

	curD = d; turn = FALSE;
	while (TRUE) {

		if (room[r][c] == 0) {
			count++;
			room[r][c] = 2;
		}

		turn = FALSE;
		for (int i = 0; i < 4; i++) {

			nextD = (curD + 3) % 4;

			if ((room[r + dirx[nextD]][c + diry[nextD]]) == 0) {
				r += dirx[nextD];
				c += diry[nextD];
				curD = nextD;

				turn = TRUE;
				break;
			}
			else {
				curD = nextD;
			}
		}

		if (turn == FALSE) {

			if ((room[r - dirx[curD]][c - diry[curD]]) == 1) {
				printf("%d\n", count);
				break;
			}
			else {
				r -= dirx[curD];
				c -= diry[curD];
			}
		}

	}
}