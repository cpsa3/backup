////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-21 19:17:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1072
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:256KB
//////////////////System Comment End//////////////////
/*记忆化搜索*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define INF 1e8
#define min(a,b) (a<b?a:b)
using namespace std;
int map[20][20];
int N,M;
int sx,sy,ans;
int dp[20][20][7];
bool vis[20][20];
int dir[4][2]={0,1,0,-1,1,0,-1,0};
void Init()
{
	int i,j;
	scanf("%d%d",&N,&M);
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=M;j++)
		{
			scanf("%d",&map[i][j]);
			if(map[i][j]==2)
			{
				sx=i;
				sy=j;
			}
		}
	}
}
bool Judge(int x,int y)
{
	if(x>=1&&x<=N&&y>=1&&y<=M)
		return true;
	return false;
}
void dfs(int x,int y,int t,int step)
{
	int i;
	if(map[x][y]==3)
	{
		ans=min(ans,step);
		return;
	}
	if(t==1) return;
	if(dp[x][y][t]!=-1&&dp[x][y][t]<=step) 
		return;
	dp[x][y][t]=step;//表示从起点走到该状态所需的最少步数

	for(i=0;i<4;i++)
	{
		int dx=x+dir[i][0];
		int dy=y+dir[i][1];
		if(Judge(dx,dy)&&map[dx][dy]!=0)
		{
			if(map[dx][dy]==4)
			{
				//vis[dx][dy]=true;
				dfs(dx,dy,6,step+1);
				//vis[dx][dy]=false;
			}
			else 
			{
				dfs(dx,dy,t-1,step+1);
			}
		}
	}
}
void Solve()
{
	memset(dp,-1,sizeof(dp));
	memset(vis,false,sizeof(vis));
	ans=INF;
	dfs(sx,sy,6,0);
	if(ans==INF) ans=-1;
	printf("%d\n",ans);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		Init();
		Solve();
	}
return 0;
}