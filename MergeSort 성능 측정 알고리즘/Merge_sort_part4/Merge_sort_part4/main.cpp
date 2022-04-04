#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define SIZE 10000000
void Fill(int data[]); // Data �迭�� 0���� 1�� ������ �� ä��� �Լ�
void Scramble(int data[]); //Data �迭 �� ���� ���� �Լ�
void mergesort_4(int n, int S[]); //��Ƽ�� ���� 4���� �պ����� �Լ�
void merge_4(int h, int m, int q, int t, const int U[], const int V[], const int P[], const int X[], int S[]);
void Validate(int data[]); //���� �� �迭�� ���� ����� ���ĵǾ����� Ȯ���ϴ� �Լ�

int main()
{
	int* data;
	clock_t startTime, endTime;
	double elapsedTime;

	data = (int*)malloc(sizeof(int) * SIZE); //�����迭 ����
	Fill(data);
	Scramble(data);

	startTime = clock(); //���� �ð� ����
	mergesort_4(SIZE, data);
	endTime = clock(); //���� ������ �ð� ����
	elapsedTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

	/*for (int i = 0; i < SIZE; i++) {
		printf("%d ", data[i]);
	}*/

	Validate(data);
	printf("%lf milli-sec", elapsedTime);
	free(data);
}

void Fill(int data[]) { // Data �迭�� 0���� 1�� ������ �� ä��� �Լ�
	for (int i = 0; i < SIZE; i++) {
		data[i] = i;
	}
}

void Scramble(int data[]) {  //Data �迭 �� ���� ���� �Լ�

	int j, k, temp;
	srand(time(NULL));
	for (int i = 0; i < SIZE / 2; i++) {
		j = rand() % (SIZE); //j �ε��� ���� ����
		temp = data[i];
		data[i] = data[j]; //�ε��� i�� j ������ �� ����
		data[j] = temp;
	}
}

void mergesort_4(int n, int S[]) { //��Ƽ�� ���� 4���� �պ����� �Լ�

	const int h = n / 4, m = (n - h) / 3, q = (n-(h+m))/2, t=(n-(q+h+m));

	int* U, * V, * P,*X;

	U = (int*)malloc(sizeof(int) * h); //�����迭 ����
	V = (int*)malloc(sizeof(int) * m); //�����迭 ����
	P = (int*)malloc(sizeof(int) * q); //�����迭 ����
	X = (int*)malloc(sizeof(int) * t); //�����迭 ����

	if (n > 1) { //n�� 1���� ũ��
		for (int i = 0; i < h; i++) {
			U[i] = S[i]; //U �迭�� ����
		}
		for (int i = h; i < h + m; i++) {
			V[i - h] = S[i]; //V �迭�� ����
		}
		for (int i = h + m; i < h+m+q; i++) {
			P[i - (h + m)] = S[i];  //P �迭�� ����
		}
		for (int i = h + m + q; i < n; i++) {
			X[i - (h + m + q)] = S[i]; //X �迭�� ����
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

	/* �迭 4�� */
	while (i < h && j < m && z < q && f<t) { //i, j, z,f �� �����ִ� ���

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

	/* �迭 3�� */
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
		/* �迭 2�� */
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
			/* �迭 1�� */
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
		/* �迭 2�� */
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
			/* �迭 1�� */
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
		/* �迭 2�� */
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
			/* �迭 1�� */
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
	/* �迭 3�� */
	else if (j >= m) {
		while (i < h && z < q && f < t) { //3�� 
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
		/* �迭 2�� */
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
			/* �迭 1�� */
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
		/* �迭 2�� */
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
			/* �迭 1�� */
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
		/* �迭 2�� */
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
			/* �迭 1�� */
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
	/* �迭 3�� */
	else if (z >= q) {
	    while (i < h && j < m && f < t) { //3�� 
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
		/* �迭 2�� */
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
			/* �迭 1�� */
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
		/* �迭 2�� */
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
			/* �迭 1�� */
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
		/* �迭 2�� */
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
			/* �迭 1�� */
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
	/* �迭 3�� */
	else if (f>=t) {
	    while (i < h && j < m && z < q) { //3�� 
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
		/* �迭 2�� */
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
			/* �迭 1�� */
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
		/* �迭 2�� */
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
			/* �迭 1�� */
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
		/* �迭 2�� */
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
			/* �迭 1�� */
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

void Validate(int data[]) { //���� �� �迭�� ���� ����� ���ĵǾ����� Ȯ���ϴ� �Լ�
	for (int i = 0; i < SIZE; i++) {
		if (data[i] == i) {
			continue;
		}
		else
		{
			printf("������ �߸��Ǿ����ϴ�.\n");
			return;
		}
	}
	printf("�պ����� ����!\n");
}