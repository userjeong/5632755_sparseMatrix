#include<stdio.h>
#include<stdlib.h>
#define MAX_TERMS 101

typedef struct {
	int row;
	int col;
	int value;
}element; //행렬에서 각각의 요소를 element

typedef struct SparseMatrix {
	element data[MAX_TERMS];
	int rows; //행의 개수
	int cols; //열의 개수
	int terms; //항목 개수(0이 아닌 항목의 개수)
}SparseMatrix;

SparseMatrix matrix_transpose2(SparseMatrix a)
{
	SparseMatrix b;
	int bindex; //행렬 b에서 현재 저장 위치
	b.rows = a.rows;
	b.cols = a.cols;
	b.terms = a.terms;
	if (a.terms > 0) {
		bindex = 0;
		for (int c = 0; c < a.cols; c++) { //0, 1,2,3,4,5...증가구문{
			for (int i = 0; i < a.terms; i++) //0이 아닌 항목 찾기. 9가 (1,0)과 같으면 (0,1)로 바꿔서 옮김
			{
				if (a.data[i].col == c) {
					b.data[bindex].row = a.data[i].col;
					b.data[bindex].col = a.data[i].row;
					b.data[bindex].value = a.data[i].value;
					bindex++;
				}
			}
		}
	}
	return b;
}

void matrix_print(SparseMatrix a)
{
	printf("=======================\n");
	for (int i = 0; i < a.terms; i++)
	{
		printf("(%d, %d, %d)\n", a.data[i].row, a.data[i].col, a.data[i].value);
	}
	printf("=======================\n");
}

int main(void)
{
	SparseMatrix* p;
	p = (SparseMatrix*)malloc(sizeof(SparseMatrix));
	if (p == NULL) {
		fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다.\n");
		exit(1);
	}

	scanf("%d %d %d", &p->rows, &p->cols, &p->terms);
	SparseMatrix m = {
		{{0,3,7}, {1,0,9},{1,5,8},{3,0,6},{3,1,5},{4,5,1},{5,2,2}},
		6, //rows
		6, //cols
		7 //terms
	};

	SparseMatrix result;
	result = matrix_transpose2(m);
	matrix_print(result);
	return 0;
}