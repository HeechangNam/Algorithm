#include <stdio.h>
#include <stdlib.h>

int N;
int **space;

typedef struct _fish {
	int x;
	int y;
	int size;
	int feed;
	int move;
}_fish;
_fish fish;

typedef struct _queue {
	int x;
	int y;
	int depth;
}_queue;
_queue *queue;
int head, tail;

int** visited;
#define WHITE 1
#define BLACK 0

#define UP 0
#define DN 1
#define LT 2
#define RT 3
#define S 4

void insert(int x, int y, int depth) {
	_queue ins;
	ins.x = x; ins.y = y; ins.depth = depth;
	queue[head] = ins;
	head++;
}

_queue delete() {
	_queue ret;
	ret = queue[tail];
	tail++;
	return ret;
}

void init();
void fr();
int BFS();

int main() {
	int flag;

	scanf("%d", &N);
	space = (int**)malloc(sizeof(int*) * N);
	queue = (_queue*)malloc(sizeof(_queue) * (N*N));
	for (int i = 0; i < N; i++)
		space[i] = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &space[i][j]);
			if (space[i][j] == 9) {
				fish.x = i; fish.y = j;
				fish.feed = 0; fish.move = 0;
				fish.size = 2;
			}
		}
	}
	
	flag = 1;
	while (flag) {
		init();
		flag = BFS();
		fr();
	}

	printf("%d\n", fish.move);
}

void init() {
	visited = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++)
		visited[i] = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = WHITE;
		}
	}

	head = 0; tail = 0;
}

void fr() {
	for (int i = 0; i < N; i++)
		free(visited[i]);
	free(visited);
}

int BFS() {
	_queue cur;
	_queue feed;

	insert(fish.x, fish.y, 0);
	visited[fish.x][fish.y] = BLACK;

	feed.x = 99; feed.y = 99; feed.depth = 99;
	while (head != tail) {
		cur = delete();

		if (space[cur.x][cur.y] > 0 && space[cur.x][cur.y] < fish.size) {
			if (feed.depth >= cur.depth){
				if (feed.x > cur.x) feed = cur;
				else if (feed.x == cur.x) {
					if (feed.y > cur.y) feed = cur;
				}
			}
		}

		if (cur.x != 0 && space[cur.x - 1][cur.y] <= fish.size && visited[cur.x - 1][cur.y] == WHITE) {
			insert(cur.x - 1, cur.y, cur.depth + 1);
			visited[cur.x - 1][cur.y] = BLACK;
		}
		if (cur.x != N - 1 && space[cur.x + 1][cur.y] <= fish.size && visited[cur.x + 1][cur.y] == WHITE) {
			insert(cur.x + 1, cur.y, cur.depth + 1);
			visited[cur.x + 1][cur.y] = BLACK;
		}
		if (cur.y != 0 && space[cur.x][cur.y - 1] <= fish.size && visited[cur.x ][cur.y - 1] == WHITE) {
			insert(cur.x, cur.y - 1, cur.depth + 1);
			visited[cur.x][cur.y - 1] = BLACK;
		}
		if (cur.y != N - 1 && space[cur.x][cur.y + 1] <= fish.size && visited[cur.x][cur.y + 1] == WHITE) {
			insert(cur.x, cur.y + 1, cur.depth + 1);
			visited[cur.x][cur.y + 1] = BLACK;
		}

		if (feed.depth != 99) {
			if (feed.depth < cur.depth || head == tail) {
				space[feed.x][feed.y] = 9;
				space[fish.x][fish.y] = 0;
				fish.x = feed.x; fish.y = feed.y;
				fish.feed++;
				fish.move += feed.depth;
				if (fish.feed == fish.size) {
					fish.feed = 0;
					fish.size++;
				}
				return 1;
			}
		}
	}

	return 0;
}