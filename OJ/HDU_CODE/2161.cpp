////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-11-28 20:29:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2161
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>
int f(int n)
{
    int i,flag=0;
    if(n==1||n==2) return 0;
    for(i=2;i<=sqrt((double)n);i++)
        if(n%i==0)
        {flag=1;break;}
        if(flag)
            return 0;
        return 1;
}
int main ()
{
    int n,k=1;
    while(scanf("%d",&n)!=EOF)
    {
        if(n<=0) break;
        printf("%d: ",k++);
        if(f(n))
            printf("yes\n");
        else
            printf("no\n");
    }
return 0;
}