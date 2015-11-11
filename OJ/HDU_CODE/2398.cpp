////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2012-03-12 14:05:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2398
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>

double a,b,c;
int main()
{
    int i;
    while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF)
    {
        i=0;
        while(true)
        {
            if(a>=c) break;
            a=a*(1+b/100);
            i++;
        }
        printf("%d\n",i);
    }
return 0;
}