////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-04 18:49:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3666
////Problem Title: 
////Run result: Accept
////Run time:906MS
////Run memory:5272KB
//////////////////System Comment End//////////////////
/*差分约束*/
/*L<=Xij * Ai / Bj<=U*/
/*lg(L)<= lg(Xij)+lg(Ai)-lg(Bj) <=lg(U)*/
/*队列实现*/
/*AC代码：906ms*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>
#include <memory.h>
#define min(a,b) (a<b?a:b)
#define INF 1e10
#define MAXN 805//N+M
using namespace std;
struct edge
{
	int v,next;
	double w;
}E[160000*3];
int head[MAXN],ecnt;
double dis[MAXN];
bool Instack[MAXN];
int N,M;
double L,U;
//d[v]<=d[u]+w(u,v);
void Insert(int u,int v,double w)//这里原先写成int w，结果WA到死
{
	E[ecnt].v=v;
	E[ecnt].w=w;
	E[ecnt].next=head[u];
	head[u]=ecnt++;
}
void Init()
{
	int i,j;
	double x;
	//L=log(L);U=log(U);
	memset(head,-1,sizeof(head));ecnt=0;
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=M;j++)
		{
			scanf("%lf",&x);
			Insert(j+N,i,log(U/x));
			Insert(i,j+N,log(x/L));
		}
	}
}
queue<int>Q;
void SPFA(int n)
{
	int i,u,v,sum=0;
	double w;
	while(!Q.empty()) Q.pop();
	memset(Instack,false,sizeof(Instack));
	for(i=1;i<=n;i++)
		dis[i]=INF;
	Q.push(1);
	Instack[1]=true;
	dis[1]=0;
	while(!Q.empty())
	{
		u=Q.front();Q.pop();
		Instack[u]=false;
		//if(cnt[u]>=(int)sqrt(1.0*n)) {printf("NO\n");return;}
		for(i=head[u];i!=-1;i=E[i].next)
		{
			v=E[i].v;w=E[i].w;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				if(!Instack[v])
				{
					Instack[v]=true;
					Q.push(v);
					sum++;
					if(sum>2*n) {printf("NO\n");return;}
				}
			}
		}
	}
	printf("YES\n");
	return;
}
int main()
{
	while(scanf("%d%d%lf%lf",&N,&M,&L,&U)!=EOF)
	{
		Init();
		SPFA(N+M);
	}
	return 0;
}