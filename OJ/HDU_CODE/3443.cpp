////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-08-25 21:22:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3443
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    __int64 N;
    while(scanf("%I64d",&N),N)
    {
        __int64 i;
        __int64 ans;
        for(i=1;i<=N;i=i*10+1)
        {
             if(N%i==0)
             ans=N/i;
        }
        printf("%I64d\n",ans);
    }
return 0;
}