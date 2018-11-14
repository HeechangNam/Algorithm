/*
1 .들을 숫자로 바꿔서 채운다
2 0인 숫자들 + 그 바로 옆의 칸을 연다
3 나머지들을 차레로 연다

board에 값을 입력받고 1의 결과를 저장한다.
flag{open, not open, close} 에 연 칸들을 표시한다.
*/

#include <stdio.h>
#include <stdlib.h>

#define OPEN 1
#define NOTOPEN 2
#define CLOSE 3

char** board;
int** flag;
int* queue;
int rear, front;
int* stack;
int top;
int N;
int notopendcell;
int result;

// 1.을 실행
void check() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] != '*') {
				int count = 0;

				if (i != 0) {
					if (board[i - 1][j] == '*')
						count++;
				}

				if (i != N - 1) {
					if (board[i + 1][j] == '*')
						count++;
				}

				if (j != 0) {
					if (board[i][j - 1] == '*')
						count++;
				}

				if (j != N - 1) {
					if (board[i][j + 1] == '*')
						count++;
				}

				if (i != 0 && j != 0) {
					if (board[i - 1][j - 1] == '*')
						count++;
				}

				if (i != 0 && j != N - 1) {
					if (board[i - 1][j + 1] == '*')
						count++;
				}

				if (i != N - 1 && j != 0) {
					if (board[i + 1][j - 1] == '*')
						count++;
				}

				if (i != N - 1 && j != N - 1) {
					if (board[i + 1][j + 1] == '*')
						count++;
				}

				board[i][j] = count + '0';

				if (count == 0) {
					stack[top++] = i * N + j;
				}
			}
		}
	}
}

// 2.를 실행
void BFS(int vertex) {
	int i = vertex / N;
	int j = vertex % N;

	if (flag[i][j] == OPEN)
		return;
	result++;

	flag[i][j] = OPEN;
	queue[rear++] = vertex;
	while (front < rear)
	{
		vertex = queue[front++];
		i = vertex / N;
		j = vertex % N;
		notopendcell--;

		if (board[i][j] == '0') {
			if (i != 0) {
				if (board[i - 1][j] != '*' && flag[i - 1][j] == NOTOPEN) {
					flag[i - 1][j] = OPEN;
					queue[rear++] = (i - 1)*N + j;
				}
			}

			if (i != N - 1) {
				if (board[i + 1][j] != '*' && flag[i + 1][j] == NOTOPEN) {
					flag[i + 1][j] = OPEN;
					queue[rear++] = (i + 1)*N + j;
				}
					
			}

			if (j != 0) {
				if (board[i][j - 1] != '*' && flag[i][j - 1] == NOTOPEN) {
					flag[i][j - 1] = OPEN;
					queue[rear++] = i * N + j - 1;
				}
			}

			if (j != N - 1) {
				if (board[i][j + 1] != '*' && flag[i][j + 1] == NOTOPEN) {
					flag[i][j + 1] = OPEN;
					queue[rear++] = i * N + j + 1;
				}
			}

			if (i != 0 && j != 0) {
				if (board[i - 1][j - 1] != '*' && flag[i - 1][j - 1] == NOTOPEN) {
					flag[i - 1][j - 1] = OPEN;
					queue[rear++] = (i - 1) * N + j - 1;
				}
					
			}

			if (i != 0 && j != N - 1) {
				if (board[i - 1][j + 1] != '*' && flag[i - 1][j + 1] == NOTOPEN) {
					flag[i - 1][j + 1] = OPEN;
					queue[rear++] = (i - 1) * N + j + 1;
				}
					
			}

			if (i != N - 1 && j != 0) {
				if (board[i + 1][j - 1] != '*' && flag[i + 1][j - 1] == NOTOPEN) {
					flag[i + 1][j - 1] = OPEN;
					queue[rear++] = (i + 1) * N + j - 1;
				}
					
			}

			if (i != N - 1 && j != N - 1) {
				if (board[i + 1][j + 1] != '*' && flag[i + 1][j + 1] == NOTOPEN) {
					flag[i + 1][j + 1] = OPEN;
					queue[rear++] = (i + 1) * N + j + 1;
				}
					
			}
		}
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
		scanf("%d\n", &N);
		notopendcell = N * N;
		front = 0;
		rear = 0;
		top = 0;
		result = 0;

		board = (char**)malloc(sizeof(char*) * N);
		flag = (int**)malloc(sizeof(int*) * N);
		queue = (int*)malloc(sizeof(int) * (N*N));
		stack = (int*)malloc(sizeof(int) * (N*N));
		
		for (int i = 0; i < N; i++) {
			board[i] = (char*)malloc(sizeof(char) * N);
			flag[i] = (int*)malloc(sizeof(int) * N);
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (j != N - 1)
					scanf("%c", &board[i][j]);
				else
					scanf("%c\n", &board[i][j]);

				if (board[i][j] == '*') {
					flag[i][j] = CLOSE;
					notopendcell--;
				}
				else
					flag[i][j] = NOTOPEN;
				queue[i*N + j] = 0;
				stack[i*N + j] = 0;
			}
		}

		check();

		while (top != 0) {
			int vertex = stack[--top];
			BFS(vertex);
		}

		//3.을 실행
		result += notopendcell;

		//출력
		printf("#%d %d\n", test_case, result);


		free(queue);
		free(stack);
		for (int i = 0; i < N; i++) {
			free(board[i]);
			free(flag[i]);
		}
		free(board);
		free(flag);

	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}