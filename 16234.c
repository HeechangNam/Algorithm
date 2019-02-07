#include <stdio.h>
#include <stdlib.h>

#define WHITE 0
#define BLACK 1


typedef struct cell {
	int r;
	int c;
}cell;

int N, L, R;
int aray[50][50];
int visited[50][50];
cell queue[2505];
int head, tail;
cell stack[2505];
int top;

int flag;
int sum;
int cnt;
int avg;

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = WHITE;
		}
	}
	head = 0;
	tail = 0;
	top = 0;
}

void add(int r, int c) {
	if (head > 2505) {
		exit(1);
	}

	queue[head].r = r;
	queue[head].c = c;
	head++;
}

int queue_empty() {
	if (tail == head)
		return 1;
	else
		return 0;
}

cell del() {
	cell temp;

	if (queue_empty()) {
		exit(1);
	}
	
	temp.r = queue[tail].r;
	temp.c = queue[tail].c;
	tail++;
	
	return temp;
}


void push(int r, int c) {
	if (top > 2505) {
		exit(1);
	}

	stack[top].r = r;
	stack[top].c = c;
	top++;
}

cell pop() {
	cell temp;

	if (top < 0) {
		exit(1);
	}

	top--;
	temp.r = stack[top].r;
	temp.c = stack[top].c;
	
	return temp;
}

int stack_empty() {
	if (top == 0) {
		return 1;
	}
	else
		return 0;
}

int minus(int a1, int a2) {
	if (a1 >= a2)
		return a1 - a2;
	else if (a1 < a2)
		return a2 - a1;
	else
		return 0;
}

void move() {
	avg = sum / cnt;

	while (!stack_empty()) {
		cell temp = pop();
		aray[temp.r][temp.c] = avg;
	}
}

void BFS(int start_i, int start_j) {
	cell cur;
	int temp;

	add(start_i, start_j);
	visited[start_i][start_j] = BLACK;
	sum = 0;
	cnt = 0;

	while (!queue_empty()) {
		cur = del();
		push(cur.r, cur.c);
		sum += aray[cur.r][cur.c];
		cnt++;

		if (cur.r != 0) {
			temp = minus(aray[cur.r][cur.c], aray[cur.r - 1][cur.c]);
			if (temp >= L && temp <= R && visited[cur.r-1][cur.c] == WHITE) {
				add(cur.r - 1, cur.c);
				visited[cur.r - 1][cur.c] = BLACK;
				flag = 1;
			}		
		}

		if (cur.c != 0) {
			temp = minus(aray[cur.r][cur.c], aray[cur.r][cur.c - 1]);
			if (temp >= L && temp <= R && visited[cur.r][cur.c-1] == WHITE) {
				add(cur.r, cur.c - 1);
				visited[cur.r][cur.c - 1] = BLACK;
				flag = 1;
			}	
		}

		if (cur.r != N - 1) {
			temp = minus(aray[cur.r][cur.c], aray[cur.r + 1][cur.c]);
			if (temp >= L && temp <= R && visited[cur.r+1][cur.c] == WHITE) {
				add(cur.r + 1, cur.c);
				visited[cur.r + 1][cur.c] = BLACK;
				flag = 1;
			}
		}

		if (cur.c != N - 1) {
			temp = minus(aray[cur.r][cur.c], aray[cur.r][cur.c + 1]);
			if (temp >= L && temp <= R && visited[cur.r][cur.c+1] == WHITE) {
				add(cur.r, cur.c + 1);
				visited[cur.r][cur.c + 1] = BLACK;
				flag = 1;
			}
		}
	}

	move();
}

int main() {
	int ans;


	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &N, &L, &R);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &aray[i][j]);
		}
	}

	ans = 0;
	flag = 1;
	while (flag == 1) {
		flag = 0;
		init();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] == WHITE) {
					BFS(i, j);
				}
			}
		}

		if (flag == 1)
			ans++;
	}

	printf("%d\n", ans);
}