////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-21 11:41:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1057
////Problem Title: 
////Run result: Accept
////Run time:203MS
////Run memory:212KB
//////////////////System Comment End//////////////////
/*模拟题*/
/*AC代码：203ms*/
#include <iostream>
int map[25][25],temp[25][25];
int d[25];
int main()
{
	int T,i,j,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		//printf("*%d\n",n);
		for(i=0;i<16;i++)
			scanf("%d",&d[i]);
		for(i=1;i<=20;i++)
		{
			for(j=1;j<=20;j++)
			{
				scanf("%d",&map[i][j]);
				temp[i][j]=map[i][j];
			}
		}
		//printf("*%d\n",n);
		while(n--)
		{
			
			for(i=1;i<=20;i++)
			{
				for(j=1;j<=20;j++)
				{
					int sum=temp[i][j]+temp[i-1][j]+temp[i+1][j]+temp[i][j-1]+temp[i][j+1];
					sum=temp[i][j]+d[sum];
					if(sum>3) sum=3;
					if(sum<0) sum=0;
					map[i][j]=sum;
				}
			}
			for(i=1;i<=20;i++)
				for(j=1;j<=20;j++)
					temp[i][j]=map[i][j];
		}
		for(i=1;i<=20;i++)
		{
			for(j=1;j<=20;j++)
			{
				if(map[i][j]==0)
					printf(".");
				else if(map[i][j]==1)
					printf("!");
				else if(map[i][j]==2)
					printf("X");
				else
					printf("#");
			}
			printf("\n");
		}
		if(T) printf("\n");//注意
	} 
	return 0;
}
