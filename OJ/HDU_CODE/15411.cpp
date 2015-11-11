////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-10-17 15:21:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1541
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1052KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 32005
#define INF (1<<30)
#define lch(a) (a<<1)
#define rch(a) (a<<1|1)
using namespace std;

struct Tree
{
	int s,e,v;
}Tnode[4*MAXN];
int N,Num[15005];

void Build(int p,int s,int e)
{
	Tnode[p].s=s;Tnode[p].e=e;
	Tnode[p].v=0;
	if(s==e) return ;
	int mid=(s+e)>>1;
	Build(lch(p),s,mid);
	Build(rch(p),mid+1,e);
}
int Insert(int p,int x)
{
	Tnode[p].v++;
	if(Tnode[p].s==Tnode[p].e)
		return Tnode[p].v-1;
	int mid=(Tnode[p].s+Tnode[p].e)>>1;
	if(x<=mid) return Insert(lch(p),x);
	else return Tnode[lch(p)].v+Insert(rch(p),x);
}
void Init()
{
	int i,x,y;
	memset(Num,0,sizeof(Num));
	Build(1,0,32000);
	for(i=1;i<=N;i++)
	{
		scanf("%d%d",&x,&y);
		int id = Insert (1,x);
		Num[id]++;
	}
}
void Solve()
{
	int i;
	for(i=0;i<N;i++)
		printf("%d\n",Num[i]);
}
int main()
{
	while(scanf("%d",&N)!=EOF)
	{
		Init();
		Solve();
	}
	return 0;
}