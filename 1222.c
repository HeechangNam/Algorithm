#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char value;
	int result;
	struct node* l_child;
	struct node* r_child;
	struct node* parent;
}node;

int postfix(node* temp) {
	if (temp->l_child != NULL)
		postfix(temp->l_child);

	if (temp->r_child != NULL)
		postfix(temp->r_child);

	if (temp->value == '+') {
		temp->result = temp->l_child->result + temp->r_child->result;
		free(temp->l_child);
		free(temp->r_child);
	}
	else
		temp->result = temp->value - '0';
	return 0;
}

int main() {
	int t, T;
	char* buff;
	int i, n;
	char c;

	node* root = NULL;
	node* temp = NULL;

	
	T = 10;
	for (t = 0; t < T; t++) {
		scanf("%d", &n);
		buff = (char*)malloc(sizeof(char) * (n + 1));
		scanf("%s", buff);

		for (i = 0; i < n; i++) {
			c = buff[i];
			temp = (node*)malloc(sizeof(node));
			temp->l_child = NULL;
			temp->r_child = NULL;
			temp->parent = NULL;
			temp->value = c;
			temp->result = -1;

			if (c == '+') {
				root->parent = temp;
				temp->l_child = root;
				root = temp;
			}
			else {
				if (root == NULL)
					root = temp;
				else {
					root->r_child = temp;
					temp->parent = root;
				}
			}
		}

		postfix(root);

		printf("#%d %d\n", t + 1, root->result);

		free(buff);
		free(root);
		root = NULL;
	}
}