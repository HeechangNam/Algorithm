/* 그래프와 bfs를 이용해서 풀어보자.
** n이 들어오면 (n+1)x(n+1)의 배열을 만들고 얘는 adjMatrix임
** 합연산이 들어오면 a와 b사이에 edge를 연결해줌
** 같은 집합에 포함되어 있는지를 찾는 연산은 a를 기준으로 bfs 탐색을 해서 b가 있는지 확인
*/

#include <stdio.h>
#include <stdlib.h>


int** adjMat;
int n, m;

int* visit;
int* queue;
int rear, front;

int breadthFirstSearch(int vertex, int target)
{
	int i;
	int flag = 0;

	visit[vertex] = 1;
	queue[rear++] = vertex;
	while (front < rear)
	{

		vertex = queue[front++];
		if (vertex == target) {
			flag = 1;
			break;
		}
			
		for (i = 1; i <= n; i++)
		{
			if (adjMat[vertex][i] == 1 && !visit[i])
			{
				visit[i] = 1;
				queue[rear++] = i;
			}
		}
	}

	return flag;
}

int main() {

	int t, T;
	int a, b, opt;
	int flag;

	scanf("%d", &T);
	for (t = 0; t < T; t++) {
		scanf("%d %d", &n, &m);
		printf("#%d ", t + 1);
		adjMat = (int**)malloc(sizeof(int*) * (n + 1));
		for (int i = 0; i <= n; i++)
			adjMat[i] = (int*)malloc(sizeof(int) * (n + 1));

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				adjMat[i][j] = 0;
			}
		}

		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &opt, &a, &b);
			
			//합연산일때
			if (opt == 0) {
				//edge 연결
				adjMat[a][b] = 1;
				adjMat[b][a] = 1;
			}
			//같은 집합인지 확인하는 연산일때
			else if (opt == 1) {
				visit = (int*)malloc(sizeof(int) * (n + 1));
				queue = (int*)malloc(sizeof(int) * (n + 1));
				for (int i = 0; i <= n; i++) {
					visit[i] = 0;  queue[i] = 0;
				}

				front = 0;  rear = 0;
				flag = breadthFirstSearch(a,b);
				printf("%d", flag);

				free(visit);
				free(queue);
			}
			else {
				printf("error!\n");
				printf("%d번째 TestCase에서 %d번째 연산\n", t + 1, m + 1);
			}
		}

		for (int i = 0; i <= n; i++)
			free(adjMat[i]);
		free(adjMat);
		printf("\n");
	}

	return 0;
}