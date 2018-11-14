/*
a문자열에서 b문자열을 걸러내야 한다!

a[i]와 b[top]가 같을때 push a[i+top]와 b[top]가 stack이 다 찰때까지 같으면 ans++하고 i를 i+top+1로 바꿈
					   push a[i+top]와 b[top]가 중간에 달라지면 stack을 비우고 i++한후 처음으로 돌아감
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* stack;
int top;
int stack_size;

int ans;
char A[10005];
int alen;
char B[105];

void push(char* stack, char c) {
	stack[top] = c;
	top++;
}

void pop(char* stack) {
	top--;
}

int isfull(char* stack) {
	return stack_size == top ? 1 : 0;
}

void init(char* stack) {
	top = 0;
}

int main() {
	
	int i, t, T;
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (t = 1; t <= T; t++) {
		scanf("%s %s", &A, &B);
		
		stack_size = strlen(B);
		alen = strlen(A);
		stack = (char*)malloc(sizeof(char) * stack_size);

		init(stack);
		ans = i = 0;
		while (i < alen) {
			if (A[i] == B[top]) {
				push(stack, A[i]);
				while (!isfull(stack)) {
					if (A[i + top] == B[top])
						push(stack, A[i + top]);
					else
						break;
				}
				if (isfull(stack)) {
					ans++;
					i = i + top;
					init(stack);
				}
				else {
					init(stack);
					i++;
					ans++;
				}

			}
			else {
				ans++;
				i++;
			}
		}
		free(stack);
		printf("#%d %d\n", t, ans);
	}

	return 0;
}