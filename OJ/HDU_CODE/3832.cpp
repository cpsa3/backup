////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-08 17:58:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3832
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:416KB
//////////////////System Comment End//////////////////
/*求连接3个点的最短距离*/
/*AC代码：*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <queue>
#include <cmath>
#define MAXN 405
#define INF 1e8
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct Point
{
	int u,step;
	Point(int u1,int step1)
	{u=u1;step=step1;}
	Point(){}
};
struct Node
{
	int x,y,r;
}node[MAXN];
int pre[MAXN];
bool map[MAXN][MAXN];
bool vis[MAXN];
int dis1[MAXN],dis2[MAXN],dis3[MAXN];
int W[MAXN],wcnt;
int N,ans;
int temp[100000000];
bool Judge(int a,int b)
{
	int dx=(node[a].x-node[b].x);
	int dy=(node[a].y-node[b].y);
	double w=sqrt((double)(dx*dx+dy*dy));
	if(node[a].r+node[b].r>=w)
		return true;
	return false;
}
void Run()
{
	int i,j;
	memset(map,false,sizeof(map));
	for(i=1;i<=N;i++)
	{
		//map[i][i]=true;
		for(j=i+1;j<=N;j++)
		{
			if(Judge(i,j))
			{
				map[i][j]=map[j][i]=true;
			}
		}
	}
}
void Init()
{
	int i;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
		scanf("%d%d%d",&node[i].x,&node[i].y,&node[i].r);
	Run();
}
queue<Point>Q;
void BFS(int s,int dis[])
{
	int i,u,step;
	Point p;
	while(!Q.empty()) Q.pop();
	memset(vis,false,sizeof(vis));
	for(i=1;i<=N;i++)
		dis[i]=INF;
	Q.push(Point(s,0));
	vis[s]=true;
	dis[s]=0;
	while(!Q.empty())
	{
		p=Q.front();Q.pop();
		u=p.u;step=p.step+1;
		for(i=1;i<=N;i++)
		{
			if(!vis[i]&&map[u][i])
			{
				vis[i]=true;
				dis[i]=step;
				Q.push(Point(i,step));
			}
		}
	}
}
void Print()
{
	int i,j;
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
			printf("%d ",map[i][j]);
		printf("\n");
	}
	printf("---\n");
	for(i=1;i<=N;i++)
		printf("%d ",dis1[i]);
	printf("\n");
	for(i=1;i<=N;i++)
		printf("%d ",dis2[i]);
	printf("\n");
	for(i=1;i<=N;i++)
		printf("%d ",dis3[i]);
	printf("\n");
}
void Solve()
{
	int i;
	ans=INF;
	BFS(1,dis1);
	BFS(2,dis2);
	BFS(3,dis3);
	//Print();
	for(i=1;i<=N;i++)
	{
		int a1=dis1[i];
		int a2=dis2[i];
		int a3=dis3[i];
		ans=min(ans,a1+a2+a3+1);
	}
	if(ans>=INF)
		printf("-1\n");
	else
		printf("%d\n",N-ans);
}
int main()
{
	int T,cas=0;
	scanf("%d",&T);
	while(T--)
	{
		//cas++;
		//if(cas==110)
		//	memset(temp,0,sizeof(temp));
		Init();
		Solve();
	}
return 0;
}
/*
4
4
0 0 1
4 0 1
2 3 1
2 1 3

0

3
0 0 1
4 0 1
2 0 5
0
*/