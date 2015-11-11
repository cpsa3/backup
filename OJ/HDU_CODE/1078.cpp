////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-11-03 13:00:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1078
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:288KB
//////////////////System Comment End//////////////////
#include <iostream>
int dp[101][101],map[101][101],N,K;
int dir[4][2]={1,0,-1,0,0,1,0,-1};
int dfs(int x,int y)
{
	int i,j,temp,sum=0;
	if(dp[x][y]!=-1) return dp[x][y];//如果已经计算过直接返回值，用来剪枝
	for(i=0;i<4;i++)//否则，向四个方向所有可能走到的点找一个最大的dp[dx][dy]
	{
		for(j=1;j<=K;j++)
		{
			int dx=x+j*dir[i][0];
			int dy=y+j*dir[i][1];
			if(dx>=1&&dx<=N&&dy>=1&&dy<=N&&map[dx][dy]>map[x][y])
			{
				temp=dfs(dx,dy);
				if(sum<temp)
					sum=temp;
			}
		}
	}
	dp[x][y]=sum+map[x][y];//dp[x][y]用来保存从(x,y)这点开始走能吃到的最大值
 return dp[x][y];
}
main ()
{
	int i,j;
	while(scanf("%d%d",&N,&K)!=EOF)
	{
		if(N==-1&&K==-1) break;
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				scanf("%d",&map[i][j]);
			memset(dp,-1,sizeof(dp));//初始化
			printf("%d\n",dfs(1,1));
	}
return 0;
}