////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-20 20:25:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3926
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1076KB
//////////////////System Comment End//////////////////
/*暴力*/
/*判断两幅无向图是否同构*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 10005
#define INF 1e8
using namespace std;
struct edge
{
	int u,v,next;
}E1[200000],E2[200000];
int head1[MAXN],ecnt1;
int head2[MAXN],ecnt2;
int N1,M1,N2,M2,cas;
int A[MAXN][2];
int B[MAXN][2];
int deg1[MAXN],deg2[MAXN];
bool vis1[MAXN],vis2[MAXN];
int num1,num2;
void Insert1(int u,int v)
{
	E1[ecnt1].u=u;
	E1[ecnt1].v=v;
	E1[ecnt1].next=head1[u];
	head1[u]=ecnt1++;
}
void Insert2(int u,int v)
{
	E2[ecnt2].u=u;
	E2[ecnt2].v=v;
	E2[ecnt2].next=head2[u];
	head2[u]=ecnt2++;
}
void Init()
{
	int i,u,v;
	memset(head1,-1,sizeof(head1));ecnt1=0;
	memset(head2,-1,sizeof(head2));ecnt2=0;
	memset(A,0,sizeof(A));
	memset(B,0,sizeof(B));
	memset(deg1,0,sizeof(deg1));
	memset(deg2,0,sizeof(deg2));
	scanf("%d%d",&N1,&M1);
	for(i=1;i<=M1;i++)
	{
		scanf("%d%d",&u,&v);
		deg1[u]++;
		deg1[v]++;
		Insert1(u,v);
		Insert1(v,u);
	}
	scanf("%d%d",&N2,&M2);
	for(i=1;i<=M2;i++)
	{
		scanf("%d%d",&u,&v);
		deg2[u]++;
		deg2[v]++;
		Insert2(u,v);
		Insert2(v,u);
	}
}
void swap(int &a,int &b)
{
	int t;
	if(a>b)
	{t=a;a=b;b=t;}
}
void dfs1(int u)
{
	int i,v;
	vis1[u]=true;
	num1++;
	for(i=head1[u];i!=-1;i=E1[i].next)
	{
		v=E1[i].v;
		if(!vis1[v])
			dfs1(v);
	}
}
void dfs2(int u)
{
	int i,v;
	vis2[u]=true;
	num2++;
	for(i=head2[u];i!=-1;i=E2[i].next)
	{
		v=E2[i].v;
		if(!vis2[v])
			dfs2(v);
	}
}
void Solve()
{
	int i;
	bool ok=true;
	if(N1!=N2||M1!=M2) 
	{
		printf("Case #%d: NO\n",cas++);
		return ;
	}
	memset(vis1,false,sizeof(vis1));
	memset(vis2,false,sizeof(vis2));

	for(i=1;i<=N1;i++)
	{
		if(vis1[i]) continue;
		if(deg1[i]==0)
			A[1][0]++;
		else if(deg1[i]==1)
		{
			num1=0;
			dfs1(i);
			A[num1][0]++;
		}
	}
	for(i=1;i<=N1;i++)
	{
		if(!vis1[i])
		{
			num1=0;
			dfs1(i);
			A[num1][1]++;
		}
	}


	for(i=1;i<=N2;i++)
	{
		if(vis2[i]) continue;
		if(deg2[i]==0)
			B[1][0]++;
		else if(deg2[i]==1)
		{
			num2=0;
			dfs2(i);
			B[num2][0]++;
		}
	}
	for(i=1;i<=N2;i++)
	{
		if(!vis2[i])
		{
			num2=0;
			dfs2(i);
			B[num2][1]++;
		}
	}

	for(i=0;i<=N1;i++)
	{
		if((A[i][0]!=B[i][0])||(A[i][1]!=B[i][1]))
		{ok=false;break;}
	}

	if(ok)
		printf("Case #%d: YES\n",cas++);
	else
		printf("Case #%d: NO\n",cas++);
}
int main()
{
	int T;
	cas=1;
	scanf("%d",&T);
	while(T--)
	{
		Init();
		Solve();
	}
return 0;
}	