#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define SIZE 10000000
void Fill(int data[]);
void Scramble(int data[]);
void mergesort(int n, int S[]);
void merge(int h, int m, const int U[], const int V[], int S[]);
void Validate(int data[]);

int main()
{
	int* data;
	clock_t startTime, endTime;
	double elapsedTime;

	data= (int*)malloc(sizeof(int) * SIZE);
	Fill(data);
	Scramble(data);

	startTime = clock();
	mergesort(SIZE, data);
	endTime = clock();
	elapsedTime = (double)(endTime - startTime)/ CLOCKS_PER_SEC;

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

void mergesort(int n, int S[]) {

	const int h = n / 2, m = n - h;
	
	//int U[h],V[n];
	int* U, * V;

	U = (int*)malloc(sizeof(int) * h); //동적배열 생성
	V = (int*)malloc(sizeof(int) * m);

	if (n > 1) {
		for (int i = 0; i < h; i++) { 
			U[i] = S[i];
		}
		for (int i = h; i < n; i++) {
			V[i-h] = S[i];
		}
		mergesort(h, U);
		mergesort(m, V);
		merge(h, m, U, V, S);
	}
	free(U);
	free(V);
}

void merge(int h, int m, const int U[], const int V[], int S[]) {
	int i, j, k; //index
	i = 0; j = 0; k = 0;
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
	else {
		while (i < h) {
 			S[k] = U[i];
			++i; ++k;
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