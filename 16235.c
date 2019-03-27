#include <stdio.h>
#include <stdlib.h>

int** A;
int N, M, K;

/*
�� ���� ���� �������� ���̰� ����� ����Ʈ
�� ����Ʈ�� �� ������ ���̿� ���� ������������ �׻� ���ĵǾ� �־���Ѵ�.
*/
typedef struct tree {
	int age;
	struct tree *next;
}tree;


//�� ���� ���� ������ ����
typedef struct land {
	int nuriment;
	int cnt_tree;
	tree *death;
	tree *htrees;
}land;

land** lands;

/*
���� r,c ���� ���� ������ ���̰��� �޾�
�ش� ���� ��������Ʈ�� ������ �ڸ��� �־��ش�.
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
trees ����Ʈ�� ó������ ���̸�ŭ ����� ����. �׸��� ���̸� 1 ���Ѵ�.
flag�� 1 -> ��� ����, 0 -> ��� �Ұ���
Ư�� ������ ���̰� ���� ��к��� ũ�� flag�� 0���� �ٲٰ� death�� �ش� ������ ����Ű�� �ȴ�.
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
death�� ����Ų �������� �ش� ������ ���ݸ�ŭ ����� �ǰ� free����.
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
���̰� 5�� ����� ������ ������ ������ ������ �������� ���̰� 1�� ������ �ɴ´�.
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
�����ٰ� �ش� ����� �����ش�.
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