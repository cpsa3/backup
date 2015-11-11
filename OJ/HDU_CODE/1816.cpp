////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-08-14 01:05:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1816
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:364KB
//////////////////System Comment End//////////////////
/*¶þ·Ö+2-satÅÐ¶Ï*/
/*AC´úÂë£º16ms*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 5000
#define min(a,b) (a<b?a:b)
using namespace std;
struct edge
{
	int u,v,next; 
}E[200000];
int head[MAXN],ecnt;
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];
int N,M,Index,scc,top;
bool Instack[MAXN];
int U1[1100],V1[1100];
int U2[2200],V2[2200];

void Insert(int u,int v)
{
	E[ecnt].u=u;
	E[ecnt].v=v;
	E[ecnt].next=head[u];
	head[u]=ecnt++;
}
void Init()
{
	int i;
	memset(head,-1,sizeof(head));ecnt=0;
	for(i=1;i<=N;i++)
		scanf("%d%d",&U1[i],&V1[i]);
	for(i=1;i<=M;i++)
		scanf("%d%d",&U2[i],&V2[i]); 
}
void Tarjan(int u)
{
	int i,v;
	DFN[u]=Low[u]=++Index;
	Stack[++top]=u;
	Instack[u]=true;
	for(i=head[u];i!=-1;i=E[i].next)
	{
		v=E[i].v;
		if(!DFN[v])
		{
			Tarjan(v);
			Low[u]=min(Low[u],Low[v]); 
		}
		else if(Instack[v])
			Low[u]=min(Low[u],DFN[v]); 
	}
	if(Low[u]==DFN[u])
	{
		scc++;
		do{
			v=Stack[top--];
			Instack[v]=false;
			Belong[v]=scc; 
		}while(u!=v); 
	} 
	return;
}
bool Judge(int mid)
{
	int i;
	memset(head,-1,sizeof(head));ecnt=0;
	for(i=1;i<=N;i++)
	{
		Insert(U1[i],2*N+V1[i]);
		Insert(V1[i],2*N+U1[i]); 
	}
	for(i=1;i<=mid;i++)
	{
		Insert(2*N+U2[i],V2[i]);
		Insert(2*N+V2[i],U2[i]); 
	}
	memset(DFN,0,sizeof(DFN));
	memset(Instack,false,sizeof(Instack));
	Index=scc=top=0;
	for(i=1;i<=4*N;i++)
	{if(!DFN[i]) Tarjan(i);}
	for(i=1;i<=2*N;i++)
	{
		if(Belong[i]==Belong[i+2*N])
			return false; 
	} 
	return true;
}
void Solve()
{
	int l,r,mid;
	l=0;r=M;
	while(l!=r)
	{
		mid=(l+r+1)>>1;
		if(Judge(mid))
			l=mid;
		else
			r=mid-1; 
	}
	printf("%d\n",l);
}
int main()
{
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		if(N==0&&M==0) break;
		Init();
		Solve();
	}
return 0;
}