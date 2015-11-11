////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-10-07 00:34:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1824
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:532KB
//////////////////System Comment End//////////////////
/*HDU_1824 Let's go home*/
/*2-SAT*/
/*
构图： 
(1):对于每个点i拆成两个点i,i+N 分别表示留下和不留下 
(2):?每个队三个队员为A,B,C (A为队长)
		1.A+N->B 
		  A+N->C
		  B+N->A
		  C+N->A
(3):每一对队员X,Y
		2.A+N->B
		  B+N->A
		  A->B+N
		  B->A+N 
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#define MAXN 6005
#define INF (1<<30)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;

struct edge
{
	int u,v,next;
}E[2000000];
int head[MAXN],ecnt;
int N,M,T;
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];
bool Instack[MAXN];
int scc,top,Index;

void Insert(int u,int v)
{
	E[ecnt].u=u;
	E[ecnt].v=v;
	E[ecnt].next=head[u];
	head[u]=ecnt++;
}
void Init()
{
	int i,A,B,C,X,Y;
	N=3*T; 
	memset(head,-1,sizeof(head));ecnt=0;
	for(i=1;i<=T;i++)
	{
		scanf("%d%d%d",&A,&B,&C);
		Insert(A+N,B);
		Insert(A+N,C);
		Insert(B+N,A);
		Insert(C+N,A);
	}
	for(i=1;i<=M;i++)
	{
		scanf("%d%d",&X,&Y);
		//Insert(X+N,Y);
		//Insert(Y+N,X);
		Insert(X,Y+N);
		Insert(Y,X+N); 
	}
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
void Solve()
{
	int i;
	memset(DFN,0,sizeof(DFN));
	memset(Low,0,sizeof(Low));
	memset(Instack,false,sizeof(Instack));
	scc=top=Index=0;
	for(i=0;i<2*N;i++)
	{
		if(!DFN[i]) Tarjan(i);
	} 
	bool ok=true;
	for(i=0;i<N;i++)
	{
		if(Belong[i]==Belong[i+N])
		{
			ok=false;
			break;
		}
	}
	if(ok) printf("yes\n");
	else printf("no\n");
}
int main()
{
	while(scanf("%d%d",&T,&M)!=EOF)
	{
		Init();
		Solve();
	}
	return 0;
}
