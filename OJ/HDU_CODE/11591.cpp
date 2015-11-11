////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-10-05 13:52:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1159
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:4188KB
//////////////////System Comment End//////////////////
/*HDU_1159 Common Subsequence*/
/*最长公共子串*/
/*
思路：
(1):状态 dp[i][j]:表示字符串s1的前i个和字符串s2的前j个字符的最长公共子串
(2):状态转移： dp[i][j]=max(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]+s[i]==s[j]);
(3):复杂度： O(n^2)
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <cstring>
#define MAXN 1005
#define INF (1<<30)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;

int dp[MAXN][MAXN];
char s1[MAXN],s2[MAXN];

int LCS(char s1[],char s2[])
{
    int i,j,k;
    int len1=strlen(s1);
    int len2=strlen(s2);
    memset(dp,-1,sizeof(dp));
    for(i=0;i<=len1;i++)
        dp[i][0]=0;
    for(i=0;i<=len2;i++)
        dp[0][i]=0;
    for(i=1;i<=len1;i++)
    {
        for(j=1;j<=len2;j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            dp[i][j]=max(dp[i][j],dp[i-1][j-1]+(s1[i-1]==s2[j-1]));
        }
    }
    return dp[len1][len2];
}
int main()
{
    while(scanf("%s%s",s1,s2)!=EOF)
    {
        int ans=LCS(s1,s2);
        printf("%d\n",ans);
    }
return 0;
}
