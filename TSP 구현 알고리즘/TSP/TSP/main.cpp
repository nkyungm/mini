#include <stdio.h>
#include<stdlib.h>
#include<math.h>

void travel(int n, const int** W, int** P, int& minlength)
{
	int i, j, k; //인덱스
	int Not_A;
	int** D;
	D = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		D[i] = (int*)malloc(sizeof(int) * (int)(pow((double)2, (double)n)));
	}

	for (i = 1; i < n; i++){
		D[i][0] = W[i][0]; //노드를 거치지 않는 경우
	}

	for (k = 1; k <= n - 2; k++) {

		for (int A = 1; A <= pow(2, n); A++) {
			if (Count1(A) != k)
				continue;
			else {
				Not_A = (pow(2, n - 1)-1) - A;
				for (i = 1; i < n; i++) {
					D[i][A] = INT_MAX;
					if (Not_A & (1 << i) != 0) {
						for (j = 1; j < n; j++) {
							
							if (A & (1 << j) != 0) {
								if (D[i][A] > W[i][j] + D[j][A - (int)pow(2, j - 1)]) {
									P[i][A] = j;
								}
								D[i][A] = node_Min(D[i][A], W[i][j] + D[j][A-(int)pow(2,j-1)]);
							}
						}
						
					}
				}
			}
		}
	}
	for (j = 1; j < n; j++) {
		D[0][(int)pow(2, n - 1) - 1] = node_Min(D[0][(int)pow(2, n - 1) - 1],W[0][j] + D[j][((int)pow(2, n - 1) - 1)-((int)pow(2,j-1))]);

	}
	minlength = D[0][(int)pow(2, n - 1) - 1];
}

int Count1(int A) { //간선의 개수 세기(비트에서 1 개수 찾기)
	int k;
	for (k = 0; A != 0; k++) {
		A &= (A - 1);
	}
	return k;
}

int node_Min(int a, int b) {
	if (a < b)return a;
	else return b;
}

int main()
{
	printf("%d",Count1(10));
}