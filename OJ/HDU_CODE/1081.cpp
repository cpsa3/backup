////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-21 11:49:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1081
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:296KB
//////////////////System Comment End//////////////////
/*DP+枚举*/
#include <iostream>
#define INF 0x7fffffff 
#define MAXN 105
int map[MAXN][MAXN];
int sum[MAXN][MAXN];//sum[i][j]记录(1,1)->(i,j)的元素之和；
int N;
void Init()
{
	int i,j,temp;
	for(i=1;i<=N;i++)
	{
		for(j=1,temp=0;j<=N;j++)
		{
			scanf("%d",&map[i][j]);
			temp+=map[i][j];
			if(i>1)
				sum[i][j]=sum[i-1][j]+temp;
			else
				sum[i][j]=temp;
		}
	}
}
void Solve()
{
	int i,j,k,m,ans=-INF;
	for(i=1;i<=N;i++)//枚举矩形
	{
		for(j=1;j<=N;j++)
		{
			for(k=i+1;k<=N;k++)
			{
				for(m=j+1;m<=N;m++)
				{
					int temp=sum[k][m];
					if(i>1)
						temp-=sum[i-1][m];
					if(j>1)
						temp-=sum[k][j-1];
					if(i>1&&j>1)
						temp+=sum[i-1][j-1];
					if(temp>ans)
						ans=temp; 
				}
			}
		}
	}
	printf("%d\n",ans);
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