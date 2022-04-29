#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#define VERTEX_LEN 12

int Count1(int A) { //간선의 개수 세기(비트에서 1 개수 찾기)
	int c=0;
	for (int j = 0; j < VERTEX_LEN - 1; j++) {
		if ((A & (1 << j )) != 0)
			c++;
	}
	return c;
}

int node_Min(int a, int b) {
	if (a < b)return a;
	else return b;
}

void travel(int n, const int(*W)[VERTEX_LEN], int ***P, int& minlength)
{
	int i = 0, j = 0, k = 0; //인덱스
	int Not_A;
	int wd;
	int** D;
	D = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		D[i] = (int*)malloc(sizeof(int) * (int)(pow((double)2, (double)n - 1)));
	}

	for (i = 0; i < n; i++) {
		D[i][0] = W[i][0]; //노드를 거치지 않는 경우
		(*P)[i][0] = 0;
	}

	for (k = 1; k <= n - 2; k++) {

		for (int A = 1; A < pow(2, n - 1); A++) {
			if (Count1(A) != k)
				continue;
			else {
				Not_A = (pow(2, n - 1) - 1) - A;
				for (i = 1; i < n; i++) {
					D[i][A] = INT_MAX;
					if ((Not_A & (1 << (i - 1))) != 0) {
						for (j = 1; j < n; j++) {

							if ((A & (1 << (j - 1))) != 0) {
								wd = W[i][j] + D[j][A - (int)pow(2, j - 1)];
								if (wd < 0)
									wd = INT_MAX;
								if (D[i][A] > wd) {
									(*P)[i][A] = j;
								}
								D[i][A] = node_Min(D[i][A], wd);
							}
						}

					}
				}
			}
		}
	}
	D[0][(int)pow(2, n - 1) - 1] = INT_MAX;

	for (j = 1; j < n; j++) {
		wd = W[0][j] + D[j][((int)pow(2, n - 1) - 1) - ((int)pow(2, j - 1))];
		if (wd < 0)
			wd = INT_MAX;
		if (D[0][(int)pow(2, n - 1) - 1] > wd) {
			(*P)[0][(int)pow(2, n - 1) - 1] = j;
		}
		D[0][(int)pow(2, n - 1) - 1] = node_Min(D[0][(int)pow(2, n - 1) - 1], wd);
	}
	minlength = D[0][(int)pow(2, n - 1) - 1];

	for (int i = 0; i < n; i++)
	{
		free(D[i]);
	}
	free(D);
}

int main()
{
	int minlength = 0;
	int j=0,A=0;
	int start;

	printf("< TSP 일주 경로 구하기 >\n");
	printf("출발지 : 1(대구), 2(서울) => ");
	scanf("%d", &start);
	if (start == 1) {
		int W[VERTEX_LEN][VERTEX_LEN] =
		{//0(대구), 1(광주), 2(부산), 3(울산), 4(대전), 5(울진), 6(천안), 7(청주), 8(동해), 9(인천), 10(서울), 11(강릉)
			{0,INT_MAX,1,2,6,INT_MAX,INT_MAX,6,INT_MAX,INT_MAX,INT_MAX,INT_MAX},
			{6,0,5,INT_MAX,3,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX},
			{INT_MAX,4,0,3,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,},
			{INT_MAX,INT_MAX,2,0,INT_MAX,1,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX},
			{3,3,INT_MAX,INT_MAX,0,5,5,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX},
			{3,INT_MAX,INT_MAX,3,5,0,INT_MAX,2,3,INT_MAX,INT_MAX,INT_MAX},
			{INT_MAX,INT_MAX,INT_MAX,INT_MAX,4,INT_MAX,0,4,INT_MAX,3,INT_MAX,INT_MAX},
			{INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,2,3,0,1,INT_MAX,13,INT_MAX},
			{INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,5,INT_MAX,2,0,INT_MAX,INT_MAX,5},
			{INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,1,INT_MAX,INT_MAX,0,7,INT_MAX},
			{INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,8,INT_MAX,3,0,5},
			{INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,3,INT_MAX,3,0}
		};
		
		int** P;
		P = (int**)malloc(sizeof(int*) * VERTEX_LEN);
		for (int i = 0; i < VERTEX_LEN; i++) {
			P[i] = (int*)malloc(sizeof(int) * (int)(pow((double)2, (double)VERTEX_LEN - 1)));
		}

		travel(VERTEX_LEN, W, &P, minlength);

		printf("0(대구), 1(광주), 2(부산), 3(울산), 4(대전), 5(울진), 6(천안), 7(청주), 8(동해), 9(인천), 10(서울), 11(강릉)\n");
		printf("최단 거리: %d\n", minlength);
		printf("경로: % d ", 0);
		A = (pow(2, VERTEX_LEN - 1) - 1);

		for (int i = 0; i < VERTEX_LEN; i++) {
			printf("-> ");
			printf("%d ", P[j][A]);
			j = P[j][A];
			A = A - (int)pow(2, j - 1);

		}
		for (int i = 0; i < VERTEX_LEN; i++)
		{
			free(P[i]);
		}
		free(P);
	}
	
	if (start == 2) {
		int W[VERTEX_LEN][VERTEX_LEN] =
		{//0(서울), 1(광주), 2(부산), 3(울산), 4(대전), 5(울진), 6(천안), 7(청주), 8(동해), 9(인천), 10(대구), 11(강릉)
			{0,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,8,INT_MAX,3,INT_MAX,5},
			{INT_MAX,0,5,INT_MAX,3,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,6,INT_MAX},
			{INT_MAX,4,0,3,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,},
			{INT_MAX,INT_MAX,2,0,INT_MAX,1,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX},
			{INT_MAX,3,INT_MAX,INT_MAX,0,5,5,INT_MAX,INT_MAX,INT_MAX,3,INT_MAX},
			{INT_MAX,INT_MAX,INT_MAX,3,5,0,INT_MAX,2,3,INT_MAX,3,INT_MAX},
			{INT_MAX,INT_MAX,INT_MAX,INT_MAX,4,INT_MAX,0,4,INT_MAX,3,INT_MAX,INT_MAX},
			{13,INT_MAX,INT_MAX,INT_MAX,INT_MAX,2,3,0,1,INT_MAX,INT_MAX,INT_MAX},
			{INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,5,INT_MAX,2,0,INT_MAX,INT_MAX,5},
			{7,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,1,INT_MAX,INT_MAX,0,INT_MAX,INT_MAX},
			{INT_MAX,INT_MAX,1,2,6,INT_MAX,INT_MAX,6,INT_MAX,INT_MAX,0,INT_MAX},
			{3,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,3,INT_MAX,INT_MAX,0}
		};
		
		int** P;
		P = (int**)malloc(sizeof(int*) * VERTEX_LEN);
		for (int i = 0; i < VERTEX_LEN; i++) {
			P[i] = (int*)malloc(sizeof(int) * (int)(pow((double)2, (double)VERTEX_LEN - 1)));
		}

		travel(VERTEX_LEN, W, &P, minlength);

		printf("0(서울), 1(광주), 2(부산), 3(울산), 4(대전), 5(울진), 6(천안), 7(청주), 8(동해), 9(인천), 10(대구), 11(강릉)\n");
		printf("최단 거리: %d\n", minlength);
		printf("경로: % d ", 0);
		A = (pow(2, VERTEX_LEN - 1) - 1);

		for (int i = 0; i < VERTEX_LEN; i++) {
			printf("-> ");
			printf("%d ", P[j][A]);
			j = P[j][A];
			A = A - (int)pow(2, j - 1);

		}

		for (int i = 0; i < VERTEX_LEN; i++)
		{
			free(P[i]);
		}
		free(P);
	}
}