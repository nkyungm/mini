/*
 < TSP 알고리즘 구현하기 >
 - 작성자 : 남경민
 - 학번 : 22012198
 - 날짜 : 2022-04-30
*/
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#define VERTEX_LEN 12 //간선의 총 개수

int Count1(int A) { //간선의 개수 세기(비트에서 1 개수 찾기)
	int c=0; //개수 세는 변수
	for (int j = 0; j < VERTEX_LEN - 1; j++) { //간선의 총 개수 -1 만큼 반복
		if ((A & (1 << j )) != 0) //1을 j만큼 왼쪽으로 shift하고 A에 &연산자 사용해 0인지 아닌지 확인
			c++; //0이 아니면 개수 +1
	}
	return c; //총 1의 개수 반환
}

int node_Min(int a, int b) { //최솟값 판단하는 함수
	if (a < b)return a;
	else return b;
}

void travel(int n, const int(*W)[VERTEX_LEN], int ***P, int& minlength) //TSP 최단거리 구하는 함수
{
	int i = 0, j = 0, k = 0; //인덱스
	int Not_A; 
	int wd; 
	int** D;
	D = (int**)malloc(sizeof(int*) * n); //2차원배열 동적할당
	for (int i = 0; i < n; i++) {
		D[i] = (int*)malloc(sizeof(int) * (int)(pow((double)2, (double)n - 1)));
	}

	for (i = 0; i < n; i++) {
		D[i][0] = W[i][0]; //중간에 노드를 거치지 않는 경우
		(*P)[i][0] = 0; //P[i][0]은 i에 도달하는 첫번째 인덱스 0이므로 0으로 채워줌
	}

	for (k = 1; k <= n - 2; k++) { // k: 중간에 거치는 정점의 개수

		for (int A = 1; A < pow(2, n - 1); A++) { //A: 거치는 정점의 집합(2의 n-1승까지 반복문 돌림)
			if (Count1(A) != k) //정점의 개수와 A의 1의 개수가 동일한지 확인
				continue; //같지 않다면 continue;
			else { //정점의 개수와 A의 1의 개수가 같다면
				Not_A = (pow(2, n - 1) - 1) - A; //Not_A : A에 포함되지 않은 정점 찾기 위함
				for (i = 1; i < n; i++) {
					D[i][A] = INT_MAX; //초기화
					if ((Not_A & (1 << (i - 1))) != 0) { //Not_A에서 해당 정점이 1이라면
						for (j = 1; j < n; j++) { //노드의 개수만큼 반복

							if ((A & (1 << (j - 1))) != 0) {//A에서 해당 정점이 1이라면
								wd = W[i][j] + D[j][A - (int)pow(2, j - 1)]; //거리 계산
								if (wd < 0) //거리가 INT_MAX에서 다른 값이 더해져 오버플로우 발생해서 음수로 바뀜
									wd = INT_MAX; //INT_MAX로 변경해줌
								if (D[i][A] > wd) { //wd의 거리가 더 작으면
									(*P)[i][A] = j; //P[i][A]에 Vi에 도달하는 첫번 째 노드의 인덱스로 j 넣어줌
								}
								D[i][A] = node_Min(D[i][A], wd); //크기 비교해서 최솟값 넣어줌
							}
						}

					}
				}
			}
		}
	}
	D[0][(int)pow(2, n - 1) - 1] = INT_MAX; //초기화

	for (j = 1; j < n; j++) { 
		wd = W[0][j] + D[j][((int)pow(2, n - 1) - 1) - ((int)pow(2, j - 1))]; //거리 계산
		if (wd < 0) //거리가 INT_MAX에서 다른 값이 더해져 오버플로우 발생해서 음수로 바뀜
			wd = INT_MAX; //INT_MAX로 변경해줌 
		if (D[0][(int)pow(2, n - 1) - 1] > wd) { //wd의 거리가 더 작으면
			(*P)[0][(int)pow(2, n - 1) - 1] = j; //P[0][(int)pow(2, n - 1) - 1]에 0에 도달하는 첫번 째 노드의 인덱스로 j 넣어줌
		}
		D[0][(int)pow(2, n - 1) - 1] = node_Min(D[0][(int)pow(2, n - 1) - 1], wd);  //크기 비교해서 최솟값 넣어줌
	}
	minlength = D[0][(int)pow(2, n - 1) - 1]; //V0에서 다시 돌아오는 최단거리 측정

	for (int i = 0; i < n; i++) //2차원 배열 동적할당 해제
	{
		free(D[i]);
	}
	free(D);
}

int main()
{
	int minlength = 0; //최단거리
	int j=0,A=0;
	int start;

	printf("< TSP 일주 경로 구하기 >\n");
	printf("출발지 : 1(대구), 2(서울) => ");
	scanf("%d", &start);

	if (start == 1) { //출발지가 대구일때
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
		P = (int**)malloc(sizeof(int*) * VERTEX_LEN); //2차원배열 동적할당
		for (int i = 0; i < VERTEX_LEN; i++) {
			P[i] = (int*)malloc(sizeof(int) * (int)(pow((double)2, (double)VERTEX_LEN - 1)));
		}

		travel(VERTEX_LEN, W, &P, minlength); //TSP 최단거리 계산

		printf("0(대구), 1(광주), 2(부산), 3(울산), 4(대전), 5(울진), 6(천안), 7(청주), 8(동해), 9(인천), 10(서울), 11(강릉)\n");
		printf("최단 거리: %d\n", minlength);
		printf("경로: % d ", 0);
		A = (pow(2, VERTEX_LEN - 1) - 1);

		for (int i = 0; i < VERTEX_LEN; i++) { //최단 경로 출력
			printf("-> ");
			printf("%d ", P[j][A]);
			j = P[j][A];
			A = A - (int)pow(2, j - 1);

		}
		for (int i = 0; i < VERTEX_LEN; i++) //2차원 배열 동적할당 해제
		{
			free(P[i]);
		}
		free(P);
	}
	
	if (start == 2) { //출발지가 서울일때 
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
		P = (int**)malloc(sizeof(int*) * VERTEX_LEN); //2차원 배열 동적할당
		for (int i = 0; i < VERTEX_LEN; i++) {
			P[i] = (int*)malloc(sizeof(int) * (int)(pow((double)2, (double)VERTEX_LEN - 1)));
		}

		travel(VERTEX_LEN, W, &P, minlength); //TSP 최단 거리 계산

		printf("0(서울), 1(광주), 2(부산), 3(울산), 4(대전), 5(울진), 6(천안), 7(청주), 8(동해), 9(인천), 10(대구), 11(강릉)\n");
		printf("최단 거리: %d\n", minlength);
		printf("경로: % d ", 0);
		A = (pow(2, VERTEX_LEN - 1) - 1);

		for (int i = 0; i < VERTEX_LEN; i++) { //최단 경로 출력
			printf("-> ");
			printf("%d ", P[j][A]);
			j = P[j][A];
			A = A - (int)pow(2, j - 1);

		}

		for (int i = 0; i < VERTEX_LEN; i++) //2차원 배열 동적할당 해제
		{
			free(P[i]);
		}
		free(P);
	}
}