////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-10-14 15:06:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1041
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:2172KB
//////////////////System Comment End//////////////////
#include <iostream>
int f[1001][501]={0};//用整型数组来进行高精度储存
main ()
{
	int i,j,n,w;
	f[1][0]=0;f[2][0]=f[3][0]=1;
	for(i=4;i<=1000;i++)
		for(j=0,w=0;j<=500;j++)
		{
			f[i][j]=f[i-1][j]+2*f[i-2][j]+w;
			w=f[i][j]/10;//储存进位
			f[i][j]%=10;
		}
		while(scanf("%d",&n)!=EOF)
		{
			if(n==1)
			{printf("0\n");continue;}
			else
			{
				int k=0;
				for(j=500;j>=0;j--)
					if(f[n][j]||k)
					{printf("%d",f[n][j]);k=1;}
					printf("\n");
			}
		}
return 0;
}