////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-05-21 12:20:32
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2824
////Problem Title: 
////Run result: Accept
////Run time:515MS
////Run memory:23688KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#define MAXN 3000005
using namespace std;
__int64 euler[MAXN];
void Init(int N)//求出1-N的欧拉函数值
{
    __int64 i,j;
    euler[1]=1;
    for(i=2;i<=N;i++)
    {
        if(!euler[i])
        {
            for(j=i;j<=N;j+=i)
            {
                if(!euler[j]) euler[j]=j;
                euler[j]=euler[j]/i*(i-1);
            }
        }
    }
}
int main()
{
    int i,s,e;
    Init(MAXN-1);
    while(scanf("%d%d",&s,&e)!=EOF)
    {   
        __int64 ans=0;
        for(i=s;i<=e;i++)
            ans+=euler[i];
        printf("%I64d\n",ans);
    }
return 0;
}