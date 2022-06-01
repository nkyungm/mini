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
	int bound; //한계값
};

struct bound_compare {
	bool operator()(node& u,node& v) {
		return u.bound < v.bound;
	}
};

void travel2(int n,list<int>& opttour,int& minlength)
{
	int index=1;
	priority_queue<node, vector<node>, bound_compare> PQ; //오름차순 우선순위 큐
	node u, v;

	PQ = priority_queue<node, vector<node>, bound_compare>(); //PQ 초기화

	v.level = 0; //
	v.path.push_back(1); //첫번째 정점 출발점으로 지정

	v.bound = bound(v);
	minlength = INFINITY;

	PQ.push(v); //node v 구조체 PQ에 삽입

	while (!empty(PQ))
	{
		v = PQ.top();
		PQ.pop();

		if (v.bound < minlength) { //한계값과 최소 길이 비교
			u.level = v.level + 1;
			
			for (int i = 2; i <= n; i++) {
				if (find(v.path.begin(),v.path.end(),i)!=v.path.end()) //v.path에 i가 존재하면
					continue;

				u.path = v.path;
				u.path.push_back(i);

				if (u.level == n - 2) //더이상 갈 필요X
				{
					for (int j = 2; j <= n; j++) {
						if (find(u.path.begin(), u.path.end(), j) != u.path.end()) //u.path에 j가 없다면
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