////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-11-30 11:35:58
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1873
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:296KB
//////////////////System Comment End//////////////////



#include <iostream>
#include <cstdio>
#include <memory.h>
#include <cstdio>
#include <cmath>
#include <queue>
#define MAXN 2005
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define INF (1<<30)
using namespace std;

struct Node
{
	int id,p;
	Node(int id1,int p1)
	{
		id=id1;
		p=p1;
	}
	Node(){}
	bool operator<(const Node &a)const 
	{
		if(p!=a.p)
			return p<a.p;
		return id>a.id;
	}
};
priority_queue<Node>Q[3];
int N;
char s[3];
void Solve()
{
	int i,a,b;
	for(i=0;i<3;i++)
		while(!Q[i].empty()) Q[i].pop();
	int n=0;
	for(i=1;i<=N;i++)
	{
		scanf("%s",s);
		if(s[0]=='I')
		{
			n++;
			scanf("%d%d",&a,&b);
			Q[a-1].push(Node(n,b));	
		}
		else
		{
			scanf("%d",&a);
			if(Q[a-1].empty()) printf("EMPTY\n");
			else
			{
				printf("%d\n",Q[a-1].top().id);
				Q[a-1].pop();
			}
		}
	}	
}
int main()
{
	while(scanf("%d",&N)!=EOF)
	{
		Solve();
	}
	return 0;
}
