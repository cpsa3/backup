////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
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
	if(dp[x][y]!=-1) return dp[x][y];//����Ѿ������ֱ�ӷ���ֵ��������֦
	for(i=0;i<4;i++)//�������ĸ��������п����ߵ��ĵ���һ������dp[dx][dy]
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
	dp[x][y]=sum+map[x][y];//dp[x][y]���������(x,y)��㿪ʼ���ܳԵ������ֵ
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
			memset(dp,-1,sizeof(dp));//��ʼ��
			printf("%d\n",dfs(1,1));
	}
return 0;
}