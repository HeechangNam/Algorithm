/*
adj[N][N]은 adjustment array
dist[N]은 N까지 가는 최소한의 거리

다익스트라 사용(BFS)
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define WHITE 1 
#define GRAY 2
#define BLACK 3

typedef struct _node {
	int to;
	int cost;
}_node;

typedef struct node {
	int node_num;
	long long current_cost;
}node;
_node** adj;
node* min_heap;
long long* dist;
int* visit;
int* adj_cnt;
int N, M, S, D;
int r;

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

void push(int got_node_num, long long got_current_cost)
{
	int target_index, current_index;
	node temp;
	min_heap[++r].current_cost = got_current_cost;
	min_heap[r].node_num = got_node_num;
	current_index = r;
	target_index = current_index / 2;
	while (target_index >= 1 && min_heap[current_index].current_cost < min_heap[target_index].current_cost)
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
	int c_count, current_index;
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
			if (min_heap[current_index].current_cost > lc.current_cost)
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
			if (lc.current_cost < rc.current_cost)
			{
				if (min_heap[current_index].current_cost > lc.current_cost)
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
				if (min_heap[current_index].current_cost > rc.current_cost)
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

void di(int start_node_num)
{
	int i, next_node, next_len;
	node pnode;
	dist[start_node_num] = 0;
	push(start_node_num, 0);
	while (!(isempty()))
	{
		pnode = pop();
		for (i = 0; i < adj_cnt[pnode.node_num]; i++)
		{
			next_node = adj[pnode.node_num][i].to;
			next_len = adj[pnode.node_num][i].cost;
			if (dist[next_node] > dist[pnode.node_num] + next_len)
			{
				dist[next_node] = dist[pnode.node_num] + next_len;
				push(next_node, dist[next_node]);
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
		scanf("%d %d %d %d", &N, &M, &S, &D);
		dist = (long long*)malloc(sizeof(long long)*(N+1));
		adj = (_node**)malloc(sizeof(_node*)*(N+1));
		visit = (int*)malloc(sizeof(int) * (N + 1));
		adj_cnt = (int*)malloc(sizeof(int) * (N + 1));
		min_heap = (node*)malloc(sizeof(node) * 100005);
		for (int i = 1; i <= N; i++) {
			dist[i] = LLONG_MAX;
			visit[i] = WHITE;
			adj_cnt[i] = 0;
			adj[i] = NULL;
		}

		for (int i = 0; i < M; i++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			
			if (adj_cnt[u] == 0)
				adj[u] = (_node*)malloc(sizeof(_node));
			else 
				adj[u] = (_node*)realloc(adj[u],sizeof(_node)*(adj_cnt[u]+1));

			adj[u][adj_cnt[u]].to = v;
			adj[u][adj_cnt[u]].cost = w;
			adj_cnt[u]++;

			if (adj_cnt[v] == 0)
				adj[v] = (_node*)malloc(sizeof(_node));
			else
				adj[v] = (_node*)realloc(adj[v], sizeof(_node)*(adj_cnt[v]+1));
			adj[v][adj_cnt[v]].to = u;
			adj[v][adj_cnt[v]].cost = w;
			adj_cnt[v]++;
		}

		di(S);

		printf("#%d %lld\n", test_case, dist[D]);

		free(visit);
		free(dist);
		free(adj_cnt);
		for (int i = 1; i < N+1; i++)
			free(adj[i]);
		free(adj);
		free(min_heap);

	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}