////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-10 11:08:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3622
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:1272KB
//////////////////System Comment End//////////////////
/*二分+2SAT判定*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cmath>
#define MAXN 405
#define INF 1e8
#define eps 1e-4
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define ll(a) (2*(a)-1)
#define rr(a) (2*(a))
#define fuck put("fuck");
using namespace std;
struct Node
{
	double x,y;
}node[MAXN];
struct edge
{
	int u,v,next;
}E[2000000];
int head[MAXN],ecnt;
int DFN[MAXN],Low[MAXN],Stack[MAXN],Belong[MAXN];
bool Instack[MAXN];
double map[MAXN][MAXN],Max;
int N,Index,top,scc;

void Insert(int u,int v)
{
	E[ecnt].u=u;
	E[ecnt].v=v;
	E[ecnt].next=head[u];
	head[u]=ecnt++;
}
double get_dis(int a,int b)
{
	double dx=node[a].x-node[b].x;
	double dy=node[a].y-node[b].y;
	return sqrt(dx*dx+dy*dy);
}
void Run()
{
	int i,j;
	Max=0;
	for(i=1;i<=2*N;i++)
	{
		for(j=i+1;j<=2*N;j++)
		{
			map[i][j]=map[j][i]=get_dis(i,j);
			Max=max(Max,map[i][j]);
		}
	}
}
void Init()
{
	int i;
	for(i=1;i<=2*N;i++)
		scanf("%lf%lf",&node[i].x,&node[i].y);
	Run();
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
}
bool Judge(double mid)
{
	int i,j,u,v;
	memset(head,-1,sizeof(head));ecnt=0;
	for(i=1;i<=N;i++)
	{
		for(j=i+1;j<=N;j++)
		{
			if(map[ll(i)][ll(j)]<mid)//1,1
			{
				Insert(i,j+N);
				Insert(j,i+N);
			}
			if(map[rr(i)][rr(j)]<mid)//2,2
			{
				Insert(i+N,j);
				Insert(j+N,i);
			}
			if(map[ll(i)][rr(j)]<mid)//1,2
			{
				Insert(i,j);
				Insert(j+N,i+N);
			}
			if(map[rr(i)][ll(j)]<mid)//2,1
			{
				Insert(i+N,j+N);
				Insert(j,i);
			}
		}
	}
	memset(DFN,0,sizeof(DFN));
	memset(Instack,false,sizeof(Instack));
	Index=top=scc=0;
	for(i=1;i<=2*N;i++)
	{if(!DFN[i]) Tarjan(i);}
	bool ok=true;
	for(i=1;i<=N;i++)
	{
		if(Belong[i]==Belong[i+N])
		{ok=false;break;}
	}
	return ok;
}
void Solve()
{
	double l,r,mid;
	l=0;r=Max;
	while(fabs(r-l)>eps)//二分直径
	{
		double mid=(l+r)/2;
		if(Judge(mid))
			l=mid;
		else
			r=mid;
	}
	printf("%.2lf\n",l/2);
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