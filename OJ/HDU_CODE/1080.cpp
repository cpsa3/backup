////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-08-21 23:34:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1080
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:268KB
//////////////////System Comment End//////////////////
/*DP¿‡À∆LCS*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#define max(a,b) (a>b?a:b)
using namespace std;
char s1[200],s2[200];
int dp[105][105];
int hash[255];
int V[5][5]={
	5,-1,-2,-1,-3,
	-1,5,-3,-2,-4,
	-2,-3,5,-2,-2,
	-1,-2,-2,5,-1,
	-3,-4,-2,-1,0 
};
int main()
{
	hash['A']=0;hash['C']=1;hash['G']=2;hash['T']=3;
	
	int T,len1,len2,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%s",&len1,s1);
		scanf("%d%s",&len2,s2);
		dp[0][0]=0;
		for(i=1;i<=len1;i++)
			dp[i][0]=dp[i-1][0]+V[hash[s1[i-1]]][4];
		for(j=1;j<=len2;j++)
			dp[0][j]=dp[0][j-1]+V[4][hash[s2[j-1]]];
		for(i=1;i<=len1;i++)
		{
			for(j=1;j<=len2;j++)
			{
				dp[i][j]=max(dp[i-1][j]+V[hash[s1[i-1]]][4],dp[i][j-1]+V[4][hash[s2[j-1]]]);
				dp[i][j]=max(dp[i][j],dp[i-1][j-1]+V[hash[s1[i-1]]][hash[s2[j-1]]]);
				//printf("%d ",dp[i][j]); 
			}
			//printf("\n"); 
		}
		//printf("----------------\n");
		printf("%d\n",dp[len1][len2]);
	}
	return 0;
}