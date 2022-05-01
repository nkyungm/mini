/*
 < TSP �˰��� �����ϱ� >
 - �ۼ��� : �����
 - �й� : 22012198
 - ��¥ : 2022-04-30
*/
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#define VERTEX_LEN 12 //������ �� ����

int Count1(int A) { //������ ���� ����(��Ʈ���� 1 ���� ã��)
	int c=0; //���� ���� ����
	for (int j = 0; j < VERTEX_LEN - 1; j++) { //������ �� ���� -1 ��ŭ �ݺ�
		if ((A & (1 << j )) != 0) //1�� j��ŭ �������� shift�ϰ� A�� &������ ����� 0���� �ƴ��� Ȯ��
			c++; //0�� �ƴϸ� ���� +1
	}
	return c; //�� 1�� ���� ��ȯ
}

int node_Min(int a, int b) { //�ּڰ� �Ǵ��ϴ� �Լ�
	if (a < b)return a;
	else return b;
}

void travel(int n, const int(*W)[VERTEX_LEN], int ***P, int& minlength) //TSP �ִܰŸ� ���ϴ� �Լ�
{
	int i = 0, j = 0, k = 0; //�ε���
	int Not_A; 
	int wd; 
	int** D;
	D = (int**)malloc(sizeof(int*) * n); //2�����迭 �����Ҵ�
	for (int i = 0; i < n; i++) {
		D[i] = (int*)malloc(sizeof(int) * (int)(pow((double)2, (double)n - 1)));
	}

	for (i = 0; i < n; i++) {
		D[i][0] = W[i][0]; //�߰��� ��带 ��ġ�� �ʴ� ���
		(*P)[i][0] = 0; //P[i][0]�� i�� �����ϴ� ù��° �ε��� 0�̹Ƿ� 0���� ä����
	}

	for (k = 1; k <= n - 2; k++) { // k: �߰��� ��ġ�� ������ ����

		for (int A = 1; A < pow(2, n - 1); A++) { //A: ��ġ�� ������ ����(2�� n-1�±��� �ݺ��� ����)
			if (Count1(A) != k) //������ ������ A�� 1�� ������ �������� Ȯ��
				continue; //���� �ʴٸ� continue;
			else { //������ ������ A�� 1�� ������ ���ٸ�
				Not_A = (pow(2, n - 1) - 1) - A; //Not_A : A�� ���Ե��� ���� ���� ã�� ����
				for (i = 1; i < n; i++) {
					D[i][A] = INT_MAX; //�ʱ�ȭ
					if ((Not_A & (1 << (i - 1))) != 0) { //Not_A���� �ش� ������ 1�̶��
						for (j = 1; j < n; j++) { //����� ������ŭ �ݺ�

							if ((A & (1 << (j - 1))) != 0) {//A���� �ش� ������ 1�̶��
								wd = W[i][j] + D[j][A - (int)pow(2, j - 1)]; //�Ÿ� ���
								if (wd < 0) //�Ÿ��� INT_MAX���� �ٸ� ���� ������ �����÷ο� �߻��ؼ� ������ �ٲ�
									wd = INT_MAX; //INT_MAX�� ��������
								if (D[i][A] > wd) { //wd�� �Ÿ��� �� ������
									(*P)[i][A] = j; //P[i][A]�� Vi�� �����ϴ� ù�� ° ����� �ε����� j �־���
								}
								D[i][A] = node_Min(D[i][A], wd); //ũ�� ���ؼ� �ּڰ� �־���
							}
						}

					}
				}
			}
		}
	}
	D[0][(int)pow(2, n - 1) - 1] = INT_MAX; //�ʱ�ȭ

	for (j = 1; j < n; j++) { 
		wd = W[0][j] + D[j][((int)pow(2, n - 1) - 1) - ((int)pow(2, j - 1))]; //�Ÿ� ���
		if (wd < 0) //�Ÿ��� INT_MAX���� �ٸ� ���� ������ �����÷ο� �߻��ؼ� ������ �ٲ�
			wd = INT_MAX; //INT_MAX�� �������� 
		if (D[0][(int)pow(2, n - 1) - 1] > wd) { //wd�� �Ÿ��� �� ������
			(*P)[0][(int)pow(2, n - 1) - 1] = j; //P[0][(int)pow(2, n - 1) - 1]�� 0�� �����ϴ� ù�� ° ����� �ε����� j �־���
		}
		D[0][(int)pow(2, n - 1) - 1] = node_Min(D[0][(int)pow(2, n - 1) - 1], wd);  //ũ�� ���ؼ� �ּڰ� �־���
	}
	minlength = D[0][(int)pow(2, n - 1) - 1]; //V0���� �ٽ� ���ƿ��� �ִܰŸ� ����

	for (int i = 0; i < n; i++) //2���� �迭 �����Ҵ� ����
	{
		free(D[i]);
	}
	free(D);
}

int main()
{
	int minlength = 0; //�ִܰŸ�
	int j=0,A=0;
	int start;

	printf("< TSP ���� ��� ���ϱ� >\n");
	printf("����� : 1(�뱸), 2(����) => ");
	scanf("%d", &start);

	if (start == 1) { //������� �뱸�϶�
		int W[VERTEX_LEN][VERTEX_LEN] =
		{//0(�뱸), 1(����), 2(�λ�), 3(���), 4(����), 5(����), 6(õ��), 7(û��), 8(����), 9(��õ), 10(����), 11(����)
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
		P = (int**)malloc(sizeof(int*) * VERTEX_LEN); //2�����迭 �����Ҵ�
		for (int i = 0; i < VERTEX_LEN; i++) {
			P[i] = (int*)malloc(sizeof(int) * (int)(pow((double)2, (double)VERTEX_LEN - 1)));
		}

		travel(VERTEX_LEN, W, &P, minlength); //TSP �ִܰŸ� ���

		printf("0(�뱸), 1(����), 2(�λ�), 3(���), 4(����), 5(����), 6(õ��), 7(û��), 8(����), 9(��õ), 10(����), 11(����)\n");
		printf("�ִ� �Ÿ�: %d\n", minlength);
		printf("���: % d ", 0);
		A = (pow(2, VERTEX_LEN - 1) - 1);

		for (int i = 0; i < VERTEX_LEN; i++) { //�ִ� ��� ���
			printf("-> ");
			printf("%d ", P[j][A]);
			j = P[j][A];
			A = A - (int)pow(2, j - 1);

		}
		for (int i = 0; i < VERTEX_LEN; i++) //2���� �迭 �����Ҵ� ����
		{
			free(P[i]);
		}
		free(P);
	}
	
	if (start == 2) { //������� �����϶� 
		int W[VERTEX_LEN][VERTEX_LEN] =
		{//0(����), 1(����), 2(�λ�), 3(���), 4(����), 5(����), 6(õ��), 7(û��), 8(����), 9(��õ), 10(�뱸), 11(����)
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
		P = (int**)malloc(sizeof(int*) * VERTEX_LEN); //2���� �迭 �����Ҵ�
		for (int i = 0; i < VERTEX_LEN; i++) {
			P[i] = (int*)malloc(sizeof(int) * (int)(pow((double)2, (double)VERTEX_LEN - 1)));
		}

		travel(VERTEX_LEN, W, &P, minlength); //TSP �ִ� �Ÿ� ���

		printf("0(����), 1(����), 2(�λ�), 3(���), 4(����), 5(����), 6(õ��), 7(û��), 8(����), 9(��õ), 10(�뱸), 11(����)\n");
		printf("�ִ� �Ÿ�: %d\n", minlength);
		printf("���: % d ", 0);
		A = (pow(2, VERTEX_LEN - 1) - 1);

		for (int i = 0; i < VERTEX_LEN; i++) { //�ִ� ��� ���
			printf("-> ");
			printf("%d ", P[j][A]);
			j = P[j][A];
			A = A - (int)pow(2, j - 1);

		}

		for (int i = 0; i < VERTEX_LEN; i++) //2���� �迭 �����Ҵ� ����
		{
			free(P[i]);
		}
		free(P);
	}
}