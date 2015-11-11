////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-31 21:00:49
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1977
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
main ()
{
    int T;
    __int64 n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d",&n);
        __int64 a,b;
        a=n*n*n;
        b=(n+1)*(n+1)*(n+1);
        printf("%I64d %I64d\n",a,b);
    }
return 0;
}