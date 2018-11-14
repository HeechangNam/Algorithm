/* 연구소에 벽을 세우는 모든 경우의 수에 대해 계산!
** 벽을 세운다 -> 바이러스가 퍼진다 -> 안전구역 계산
** 1. 3개의 벽을 세운다 
**	재귀함수를 사용. 벽 박고 -> 벽 박고 -> 벽 박고
** 원본 행렬 -> 벽 세우는 행렬
** 2. 바이러스가 퍼진다
**	BFS. 2일때 상하좌우에 있고 값이 0일때 큐에 삽입
** 벽 세우는 행렬 -> 바이러스가 퍼지는 행렬
** 3. 안전구역 계산
** 최대값 찾기.
*/

#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0

int** LAB;
int** wallLAB;
int** infestedLAB;

int N, M;
int ans;

typedef struct node{
	int row;
	int col;
	struct node* next;
}node;

node* front;
node* rear;

void printMatrix(int** ary) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", ary[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void copyMatrix(int** origin, int** copy) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			copy[i][j] = origin[i][j];
		}
	}
}

void push(int row, int col) {

	node* temp;

	temp = (node*)malloc(sizeof(node));
	temp->row = row;
	temp->col = col;
	temp->next = NULL;

	if ((front == NULL) && (rear == NULL))
		front = rear = temp;
	else {
		rear->next = temp;
		rear = temp;
	}
}

node pop() {
	
	node* temp;
	node ret;

	temp = front;
	ret.row = front->row;
	ret.col = front->col;

	front = front->next;
	if (front == NULL) rear = NULL;
	free(temp);

	return ret;

}

void infest() {

	node temp;
	int cnt;

	copyMatrix(wallLAB, infestedLAB);

	front = NULL; rear = NULL;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (infestedLAB[i][j] == 2)
				push(i, j);
		}
	}

	while (front != NULL || rear != NULL) {
		temp = pop();
		if (temp.row > 0) {
			if (infestedLAB[temp.row - 1][temp.col] == 0) {
				infestedLAB[temp.row - 1][temp.col] = 2;
				
#if DEBUG
				printMatrix(infestedLAB);
#endif
				push(temp.row - 1, temp.col);
			}
		}
		if (temp.col > 0) {
			if (infestedLAB[temp.row][temp.col - 1] == 0) {
				infestedLAB[temp.row][temp.col - 1] = 2;

#if DEBUG
				printMatrix(infestedLAB);
#endif
				push(temp.row, temp.col - 1);
			}
		}
		if (temp.row < N - 1) {
			if (infestedLAB[temp.row + 1][temp.col] == 0) {
				infestedLAB[temp.row + 1][temp.col] = 2;
				
#if DEBUG
				printMatrix(infestedLAB);
#endif
				push(temp.row + 1, temp.col);
			}
		}
		if (temp.col < M - 1) {
			if (infestedLAB[temp.row][temp.col + 1] == 0) {
				infestedLAB[temp.row][temp.col + 1] = 2;
		
#if DEBUG
				printMatrix(infestedLAB);
#endif
				push(temp.row, temp.col + 1);
			}
		}
	}

	cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (infestedLAB[i][j] == 0)
				cnt++;
		}
	}

	ans = ans > cnt ? ans : cnt;
}

void wall(int flag) {

	if (flag == 0) {
		copyMatrix(LAB, wallLAB);
	}

	if (flag == 3) {
		infest();
		return 0;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (wallLAB[i][j] == 0) {
				wallLAB[i][j] = 1;
				wall(flag + 1);
				wallLAB[i][j] = 0;
			}
		}
	}
}

int main() {

	scanf("%d %d", &N, &M);

	LAB = (int**)malloc(sizeof(int*) * N);
	wallLAB = (int**)malloc(sizeof(int*) * N);
	infestedLAB = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++) {
		LAB[i] = (int*)malloc(sizeof(int) * M);
		wallLAB[i] = (int*)malloc(sizeof(int) * M);
		infestedLAB[i] = (int*)malloc(sizeof(int) * M);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &LAB[i][j]);
		}
	}

	ans = 0;
	wall(0);

	for (int i = 0; i < N; i++) {
		free(LAB[i]);
		free(wallLAB[i]);
		free(infestedLAB[i]);
	}
	free(LAB); free(wallLAB); free(infestedLAB);

	printf("%d\n", ans);
}
