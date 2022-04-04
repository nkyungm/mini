#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define SIZE 10000000
void Fill(int data[]); // Data 배열을 0부터 1씩 증가해 값 채우는 함수
void Scramble(int data[]); //Data 배열 내 값을 섞는 함수
void mergesort_4(int n, int S[]); //파티션 수를 4개로 합병정렬 함수
void merge_4(int h, int m, int q, int t, const int U[], const int V[], const int P[], const int X[], int S[]);
void Validate(int data[]); //정렬 후 배열내 값이 제대로 정렬되었는지 확인하는 함수

int main()
{
	int* data;
	clock_t startTime, endTime;
	double elapsedTime;

	data = (int*)malloc(sizeof(int) * SIZE); //동적배열 생성
	Fill(data);
	Scramble(data);

	startTime = clock(); //시작 시간 측정
	mergesort_4(SIZE, data);
	endTime = clock(); //정렬 끝나는 시간 측정
	elapsedTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

	/*for (int i = 0; i < SIZE; i++) {
		printf("%d ", data[i]);
	}*/

	Validate(data);
	printf("%lf milli-sec", elapsedTime);
	free(data);
}

void Fill(int data[]) { // Data 배열을 0부터 1씩 증가해 값 채우는 함수
	for (int i = 0; i < SIZE; i++) {
		data[i] = i;
	}
}

void Scramble(int data[]) {  //Data 배열 내 값을 섞는 함수

	int j, k, temp;
	srand(time(NULL));
	for (int i = 0; i < SIZE / 2; i++) {
		j = rand() % (SIZE); //j 인덱스 랜덤 생성
		temp = data[i];
		data[i] = data[j]; //인덱스 i와 j 데이터 값 변경
		data[j] = temp;
	}
}

void mergesort_4(int n, int S[]) { //파티션 수를 4개로 합병정렬 함수

	const int h = n / 4, m = (n - h) / 3, q = (n-(h+m))/2, t=(n-(q+h+m));

	int* U, * V, * P,*X;

	U = (int*)malloc(sizeof(int) * h); //동적배열 생성
	V = (int*)malloc(sizeof(int) * m); //동적배열 생성
	P = (int*)malloc(sizeof(int) * q); //동적배열 생성
	X = (int*)malloc(sizeof(int) * t); //동적배열 생성

	if (n > 1) { //n이 1보다 크면
		for (int i = 0; i < h; i++) {
			U[i] = S[i]; //U 배열에 복사
		}
		for (int i = h; i < h + m; i++) {
			V[i - h] = S[i]; //V 배열에 복사
		}
		for (int i = h + m; i < h+m+q; i++) {
			P[i - (h + m)] = S[i];  //P 배열에 복사
		}
		for (int i = h + m + q; i < n; i++) {
			X[i - (h + m + q)] = S[i]; //X 배열에 복사
		}

		mergesort_4(h, U);
		mergesort_4(m, V);
		mergesort_4(q, P);
		mergesort_4(t, X);
		merge_4(h, m, q,t, U, V, P,X, S);
	}
	free(U);
	free(V);
	free(P);
	free(X);
}

void merge_4(int h, int m, int q,int t, const int U[], const int V[], const int P[],const int X[], int S[]) {
	int i, j, z, f,k; //index
	i = 0; j = 0; z = 0; f = 0; k = 0;

	/* 배열 4개 */
	while (i < h && j < m && z < q && f<t) { //i, j, z,f 다 남아있는 경우

		if ((U[i] < V[j]) && (U[i] < P[z]) && (U[i] < X[f])) {
			S[k] = U[i];
			++i;
		}
		else if ((V[j] < U[i]) && (V[j] < P[z]) && (V[j] < X[f]))
		{
			S[k] = V[j];
			++j;
		}
		else if ((P[z] < U[i]) && (P[z] < V[j]) && (P[z] < X[f]))
		{
			S[k] = P[z];
			++z;
		}
		else {
			S[k] = X[f];
			++f;
		}
		++k;
	}

	/* 배열 3개 */
	if (i >= h) { 
		while (j < m && z < q && f<t) { 
			if ((V[j] < P[z]) && (V[j] < X[f])) {
				S[k] = V[j];
				++j;
			}
			else if ((P[z] < V[j]) && (P[z] < X[f]))
			{
				S[k] = P[z];
				++z;
			}
			else {
				S[k] = X[f];
				++f;
			}
			++k;
		}
		/* 배열 2개 */
		if (j >= m) {
			while (z < q && f < t) {
				if (P[z] < X[f]) {
					S[k] = P[z];
					++z;
				}
				else {
					S[k] = X[f];
					++f;
				}
				++k;
			}
			/* 배열 1개 */
			if (z >= q) { 
				while (f < t) {
					S[k] = X[f];
					++f; ++k;
				}
			}
			else {
				while (z < q) {
					S[k] = P[z];
					++z; ++k;
				}
			}
		}
		/* 배열 2개 */
		else if (z >= q) {
			while (j < m && f < t) {
				if (V[j] < X[f]) {
					S[k] = V[j];
					++j;
				}
				else {
					S[k] = X[f];
					++f;
				}
				++k;
			}
			/* 배열 1개 */
			if (j >= m) {
				while (f < t) {
					S[k] = X[f];
					++f; ++k;
				}
			}
			else {
				while (j < m) {
					S[k] = V[j];
					++j; ++k;
				}
			}
		}
		/* 배열 2개 */
		else if (f >= t) {
			while (j < m && z < q) {
				if (V[j] < P[z]) {
					S[k] = V[j];
					++j;
				}
				else {
					S[k] = P[z];
					++z;
				}
				++k;
			}
			/* 배열 1개 */
			if (j >= m) {
				while (z < q) {
					S[k] = P[z];
					++z; ++k;
				}
			}
			else {
				while (j < m) {
					S[k] = V[j];
					++j; ++k;
				}
			}
		}
	}
	/* 배열 3개 */
	else if (j >= m) {
		while (i < h && z < q && f < t) { //3개 
			if ((U[i] < P[z]) && (U[i] < X[f])) {
				S[k] = U[i];
				++i;
			}
			else if ((P[z] < U[i]) && (P[z] < X[f]))
			{
				S[k] = P[z];
				++z;
			}
			else {
				S[k] = X[f];
				++f;
			}
			++k;
		}
		/* 배열 2개 */
		if (i >= h) {
			while (z < q && f < t) {
				if (P[z] < X[f]) {
					S[k] = P[z];
					++z;
				}
				else {
					S[k] = X[f];
					++f;
				}
				++k;
			}
			/* 배열 1개 */
			if (z >= q) {
				while (f < t) {
					S[k] = X[f];
					++f; ++k;
				}
			}
			else {
				while (z < q) {
					S[k] = P[z];
					++z; ++k;
				}
			}
		}
		/* 배열 2개 */
		else if (z >= q) {
			while (i < h && f < t) {
				if (U[i] < X[f]) {
					S[k] = U[i];
					++i;
				}
				else {
					S[k] = X[f];
					++f;
				}
				++k;
			}
			/* 배열 1개 */
			if (i >= h) {
				while (f < t) {
					S[k] = X[f];
					++f; ++k;
				}
			}
			else {
				while (i < h) {
					S[k] = U[i];
					++i; ++k;
				}
			}
		}
		/* 배열 2개 */
		else if (f>=t) {
			while (i < h && z < q) {
				if (U[i] < P[z]) {
					S[k] = U[i];
					++i;
				}
				else {
					S[k] = P[z];
					++z;
				}
				++k;
			}
			/* 배열 1개 */
			if (i >= h) {
				while (z < q) {
					S[k] = P[z];
					++z; ++k;
				}
			}
			else {
				while (i < h) {
					S[k] = U[i];
					++i; ++k;
				}
			}
		}
	}
	/* 배열 3개 */
	else if (z >= q) {
	    while (i < h && j < m && f < t) { //3개 
	    	if ((U[i] < V[j]) && (U[i] < X[f])) {
	    		S[k] = U[i];
	    		++i;
	    	}
	    	else if ((V[j] < U[i]) && (V[j] < X[f]))
	    	{
	    		S[k] = V[j];
	    		++j;
	    	}
	    	else {
	    		S[k] = X[f];
	    		++f;
	    	}
	    	++k;
	    }
		/* 배열 2개 */
		if (i >= h) {
			while (j < m && f < t) {
				if (V[j] < X[f]) {
					S[k] = V[j];
					++j;
				}
				else {
					S[k] = X[f];
					++f;
				}
				++k;
			}
			/* 배열 1개 */
			if (j >= m) {
				while (f < t) {
					S[k] = X[f];
					++f; ++k;
				}
			}
			else {
				while (j < m) {
					S[k] = V[j];
					++j; ++k;
				}
			}
		}
		/* 배열 2개 */
		else if (j >= m) {
			while (i < h && f < t) {
				if (U[i] < X[f]) {
					S[k] = U[i];
					++i;
				}
				else {
					S[k] = X[f];
					++f;
				}
				++k;
			}
			/* 배열 1개 */
			if (i >= h) {
				while (f < t) {
					S[k] = X[f];
					++f; ++k;
				}
			}
			else {
				while (i < h) {
					S[k] = U[i];
					++i; ++k;
				}
			}
		}
		/* 배열 2개 */
		else if (f >= t) {
			while (i < h && j < m) {
				if (U[i] < V[j]) {
					S[k] = U[i];
					++i;
				}
				else {
					S[k] = V[j];
					++j;
				}
				++k;
			}
			/* 배열 1개 */
			if (i >= h) {
				while (j < m) {
					S[k] = V[j];
					++j; ++k;
				}
			}
			else {
				while (i < h) {
					S[k] = U[i];
					++i; ++k;
				}
			}
		}
    }
	/* 배열 3개 */
	else if (f>=t) {
	    while (i < h && j < m && z < q) { //3개 
	    	if ((U[i] < V[j]) && (U[i] < P[z])) {
	    		S[k] = U[i];
	    		++i;
	    	}
	    	else if ((V[j] < U[i]) && (V[j] < P[z]))
	    	{
	    		S[k] = V[j];
	    		++j;
	    	}
	    	else {
	    		S[k] = P[z];
	    		++z;
	    	}
	    	++k;
	    }
		/* 배열 2개 */
	    if (i >= h) {
	    	while (j < m && z < q) {
	    		if (V[j] < P[z]) {
	    			S[k] = V[j];
	    			++j;
	    		}
	    		else {
	    			S[k] = P[z];
	    			++z;
	    		}
	    		++k;
	    	}
			/* 배열 1개 */
	    	if (j >= m) {
	    		while (z < q) {
	    			S[k] = P[z];
	    			++z; ++k;
	    		}
	    	}
	    	else {
	    		while (j < m) {
	    			S[k] = V[j];
	    			++j; ++k;
	    		}
	    	}
	    }
		/* 배열 2개 */
	    else if (j >= m) {
	    	while (i < h && z < q) {
	    		if (U[i] < P[z]) {
	    			S[k] = U[i];
	    			++i;
	    		}
	    		else {
	    			S[k] = P[z];
	    			++z;
	    		}
	    		++k;
	    	}
			/* 배열 1개 */
	    	if (i >= h) {
	    		while (z < q) {
	    			S[k] = P[z];
	    			++z; ++k;
	    		}
	    	}
	    	else {
	    		while (i < h) {
	    			S[k] = U[i];
	    			++i; ++k;
	    		}
	    	}
	    }
		/* 배열 2개 */
	    else {
	    	while (i < h && j < m) {
	    		if (U[i] < V[j]) {
	    			S[k] = U[i];
	    			++i;
	    		}
	    		else {
	    			S[k] = V[j];
	    			++j;
	    		}
	    		++k;
	    	}
			/* 배열 1개 */
	    	if (i >= h) {
	    		while (j < m) {
	    			S[k] = V[j];
	    			++j; ++k;
	    		}
	    	}
	    	else {
	    		while (i < h) {
	    			S[k] = U[i];
	    			++i; ++k;
	    		}
	    	}
	    }

	}
}

void Validate(int data[]) { //정렬 후 배열내 값이 제대로 정렬되었는지 확인하는 함수
	for (int i = 0; i < SIZE; i++) {
		if (data[i] == i) {
			continue;
		}
		else
		{
			printf("정렬이 잘못되었습니다.\n");
			return;
		}
	}
	printf("합병정렬 성공!\n");
}