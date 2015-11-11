////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-17 19:25:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2013
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int f(int n)
{ 
    int s;
    if(n==1)
        s=1;
    else
        s=(f(n-1)+1)*2;
return s;
}
int main ()
{
    int a;
    while(scanf("%d",&a)!=EOF)
    {
        printf("%d\n",f(a));
    }
return 0;

}