#include <stdio.h>
#include <stdlib.h>

int N, M, V;
int** adj;

int* path;
int p_index;
int* visit;

int* queue;
int head, tail;

void init(int flag) {
	if (flag == 1) {
		queue = (int*)malloc(sizeof(int) * (N + 5));
		head = 0; tail = 0;
	}

	path = (int*)malloc(sizeof(int) * (N + 1));
	p_index = 0;
	visit = (int*)malloc(sizeof(int*) * (N + 1));

	for (int i = 1; i <= N; i++) {
		path[i] = 0;
		visit[i] = 0;
	}
}

void fre(int flag) {
	if (flag == 1)
		free(queue);

	free(path);
	free(visit);
}

void addPath(int node) {
	path[p_index] = node;
	p_index++;
}

void printPath(int flag) {
	for (int i = 0; i < p_index - 1; i++) {
		printf("%d ", path[i]);
	}
	if (flag == 0)
		printf("%d\n", path[p_index - 1]);
	else
		printf("%d", path[p_index - 1]);
}

void push(int node) {
	queue[tail] = node;
	tail++;
}

int pop() {
	int ret = queue[head];
	head++;

	return ret;
}

void DFS(int node) {
	addPath(node);
	visit[node] = 1;

	for (int i = 1; i <= N; i++) {
		if (adj[node][i] == 1 && visit[i] == 0)
			DFS(i);
	}
}

void BFS(int node) {
	int cur;
	push(node);
	visit[node] = 1;

	while (head != tail) {
		cur = pop();
		addPath(cur);

		for (int i = 1; i <= N; i++) {
			if (adj[cur][i] == 1 && visit[i] == 0) {
				push(i);
				visit[i] = 1;
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &V);

	adj = (int**)malloc(sizeof(int*) * (N + 1));
	for (int i = 1; i <= N; i++)
		adj[i] = (int*)malloc(sizeof(int) * (N + 1));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			adj[i][j] = 0;
		}
	}

	for (int i = 0; i < M; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		adj[x][y] = 1;
		adj[y][x] = 1;
	}

	init(0);
	DFS(V);
	printPath(0);
	fre(0);

	init(1);
	BFS(V);
	printPath(1);
	fre(1);

	for (int i = 1; i <= N; i++)
		free(adj[i]);
	free(adj);
}