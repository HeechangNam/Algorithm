#include <stdio.h>


#define WHITE 7
#define BLACK 8
#define GRAY 9

int adj[100][2];
int color[100];
int queue[100];

int back;
int front;



void inqueue(int node) {
	queue[back++] = node;	
	color[node] = GRAY;
}

int dequeue() {
	int result = queue[front];
	
	color[queue[front]] = BLACK;
	front++;

	return result;
}

int main() {
	int t;
	int T = 10;
	int e;
	int num_edge;
	int N;
	int ans;
	int s, d;
	int i;
	int cur_node;

	for (t = 0; t < T; t++) {
		scanf("%d %d", &N, &num_edge);

		front = 0; back = 0;
		for (i = 0; i < 100; i++) {
			color[i] = WHITE;
			adj[i][0] = -1; adj[i][1] = -1;
		}

		for (e = 0; e < num_edge; e++) {
			scanf("%d %d", &s, &d);

			if (adj[s][0] == -1)
				adj[s][0] = d;
			else
				adj[s][1] = d;
		}

		inqueue(0);
		cur_node = dequeue();
			
		while (cur_node != 99) {
			for (i = 0; i < 2; i++) {
				if ((adj[cur_node][i] != -1) && (color[adj[cur_node][i]] == WHITE))
					inqueue(adj[cur_node][i]);

			}
				
			if (front != back)
				cur_node = dequeue();
			else
				break;
		}

		if (cur_node == 99)
			ans = 1;
		else
			ans = 0;

		printf("#%d %d\n", t + 1, ans);
	}
}