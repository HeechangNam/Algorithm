/*
adj[N][N]은 adjustmen list.
adj_cnt[N]은 list의 크기

프림 사용(min heap)
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int V, E;

#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct _node {
	int to;
	int weight;
}_node;
int* adj_cnt;
_node** adj;

typedef struct node {
	int node_num;
	int key;
}node;
node* min_heap;
long long r;
long long result;

int* visit;

int get_c_count(int current_index)
{
	if (((current_index * 2) + 1) <= r)
	{
		return 2;
	}
	else if ((current_index * 2) <= r)
	{
		return 1;
	}
	return 0;
}

void push(int got_node_num, int got_key)
{
	long long target_index;
	long long current_index;
	node temp;
	min_heap[++r].key = got_key;
	min_heap[r].node_num = got_node_num;
	current_index = r;
	target_index = current_index / 2;
	while (target_index >= 1 && min_heap[current_index].key < min_heap[target_index].key)
	{
		temp = min_heap[current_index];
		min_heap[current_index] = min_heap[target_index];
		min_heap[target_index] = temp;
		current_index = target_index;
		target_index = current_index / 2;
	}
}
node pop()
{
	int c_count;
	long long current_index;
	node result, lc, rc, temp;
	result = min_heap[1];
	min_heap[1] = min_heap[r--];
	current_index = 1;
	while (1)
	{
		c_count = get_c_count(current_index);
		if (c_count == 0)
		{
			break;
		}
		else if (c_count == 1)
		{
			lc = min_heap[(current_index * 2)];
			if (min_heap[current_index].key > lc.key)
			{
				temp = min_heap[current_index];
				min_heap[current_index] = lc;
				min_heap[current_index * 2] = temp;
				current_index *= 2;
			}
			else
			{
				break;
			}
		}
		else
		{
			lc = min_heap[(current_index * 2)];
			rc = min_heap[((current_index * 2) + 1)];
			if (lc.key < rc.key)
			{
				if (min_heap[current_index].key > lc.key)
				{
					temp = min_heap[current_index];
					min_heap[current_index] = lc;
					min_heap[current_index * 2] = temp;
					current_index *= 2;
				}
				else
				{
					break;
				}
			}
			else
			{
				if (min_heap[current_index].key > rc.key)
				{
					temp = min_heap[current_index];
					min_heap[current_index] = rc;
					min_heap[((current_index * 2) + 1)] = temp;
					current_index *= 2;
					current_index++;
				}
				else
				{
					break;
				}
			}
		}
	}
	return result;
}
int isempty()
{
	if (r == 0)
	{
		return 1;
	}
	return 0;
}

void prim(int start_node_num)
{
	int i, next_node, next_len;
	node pnode;

	for (int i = 1; i <= V; i++) {
		if (i == start_node_num)
			push(start_node_num, 0);
		else
			push(i, INT_MAX);
	}

	while (!(isempty()))
	{
		pnode = pop();

		if (visit[pnode.node_num] == WHITE) {
			result += pnode.key;
			for (i = 0; i < adj_cnt[pnode.node_num]; i++)
			{
				next_node = adj[pnode.node_num][i].to;
				next_len = adj[pnode.node_num][i].weight;

				if (visit[next_node] == WHITE) {
					push(next_node, next_len);
				}
				visit[pnode.node_num] = BLACK;
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
		scanf("%d %d", &V, &E);
		adj_cnt = (int*)malloc(sizeof(int) * (V + 1));
		adj = (_node**)malloc(sizeof(_node*) * (V + 1));
		min_heap = (node*)malloc(sizeof(node) * (V*V));
		visit = (int*)malloc(sizeof(int) * (V + 1));
		for (int i = 0; i <= V; i++) {
			adj_cnt[i] = 0;
			adj[i] = NULL;
			visit[i] = WHITE;
		}

		for (int i = 0; i < E; i++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);

			if (adj_cnt[u] == 0)
				adj[u] = (_node*)malloc(sizeof(_node));
			else
				adj[u] = (_node*)realloc(adj[u], sizeof(_node) * (adj_cnt[u] + 1));
			adj[u][adj_cnt[u]].to = v;
			adj[u][adj_cnt[u]].weight = w;
			adj_cnt[u]++;

			if (adj_cnt[v] == 0)
				adj[v] = (_node*)malloc(sizeof(_node));
			else
				adj[v] = (_node*)realloc(adj[v], sizeof(_node) * (adj_cnt[v] + 1));
			adj[v][adj_cnt[v]].to = u;
			adj[v][adj_cnt[v]].weight = w;
			adj_cnt[v]++;
		}

		result = 0;
		prim(1);

		printf("#%d %lld\n", test_case, result);

		free(adj_cnt);
		free(visit);
		for (int i = 0; i <= V; i++)
			free(adj[i]);
		free(adj);
		free(min_heap);
	}

	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}