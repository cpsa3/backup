////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-29 18:20:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3826
////Problem Title: 
////Run result: Accept
////Run time:265MS
////Run memory:260KB
//////////////////System Comment End//////////////////
/*
思路：
N=a^2*b;且a,b中至少有一个<=（Lim=pow(N,1/3)）；
所以只要从2-Lim枚举
*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cmath>
using namespace std;
__int64 N,a,t;
int main()
{
    int T,cas=1,i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d",&N);
        __int64 Lim=(__int64)(pow(N*1.0,1.0/3))+1;
        bool ok=true;
        a=(__int64)(sqrt(N*1.0));
        if(a*a==N)//注意特判49
        {
            printf("Case %d: No\n",cas++);
            continue;
        }
        for(i=2;i<=Lim+1;i++)
        {
            //if(N%a==0) {ok=false;break;}
            if(N%i==0)
            {
                t=N/i;
                if(t%i==0) {ok=false;break;}
                a=(__int64)sqrt(t*1.0);
                if(a*a==t&&a>1)
                {ok=false;break;}
            }
        }
        if(ok) printf("Case %d: Yes\n",cas++);
        else printf("Case %d: No\n",cas++);
    }
return 0;
}