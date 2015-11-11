////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-11-01 20:37:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1159
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:2160KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
const int MAX=1005;
char a[MAX],b[MAX];
int  c[MAX][MAX];
int LCS(char a[],char b[],int c[MAX][MAX])//最长公共子序列
{
	int i,j;
	int n=strlen(a);
	int m=strlen(b);
	for(i=0;i<n;i++)
		c[i][0]=0;
	for(i=0;i<m;i++)
		c[0][i]=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i]==b[j])
				c[i+1][j+1]=c[i][j]+1;
			else
			{
				if(c[i][j+1]>=c[i+1][j])
					c[i+1][j+1]=c[i][j+1];
				else
					c[i+1][j+1]=c[i+1][j];
			}
		}
	}
return c[n][m];
}
main ()
{
	while(scanf("%s %s",a,b)!=EOF)
		printf("%d\n",LCS(a,b,c));
	return 0;
}