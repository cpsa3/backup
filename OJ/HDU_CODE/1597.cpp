////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-08-29 01:08:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1597
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <cmath>
using namespace std;
__int64 N;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d",&N);
        __int64 n=(__int64)((sqrt(1+8.0*N)-1)*0.5);
        __int64 t=(1+n)*n/2;
        if(N!=t)
            n=N-t;
        printf("%I64d\n",(n-1)%9+1);
    }
return 0;
}