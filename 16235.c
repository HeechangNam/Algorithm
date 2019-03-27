#include <stdio.h>
#include <stdlib.h>

int** A;
int N, M, K;

/*
각 땅에 대한 나무들의 나이가 저장될 리스트
이 리스트의 각 노드들은 나이에 따른 오름차순으로 항상 정렬되어 있어야한다.
*/
typedef struct tree {
	int age;
	struct tree *next;
}tree;


//각 땅에 대한 정보를 저장
typedef struct land {
	int nuriment;
	int cnt_tree;
	tree *death;
	tree *htrees;
}land;

land** lands;

/*
땅의 r,c 값과 심을 나무의 나이값을 받아
해당 땅의 나무리스트의 적절한 자리에 넣어준다.
*/
void addTree(int r, int c, int age) {
	tree *addNode;
	tree *cur;
	tree *nextnode;
	addNode = (tree*)malloc(sizeof(tree));
	addNode->age = age;
	addNode->next = NULL;
	lands[r][c].cnt_tree++;

	cur = lands[r][c].htrees;
	while (cur->next != NULL && cur->next->age < age) cur = cur->next;
	
	if (cur->next == NULL)
		nextnode = NULL;
	else
		nextnode = cur->next;

	cur->next = addNode;
	addNode->next = nextnode;

	
}
/*
trees 리스트의 처음부터 나이만큼 양분을 뺀다. 그리고 나이를 1 더한다.
flag가 1 -> 흡수 가능, 0 -> 흡수 불가능
특정 나무의 나이가 땅의 양분보다 크면 flag를 0으로 바꾸고 death가 해당 나무를 가리키게 된다.
*/
void spring() {
	int cnt, flag;
	tree *cur;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			flag = 1;
			cnt = 0;
			cur = lands[i][j].htrees;
			while (flag == 1 && cur->next != NULL) {
				if (lands[i][j].nuriment >= cur->next->age) {
					lands[i][j].nuriment = lands[i][j].nuriment-cur->next->age;
					cur->next->age++;
					cur = cur->next;
					cnt++;
				}
				else {
					flag = 0;
					lands[i][j].death = cur->next;
					lands[i][j].cnt_tree = cnt;
					cur->next = NULL;
				}
			}
		}
	}
}

/*
death가 가리킨 나무부터 해당 나이의 절반만큼 양분이 되고 free해줌.
*/
void summer() {
	tree* temp;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			while(lands[i][j].death != NULL) {
				lands[i][j].nuriment += (lands[i][j].death->age) / 2;
				temp = lands[i][j].death->next;
				free(lands[i][j].death);
				lands[i][j].death = temp;
			}
		}
	}
}

/*
나이가 5의 배수인 나무가 있으면 가능한 주위의 영역마다 나이가 1인 나무를 심는다.
*/
void fall() {
	tree *cur;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cur = lands[i][j].htrees;
			while (cur->next != NULL) {
				if ((cur->next->age) % 5 == 0) {
					if (i != 1)
						addTree(i - 1, j, 1);
					if (j != 1)
						addTree(i, j - 1, 1);
					if (i != 1 && j != 1)
						addTree(i - 1, j - 1, 1);
					if (i != N)
						addTree(i + 1, j, 1);
					if (j != N)
						addTree(i, j + 1, 1);
					if (i != N && j != N)
						addTree(i + 1, j + 1, 1);
					if (i != 1 && j != N)
						addTree(i - 1, j + 1, 1);
					if (i != N && j != 1)
						addTree(i + 1, j - 1, 1);
				}
				cur = cur->next;
			}
		}
	}
}

/*
땅에다가 해당 양분을 더해준다.
*/
void winter() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			lands[i][j].nuriment += A[i][j];
		}
	}
}

int main() {

	int ans;

	scanf("%d %d %d", &N, &M, &K);

	A = (int**)malloc(sizeof(int*) * (N + 2));
	lands = (land**)malloc(sizeof(land*) * (N + 2));
	for (int i = 0; i <= N+1; i++) {
		A[i] = (int*)malloc(sizeof(int) * (N + 2));
		lands[i] = (land*)malloc(sizeof(land) * (N + 2));
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &A[i][j]);


			lands[i][j].cnt_tree = 0;
			lands[i][j].death = NULL;
			lands[i][j].htrees = (tree*)malloc(sizeof(tree));
			lands[i][j].htrees->age = 0;
			lands[i][j].htrees->next = NULL;
			lands[i][j].nuriment = 5;
		}
	}

	for (int i = 0; i < M; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		addTree(x, y, z);
	}

	for (int i = 0; i < K; i++) {
		spring();
		summer();
		fall();
		winter();
	}

	ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans += lands[i][j].cnt_tree;
		}
	}

	printf("%d\n", ans);
}