////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-12-29 22:30:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1532
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:580KB
//////////////////System Comment End//////////////////
/*网络最大流*/
#include <iostream>
#include <queue>
using namespace std;
#define INF 99999999
#define MAXN 205
int cp[MAXN][MAXN];//用来存i,j的容量
int flow[MAXN][MAXN];//用来存i,j的流量
int a[MAXN];//a[i]=j:源点s到i的最小残量为j
int p[MAXN];//p[v]=u;表示v的父节点为u
int N,M;//N:边数  M:点数
int maxf;//记录总的流量
int min(int a,int b)
{return a<b?a:b;}
queue<int>Q;
//求s->t的最大流
void Edmonds_Karp(int s,int t)//s为源点,t为汇点
{
	int u,v;
	memset(p,0,sizeof(p));
	maxf=0;
	while(true)
	{
		memset(a,0,sizeof(a));//每次找增广路径时都要初始化
		if(!Q.empty())
			Q.pop();
		Q.push(s);
		a[s]=INF;
		while(!Q.empty())//bfs找增广路径
		{
			u=Q.front();
			Q.pop();
			for(v=1;v<=M;v++)
			{
				if(!a[v]&&cp[u][v]>flow[u][v])
				{
					p[v]=u;//注意不是p[u]=v;记录v的父节点
					Q.push(v);
					a[v]=min(a[u],cp[u][v]-flow[u][v]);//更新v的最小残量
				}
			}
		}
		if(!a[t])//没有找到增广路径
			break;
		//更新正向流量和反向流量
		for(u=t;u!=s;u=p[u])//递归访问增广路径
		{
			flow[p[u]][u]+=a[t];
			flow[u][p[u]]-=a[t];
		}
		maxf+=a[t];//更新从s流出的总流量
	}
	printf("%d\n",maxf);
}
int main()
{
	int s,e,c,i;
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		memset(cp,0,sizeof(cp));
		memset(flow,0,sizeof(flow));
		for(i=1;i<=N;i++)
		{
			scanf("%d%d%d",&s,&e,&c);
			cp[s][e]+=c;//重边处理
		}
		Edmonds_Karp(1,M);
	}
	return 0;
}