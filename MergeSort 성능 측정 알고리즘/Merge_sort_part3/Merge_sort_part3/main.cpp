#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define SIZE 10000000
void Fill(int data[]);
void Scramble(int data[]);
void mergesort_3(int n, int S[]);
void merge_3(int h, int m, int q, const int U[], const int V[], const int P[], int S[]);
void Validate(int data[]);

int main()
{
	int* data;
	clock_t startTime, endTime;
	double elapsedTime;

	data = (int*)malloc(sizeof(int) * SIZE);
	Fill(data);
	Scramble(data);

	startTime = clock();
	mergesort_3(SIZE, data);
	endTime = clock();
	elapsedTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

	/*for (int i = 0; i < SIZE; i++) {
		printf("%d ", data[i]);
	}*/
	Validate(data);
	printf("%lf milli-sec", elapsedTime);
	free(data);
}

void Fill(int data[]) {
	for (int i = 0; i < SIZE; i++) {
		data[i] = i;
	}
}

void Scramble(int data[]) {

	int j, k, temp;
	srand(time(NULL));
	for (int i = 0; i < SIZE / 2; i++) {
		j = rand() % (SIZE);
		temp = data[i];
		data[i] = data[j];
		data[j] = temp;
	}
}

void mergesort_3(int n, int S[]) {

	const int h=n/3,m=(n-h)/2,q=n-(h+m);

	int* U, * V, *P;

	U = (int*)malloc(sizeof(int) * h); //동적배열 생성
	V = (int*)malloc(sizeof(int) * m);
	P = (int*)malloc(sizeof(int) * q);

	if (n > 1) {
		for (int i = 0; i < h; i++) {
			U[i] = S[i];
		}
		for (int i = h; i < h+m; i++) {
			V[i - h] = S[i];
		}
		for (int i = h+m; i < n; i++) {
			P[i - (h + m)] = S[i];
		}

		mergesort_3(h, U);
		mergesort_3(m, V);
		mergesort_3(q, P);
		merge_3(h, m,q, U, V,P, S);
	}
	free(U);
	free(V);
	free(P);
}

void merge_3(int h, int m,int q, const int U[], const int V[], const int P[], int S[]) {
	int i, j,z, k; //index
	i = 0; j = 0; z = 0; k = 0;

	while (i < h && j < m && z<q) {

		if ((U[i] < V[j])&&(U[i]<P[z])) {
			S[k] = U[i];
			++i;
		}
		else if((V[j]<U[i])&&(V[j]<P[z]))
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
		if (j >= m) {
			while (z < q) {
				S[k] = P[z];
				++z; ++k;
			}
		}
		else if(z>=q) {
			while (j < m) {
				S[k] = V[j];
				++j; ++k;
			}
		}
	}

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
		if (i >= h) {
			while (z < q) {
				S[k] = P[z];
				++z; ++k;
			}
		}
		else if (z >= q) {
			while (i < h) {
				S[k] = U[i];
				++i; ++k;
			}
		}
	}

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
		if (i >= h) {
			while (j < m) {
				S[k] = V[j];
				++j; ++k;
			}
		}
		else if (j >= m) {
			while (i < h) {
				S[k] = U[i];
				++i; ++k;
			}
		}
	}
}

void Validate(int data[]) {
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