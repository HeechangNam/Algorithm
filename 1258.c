/* 한 칸씩 차례대로 봄.
** 보다가 0이 아닌 수를 만나면 그 수를 기준으로 해서 sub matrix가 몇 x 몇인지 계산
** 계산한 row_cnt, col_cnt의 값은 cnt[row_cnt] = col_cnt의 형태로 저장됨
** 그리고 해당 sub_matix를 matirx에서 지워버림(0으로 뒤덮음)
** 탐색을 계속함.
** sub_mat 행렬의 값을 토대로 sub_matrix가 몇개나 되는지 계산
** sub_mat[[i].row -> i's row; sub_mat[i].col = cnt[i's row]로 저장
** sub_mat를 time에 따라 정렬
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct{
	int row;
	int col;
	int size;
} sub_matrix;

void quickSort(sub_matrix* chem, int first, int last)
{
	int pivot;
	int i;
	int j;
	int temp;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;

		while (i < j)
		{
			while (chem[i].size <= chem[pivot].size && i < last)
			{
				i++;
			}
			while (chem[j].size > chem[pivot].size)
			{
				j--;
			}
			if (i < j)
			{
				temp = chem[i].size;
				chem[i].size = chem[j].size;
				chem[j].size = temp;

				temp = chem[i].col;
				chem[i].col = chem[j].col;
				chem[j].col = temp;

				temp = chem[i].row;
				chem[i].row = chem[j].row;
				chem[j].row = temp;
			}
		}

		temp = chem[pivot].size;
		chem[pivot].size = chem[j].size;
		chem[j].size = temp;

		temp = chem[pivot].col;
		chem[pivot].col = chem[j].col;
		chem[j].col = temp;

		temp = chem[pivot].row;
		chem[pivot].row = chem[j].row;
		chem[j].row = temp;

		quickSort(chem, first, j - 1);
		quickSort(chem, j + 1, last);
	}
}


int main() {

	int T;
	int t;
	int n;
	int i, j;

	int row_cnt = 0;
	int col_cnt = 0;

	int** mat;
	int* cnt;
	sub_matrix* sub_mat;

	int n_submat;

	scanf("%d", &T);
	for (t = 0; t < T; t++) {
		scanf("%d", &n);
		mat = (int**)malloc(sizeof(int*) * n);
		for (int i = 0; i < n; i++)
			mat[i] = (int*)malloc(sizeof(int) * n);
		cnt = (int*)malloc(sizeof(int) * n);
		for (int i = 0; i < n; i++)
			cnt[i] = 0;

		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				scanf("%d", &mat[i][j]);
			}
		}

		//mat 행렬 탐색
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				// sub matrix 확인
				if (mat[i][j] != 0) {
					//해당 sub matrix의 row, col 길이 계산
					int tempj = j;
					while (tempj < n && mat[i][tempj] != 0 ) {
						col_cnt++;
						tempj++;
					}
					int tempi = i;
					while (tempi < n && mat[tempi][j] != 0) {
						row_cnt++;
						tempi++;
					}
					//해당 sub matrix 덮기
					for (tempi = i; tempi < i + row_cnt; tempi++) {
						for (tempj = j; tempj < j + col_cnt; tempj++) {
							if (mat[tempi][tempj] == 0) {
								printf("Error!\n");
							}
							mat[tempi][tempj] = 0;
						}
					}
					//값 저장 및 초기화
					cnt[row_cnt] = col_cnt;
					row_cnt = 0; col_cnt = 0;
				}
			}
		}

		//submatrix의 갯수 계산
		n_submat = 0;
		for (i = 0; i < n; i++) {
			if (cnt[i] != 0)
				n_submat++;
		}
		//sub_mat 만들기
		sub_mat = (sub_matrix*)malloc(sizeof(sub_matrix) * n_submat);
		j = 0;
		for (i = 0; i < n; i++) {
			if (cnt[i] != 0) {
				sub_mat[j].row = i;
				sub_mat[j].col = cnt[i];
				sub_mat[j].size = sub_mat[j].row * sub_mat[j].col;
				j++;
			}
		}

		//정렬
		quickSort(sub_mat, 0, n_submat-1);

		printf("#%d %d", t + 1, n_submat);
		for (i = 0; i < n_submat; i++) {
			printf(" %d %d", sub_mat[i].row, sub_mat[i].col);
		}
		printf("\n");
		
		for (int i = 0; i < n; i++)
			free(mat[i]);
		free(mat);
		free(cnt);
		free(sub_mat);
	}

	

	return 0;
}