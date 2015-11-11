////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-04-18 19:39:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2610
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:768KB
//////////////////System Comment End//////////////////
/*BFS+‘§¥¶¿Ì*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <queue>
#include <vector>
#define MAXN 1005
using namespace std;
struct Node
{
	vector<int>V;
	int pos;
};
int S[MAXN];
int temp[MAXN];
int N,P;
void Init()
{
	int i;
	for(i=1;i<=N;i++)
		scanf("%d",&S[i]);
}
void Print(Node u)
{
	int i,size=u.V.size();
	for(i=0;i<size-1;i++)
		printf("%d ",u.V[i]);
	printf("%d\n",u.V[i]);
}
void get_temp()
{
	int i,j;
	for(i=1;i<=N;i++)
	{
		for(j=i-1;j>=1;j--)
		{if(S[i]==S[j]) break;}
		temp[i]=j;
	}
}
queue<Node>Q;
void Solve()
{
	int i;
	Node u,v;
	get_temp();
	while(!Q.empty()) Q.pop();
	int cnt=0;
	for(i=1;i<=N;i++)
	{
		if(temp[i]>=1) continue;
		u.V.clear();
		u.pos=i;
		u.V.push_back(S[i]);
		Print(u);cnt++;
		if(cnt==P) return;
		Q.push(u);
	}
	while(!Q.empty())
	{
		u=Q.front();Q.pop();
		if(cnt==P) break;
		int pos=u.pos,now=u.V.back();
		for(i=pos+1;i<=N;i++)
		{
			if(temp[i]>=pos+1) continue;
			if(S[i]>=now)
			{
				v=u;
				v.pos=i;
				v.V.push_back(S[i]);
				Print(v);cnt++;
				if(cnt==P) return;
				Q.push(v);
			}
		}
	}
}
int main()
{
	while(scanf("%d%d",&N,&P)!=EOF)
	{
		Init();
		Solve();
		printf("\n");
	}
	return 0;
}