////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-08-19 01:08:26
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3953
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s1[200],s2[200];
int main()
{
    int T,i;
    int cas=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s%s",s1,s2);
        int len1=strlen(s1);
        int len2=strlen(s2);
        __int64 ans=0;
        for(i=0;i<len1;i++)
            ans+=s1[i]-'0';
        for(i=0;i<len2;i++)
            ans+=s2[i]-'0';
        printf("Case %d: %I64d\n",cas++,ans);
    }
return 0;
}