#include <stdio.h>
#include <iostream>
#include <queue>
#include<list>
#include<math.h>

#define SIZE 12
#define INF 1000000
using namespace std;

struct node
{
	int level;
	list<int> path;
	int bound; //�Ѱ谪
};

struct bound_compare {
	bool operator()(const node& a, const node& b) {
		return a.bound > b.bound;
	}
};

int length(node l);
int bound(node d);
void travel2(int n, list<int>& opttour, int& minlength);

//int W[SIZE][SIZE] = {
//	{0,14,4,10,20},
//	{14,0,7,8,7},
//	{4,5,0,7,16},
//	{11,7,9,0,2},
//	{18,7,17,4,0}
//};

//int W[SIZE][SIZE] =
//{//0(�뱸), 1(����), 2(�λ�), 3(���), 4(����), 5(����), 6(õ��), 7(û��), 8(����), 9(��õ), 10(����), 11(����)
//	{0,INF,1,2,6,INF,INF,6,INF,INF,INF,INF},
//	{6,0,5,INF,3,INF,INF,INF,INF,INF,INF,INF},
//	{INF,4,0,3,INF,INF,INF,INF,INF,INF,INF,INF,},
//	{INF,INF,2,0,INF,1,INF,INF,INF,INF,INF,INF},
//	{3,3,INF,INF,0,5,5,INF,INF,INF,INF,INF},
//	{3,INF,INF,3,5,0,INF,2,3,INF,INF,INF},
//	{INF,INF,INF,INF,4,INF,0,4,INF,3,INF,INF},
//	{INF,INF,INF,INF,INF,2,3,0,1,INF,13,INF},
//	{INF,INF,INF,INF,INF,5,INF,2,0,INF,INF,5},
//	{INF,INF,INF,INF,INF,INF,1,INF,INF,0,7,INF},
//	{INF,INF,INF,INF,INF,INF,INF,8,INF,3,0,5},
//	{INF,INF,INF,INF,INF,INF,INF,INF,3,INF,3,0}
//};

int W[SIZE][SIZE] =
{//0(����), 1(����), 2(�λ�), 3(���), 4(����), 5(����), 6(õ��), 7(û��), 8(����), 9(��õ), 10(�뱸), 11(����)
	{0,INF,INF,INF,INF,INF,INF,8,INF,3,INF,5},
	{INF,0,5,INF,3,INF,INF,INF,INF,INF,6,INF},
	{INF,4,0,3,INF,INF,INF,INF,INF,INF,INF,INF,},
	{INF,INF,2,0,INF,1,INF,INF,INF,INF,INF,INF},
	{INF,3,INF,INF,0,5,5,INF,INF,INF,3,INF},
	{INF,INF,INF,3,5,0,INF,2,3,INF,3,INF},
	{INF,INF,INF,INF,4,INF,0,4,INF,3,INF,INF},
	{13,INF,INF,INF,INF,2,3,0,1,INF,INF,INF},
	{INF,INF,INF,INF,INF,5,INF,2,0,INF,INF,5},
	{7,INF,INF,INF,INF,INF,1,INF,INF,0,INF,INF},
	{INF,INF,1,2,6,INF,INF,6,INF,INF,0,INF},
	{3,INF,INF,INF,INF,INF,INF,INF,3,INF,INF,0}
};

int main() {

	int minLength;
	int n = 1;
	list<int> opttour;
	list<int>::iterator iter;

	travel2(SIZE, opttour, minLength);

	cout << minLength << "\n";
	for (iter = opttour.begin(); iter != opttour.end() && n != opttour.size(); iter++)
	{
		cout << *iter << " -> ";
		n++;
	}cout << "1";
}

int length(node l)
{
	int Value = 0;
	int n = 1;
	list<int>::iterator iter;
	for (iter = l.path.begin(); iter != l.path.end() && n != l.path.size(); iter++) {
		Value += W[(*iter) - 1][(*(++iter)) - 1];
		iter--;
		n++;
	}
	return Value;
}

int bound(node d)
{
	int Bound = 0;
	int bound_min;
	Bound += length(d);

	bound_min = INT_MAX;
	for (int i = 2; i <= SIZE; i++) {
		if (find(d.path.begin(), d.path.end(), i) != d.path.end())
			continue;
		if (W[d.path.back() - 1][i - 1] < bound_min)
			bound_min = W[d.path.back() - 1][i - 1];
	}
	Bound += bound_min;

	for (int i = 2; i <= SIZE; i++) {
		bound_min = W[i - 1][0];
		if (find(d.path.begin(), d.path.end(), i) != d.path.end())
			continue;
		for (int j = 2; (j <= SIZE) ; j++) {
			if ((find(d.path.begin(), d.path.end(), j) != d.path.end())||(j==i))
				continue;
			if (W[i - 1][j - 1] < bound_min)
				bound_min = W[i - 1][j - 1];
		}
		Bound += bound_min;
	}

	return Bound;
}

void travel2(int n,list<int>& opttour,int& minlength)
{
	int index=1;
	priority_queue<node, vector<node>, bound_compare> PQ; //�������� �켱���� ť
	node u, v;

	PQ = priority_queue<node, vector<node>, bound_compare>(); //PQ �ʱ�ȭ

	v.level = 0; //
	v.path.push_back(1); //ù��° ���� ��������� ����

	v.bound = bound(v);
	minlength = INT_MAX;

	PQ.push(v); //node v ����ü PQ�� ����

	while (!empty(PQ))
	{
		v = PQ.top();
		PQ.pop();

		if (v.bound < minlength) { //�Ѱ谪�� �ּ� ���� ��
			u.level = v.level + 1;
			
			for (int i = 2; i <= n; i++) {
				if (find(v.path.begin(),v.path.end(),i)!=v.path.end()) //v.path�� i�� �����ϸ�
					continue;

				u.path = v.path;
				u.path.push_back(i);

				if (u.level == n - 2) //���̻� �� �ʿ�X
				{
					for (int j = 2; j <= n; j++) {
						if (find(u.path.begin(), u.path.end(), j) == u.path.end()) //u.path�� j�� ���ٸ�
						{
							u.path.push_back(j);
							break;
						}
					}
					u.path.push_back(1);
					if (length(u) < minlength) {
						minlength = length(u);
						opttour = u.path;
					}
				}
				else {
					u.bound = bound(u);
					if (u.bound < minlength)
						PQ.push(u);
				}
			}
		}
	}
}