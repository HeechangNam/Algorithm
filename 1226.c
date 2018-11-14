/* DFS 쓰면 되는 문제!
*/

#include <stdio.h>
#include <stdlib.h>

int map[16][16];
int visit[16][16];

typedef struct {
	int x;
	int y;
}point;

point start;
point goal;
point* queue;
int rear, front;

int BFS(point vertex) {

	int flag = 0;
	point temp;

	visit[vertex.x][vertex.y] = 1;
	queue[rear++] = vertex;

	while (front < rear) {
		vertex = queue[front++];

		if (vertex.x == goal.x && vertex.y == goal.y) {
			flag = 1;
			return flag;
		}

		if (vertex.x != 0) {
			temp.x = vertex.x - 1; temp.y = vertex.y;
			if (visit[temp.x][temp.y] == 0) {
				visit[temp.x][temp.y] = 1;
				queue[rear++] = temp;
			}
		}
		if (vertex.y != 0) {
			temp.x = vertex.x; temp.y = vertex.y - 1;
			if (visit[temp.x][temp.y] == 0) {
				visit[temp.x][temp.y] = 1;
				queue[rear++] = temp;
			}
		}
		if (vertex.x != 15) {
			temp.x = vertex.x + 1; temp.y = vertex.y;
			if (visit[temp.x][temp.y] == 0) {
				visit[temp.x][temp.y] = 1;
				queue[rear++] = temp;
			}
		}
		if (vertex.y != 15) {
			temp.x = vertex.x; temp.y = vertex.y + 1;
			if (visit[temp.x][temp.y] == 0) {
				visit[temp.x][temp.y] = 1;
				queue[rear++] = temp;
			}
		}
	}

	return flag;
}

int main() {

	int i, j;
	char c;
	int flag = 0;
	int temp;
	int testcase;

	for (int t = 0; t < 10; t++) {
		scanf("%d\n", &testcase);
		queue = (point*)malloc(sizeof(point) * 260);
		front = rear = 0;

		for (i = 0; i < 16; i++) {
			for (j = 0; j < 16; j++) {
				scanf("%c", &c);
				temp = c - '0';
				if (temp == 2) {
					start.x = i; start.y = j;
				}


				if (temp == 3) {
					goal.x = i; goal.y = j;
				}


				map[i][j] = temp;

				if (temp == 1) {
					visit[i][j] = 1;
				}
				else {
					visit[i][j] = 0;
				}
			}
			scanf("%c\n", &c);
		}

		printf("#%d", testcase);
		flag = BFS(start);
		printf(" %d\n", flag);
		free(queue);
	}
	return 0;
}