////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-09-14 18:19:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3422
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
__int64 n,a,b,c;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        a=2*(1+n)*n;
        c=a+1;
        b=c*c-a*a;
        b=sqrt(b*1.0);
        printf("%I64d %I64d\n",a+b+c-3,c);
    }
return 0;
}