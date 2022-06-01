#include <stdio.h>
#include <iostream>
#include <queue>
#include<list>
#include<math.h>

#define SIZE 4

using namespace std;
int W[SIZE][SIZE];

struct node
{
	int level;
	list<int> path;
	int bound; //�Ѱ谪
};

struct bound_compare {
	bool operator()(node& u,node& v) {
		return u.bound < v.bound;
	}
};

void travel2(int n,list<int>& opttour,int& minlength)
{
	int index=1;
	priority_queue<node, vector<node>, bound_compare> PQ; //�������� �켱���� ť
	node u, v;

	PQ = priority_queue<node, vector<node>, bound_compare>(); //PQ �ʱ�ȭ

	v.level = 0; //
	v.path.push_back(1); //ù��° ���� ��������� ����

	v.bound = bound(v);
	minlength = INFINITY;

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
						if (find(u.path.begin(), u.path.end(), j) != u.path.end()) //u.path�� j�� ���ٸ�
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

int bound(node d)
{

}

int length(node l)
{
	list<int>::iterator iter;
	for (iter = l.path.begin(); iter != l.path.end(); iter++) {

	}

}