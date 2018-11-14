/* 다 해보면 되겄다.
** 보드를 4가지 방향 중 한 곳으로 기울임 -> 구슬을 옮김 -> 빠지는지 확인. -> 다시 기울임
** 1. 기울이기 2. 옮기기 3. 빠진거 확인
** 1. 기울이기
**	재귀써서. 1- 1- 1- 1- .... 1- 2- 1- 1-.... 식으로
**	기울일때는 몇번째 기울이는지, 빨간 공과  파란 공의 위치, 현재 보드를 넘겨 줌
**
** 2. 옮기기 
**	그냥 옮기면 될듯. BFS나 DFS 쓸 필요도 없겠다. (아니어썽 슈발)
**	보드를 넘기고 거기서 옮기기.
**	왼쪽으로 옮길때는, 왼쪽에 있는 공 먼저 옮기고, 오른쪽으로 옮길때는 오른쪽에 잇는 공 먼저..
**	파란공이 빠지면 무조건 탈락. 파란공이 안빠지고 빨간공이 빠져야 통과
** 3. 빠지는지 확인
**	파란 공 빠지면 바로 재귀함수 break. 빨간 공 빠지면 결과 값 저장 후, flag 설정
*/

#include <stdio.h>
#include <stdlib.h>

#define RED 1
#define BLUE 0

#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3

int dirrow[4] = { -1,0,1,0 };
int dircol[4] = { 0,-1,0,1 };

int N, M;

typedef struct ball {
	int row;
	int col;
}ball;

int ans;

void copyMatrix(char** orgin, char** copy) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			copy[i][j] = orgin[i][j];
		}
	}
}

ball rolling(ball curball, char** board, int dir, int color) {

	ball nextball = curball;
	while (board[nextball.row + dirrow[dir]][nextball.col + dircol[dir]] == '.') {
		nextball.row += dirrow[dir];
		nextball.col += dircol[dir];
	}

	board[curball.row][curball.col] = '.';
	if (board[nextball.row + dirrow[dir]][nextball.col + dircol[dir]] == 'O') {
		nextball.row = -1; nextball.col = -1;
	}
	else {
		if (color == RED)
			board[nextball.row][nextball.col] = 'R';
		else if(color == BLUE)
			board[nextball.row][nextball.col] = 'B';
	}

	return nextball;
}

void tilt(int cnt, ball curRed, ball curBlue, char** origin) {

	char** tempBoard;
	ball nextRed;
	ball nextBlue;
	
	if (cnt > 10)
		return;

	tempBoard = (char**)malloc(sizeof(char*) * N);
	for (int i = 0; i < N; i++)
		tempBoard[i] = (char*)malloc(sizeof(char) * M);

	for (int i = 0; i < 4; i++) {
		switch (i) {
		case UP:
			copyMatrix(origin, tempBoard);
			if (curRed.row < curBlue.row) {
				nextRed = rolling(curRed, tempBoard, UP, RED);
				nextBlue = rolling(curBlue, tempBoard, UP, BLUE);
			}
			else {
				nextBlue = rolling(curBlue, tempBoard, UP, BLUE);
				nextRed = rolling(curRed, tempBoard, UP, RED);
			}
			if (nextBlue.row != -1 && nextBlue.col != -1) {
				if (nextRed.row != -1 && nextBlue.col != -1) {
					tilt(cnt + 1, nextRed, nextBlue, tempBoard);
				}
				else {
					ans = ans < cnt ? ans : cnt;
				}
			}
			break;
		case DOWN:
			copyMatrix(origin, tempBoard);
			if (curRed.row > curBlue.row) {
				nextRed = rolling(curRed, tempBoard, DOWN, RED);
				nextBlue = rolling(curBlue, tempBoard, DOWN, BLUE);
			}
			else {
				nextBlue = rolling(curBlue, tempBoard, DOWN, BLUE);
				nextRed = rolling(curRed, tempBoard, DOWN, RED);
			}
			if(nextBlue.row != -1 && nextBlue.col != -1) {
				if (nextRed.row != -1 && nextBlue.col != -1) {
					tilt(cnt + 1, nextRed, nextBlue, tempBoard);
				}
				else {
					ans = ans < cnt ? ans : cnt;
				}
			}
			break;
		case LEFT:
			copyMatrix(origin, tempBoard);
			if (curRed.col < curBlue.col) {
				nextRed = rolling(curRed, tempBoard, LEFT, RED);
				nextBlue = rolling(curBlue, tempBoard, LEFT, BLUE);
			}
			else {
				nextBlue = rolling(curBlue, tempBoard, LEFT, BLUE);
				nextRed = rolling(curRed, tempBoard, LEFT, RED);
			}
			if (nextBlue.row != -1 && nextBlue.col != -1) {
				if (nextRed.row != -1 && nextBlue.col != -1) {
					tilt(cnt + 1, nextRed, nextBlue, tempBoard);
				}
				else {
					ans = ans < cnt ? ans : cnt;
				}
			}
			break;
		case RIGHT:
			copyMatrix(origin, tempBoard);
			if (curRed.col > curBlue.col) {
				nextRed = rolling(curRed, tempBoard, RIGHT, RED);
				nextBlue = rolling(curBlue, tempBoard, RIGHT, BLUE);
			}
			else {
				nextBlue = rolling(curBlue, tempBoard, RIGHT, BLUE);
				nextRed = rolling(curRed, tempBoard, RIGHT, RED);
			}
			if (nextBlue.row != -1 && nextBlue.col != -1) {
				if (nextRed.row != -1 && nextBlue.col != -1) {
					tilt(cnt + 1, nextRed, nextBlue, tempBoard);
				}
				else {
					ans = ans < cnt ? ans : cnt;
				}
			}
			break;
		}	
	}

	for (int i = 0; i < N; i++)
		free(tempBoard[i]);
	free(tempBoard);
}

int main() {

	char** board;
	ball Red;
	ball Blue;
	char dump;
	scanf("%d %d\n", &N, &M);
	
	board = (char**)malloc(sizeof(char*) * N);
	for (int i = 0; i < N; i++)
		board[i] = (char*)malloc(sizeof(char) * M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%c", &board[i][j]);

			if (board[i][j] == 'R') {
				Red.row = i; Red.col = j;
			}

			if (board[i][j] == 'B') {
				Blue.row = i; Blue.col = j;
			}
		}
		scanf("%c", &dump);
	}

	ans = 99;
	tilt(1, Red, Blue, board);

	if (ans == 99)
		printf("-1\n");
	else
		printf("%d\n", ans);

	for (int i = 0; i < N; i++)
		free(board[i]);
	free(board);

	return 0;
}