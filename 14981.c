/*
시뮬레이션 문제인듯.
톱니바퀴는 무조건 8칸, 4개.
4개의 길이가 8인 링크드리스트를 만들자. 회전이랑 12시 방향을 어떻게 표시할건지가 관건.
12시 방향을 가리키는 변수를 선언해서 이 변수를 ++, --시키면 이동.
*/

#include <stdio.h>
#include <stdlib.h>

#define N 0
#define S 1

#define CW 1
#define CCW -1

#define TRUE 1
#define FALSE 0

typedef struct node {
	int value;
	struct node* cw;
	struct node* ccw;
}node;

typedef struct instruct {
	int target;
	int dir;
}instruct;


node* wheel[5];
instruct* inst;

int K;
int ans;
int Tc[4];
int Nc[4];

void rotate(int target, int dir) {
	
	int left;
	int cur;
	int right;
	
	for (int i = 1; i < 4; i++)
		Tc[i] = wheel[i]->cw->cw->value;
	for (int i = 4; i > 1; i--)
		Nc[i] = wheel[i]->ccw->ccw->value;

	cur = target;
	left = cur - 1;
	while (left > 0) {
		if (Nc[cur] != Tc[left]) {
			if (dir == CW)
				wheel[left] = wheel[left]->ccw;
			else
				wheel[left] = wheel[left]->c
		}
	}
	
	right = target + 1;

}

int main() {
	char c;

	for (int i = 1; i < 5; i++) {
		node* first = NULL;
		for (int j = 0; j < 8; j++) {
			if (j == 0) {
				node* temp = (node*)malloc(sizeof(node));
				scanf("%c", &c);
				temp->value = c - '0';
				temp->cw = NULL;
				temp->ccw = NULL;
				wheel[i] = temp;
				first = temp;
			}

			else if (j == 7) {
				node* temp = (node*)malloc(sizeof(node));
				scanf("%c", &c);
				temp->value = c - '0';
				temp->cw = first;
				temp->ccw = wheel[i];
				wheel[i]->cw = temp;
				first->ccw = temp;
				wheel[i] = first;
			}
			else {
				node* temp = (node*)malloc(sizeof(node));
				scanf("%c", &c);
				temp->value = c - '0';
				temp->cw = NULL;
				temp->ccw = wheel[i];
				wheel[i]->cw = temp;
				wheel[i] = temp;
			}
		}
		scanf("%c", &c);
	}

	scanf("%d", &K);

	inst = (instruct*)malloc(sizeof(instruct) * K);
	for (int i = 0; i < K; i++)
		scanf("%d %d", &inst[i].target, &inst[i].dir);

	for (int i = 0; i < K; i++)
		rotate(inst[i].target, inst[i].dir);


	ans = 0;
	for (int i = 1; i < 5; i++) {
		if (wheel[i]->value == S)
			ans += i * 2;
	}
	printf("%d\n", ans);

	for (int i = 1; i < 5; i++) {
		for (int j = 0; j < 8; j++) {
			node* temp;
			temp = wheel[i];
			wheel[i] = temp->cw;
			free(temp);
		}
	}

	return 0;
}