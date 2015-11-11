////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-21 03:08:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1044
////Problem Title: 
////Run result: Accept
////Run time:609MS
////Run memory:240KB
//////////////////System Comment End//////////////////
/*BFS+DFS*/
/*AC代码：15ms*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <queue>
#define MAXN 55
#define INF 1e8
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct Node
{
	int x,y,step; 
	Node(int x1,int y1,int step1)
	{x=x1;y=y1;step=step1;}
	Node(){}
};
struct Node node[MAXN];
int H,W,M,cas,L,ans;
char map[MAXN][MAXN];
int V[20];
int dis[MAXN][MAXN];
bool mark[MAXN][MAXN],vis[MAXN];
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int take[MAXN];
bool ok;
void Init()
{
	int i,j;
	scanf("%d%d%d%d",&W,&H,&L,&M);
	for(i=1;i<=M;i++)
		scanf("%d",&V[i]);
	for(i=0;i<H;i++)
		scanf("%s",map[i]);
	for(i=0;i<H;i++)
	{
		for(j=0;j<W;j++)
		{
			if(map[i][j]=='@') 
			{
				node[0].x=i;
				node[0].y=j; 
			}
			else if(map[i][j]=='<')
			{
				node[M+1].x=i;
				node[M+1].y=j; 
			}
			else if(map[i][j]>='A'&&map[i][j]<='Z')
			{
				int id=map[i][j]-'A'+1;
				node[id].x=i;
				node[id].y=j;
			}
		}
	} 
}
bool Judge(int x,int y)
{
	if(x>=0&&x<H&&y>=0&&y<W)
		return true;
	return false;
}
queue<Node>Q;
void BFS(int ith)
{
	int i,step,id;
	Node u,v;
	while(!Q.empty()) Q.pop();
	memset(mark,false,sizeof(mark));
	u=node[ith];
	u.step=0;
	Q.push(u);
	mark[u.x][u.y]=true;
	while(!Q.empty())
	{
		u=Q.front();Q.pop();
		step=u.step+1;
		for(i=0;i<4;i++)
		{
			int dx=u.x+dir[i][0];
			int dy=u.y+dir[i][1];
			if(Judge(dx,dy)&&!mark[dx][dy]&&map[dx][dy]!='*')
			{
				mark[dx][dy]=true;
				if(map[dx][dy]=='@')
					dis[ith][0]=dis[0][ith]=step;
				else if(map[dx][dy]=='<')
					dis[ith][M+1]=dis[M+1][ith]=step;
				else if(map[dx][dy]>='A'&&map[dx][dy]<='Z')
				{
					id=map[dx][dy]-'A'+1;
					dis[ith][id]=dis[id][ith]=step;
				}
				Q.push(Node(dx,dy,step));
			}
		}
	}
}
void Run()
{
	int i,j;
	for(i=0;i<=M+1;i++)
	{
		for(j=0;j<=M+1;j++)
		{
			dis[i][j]=INF; 
		}
		dis[i][i]=0;
	}
	for(i=0;i<=M+1;i++)
		BFS(i);
}
void dfs(int take[],int cnt,int value,int cost,bool vis[])
{
	int i;
	//if(ok) return;//剪枝：如果已经拿到所有宝物就停止 
	if(cost+dis[take[cnt]][M+1]>L) return; //剪枝
	ans=max(ans,value);
	if(cnt==M) 
	{
		ok=true;
		return; 
	}
	int u=take[cnt],v;
	for(i=1;i<=M;i++)
	{
		if(!vis[i])
		{
			vis[i]=true;
			take[++cnt]=i;
			v=take[cnt];
			dfs(take,cnt,value+V[i],cost+dis[u][v],vis);
			vis[i]=false;
			cnt--;
		}
	}
}
void Print()
{
	int i,j;
	printf("------------------------\n");
	for(i=0;i<=M+1;i++)
	{
		for(j=0;j<=M+1;j++)
			printf("%d ",dis[i][j]);
		printf("\n"); 
	}
	printf("------------------------\n");
}
void Solve()
{
	Run();//BFS预处理
	//Print();
	printf("Case %d:\n",cas++);
	if(dis[0][M+1]>L)
	{printf("Impossible\n");return;}
	ans=0;
	memset(vis,false,sizeof(vis));
	take[0]=0;
	ok=false;
	dfs(take,0,0,0,vis);
	printf("The best score is %d.\n",ans); 
}
int main()
{
	int T;
	cas=1;
	scanf("%d",&T);
	while(T--)
	{
		if(cas!=1)
			printf("\n");
		Init();
		Solve();
	}
return 0;
}