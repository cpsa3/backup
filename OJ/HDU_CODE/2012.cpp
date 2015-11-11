////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-17 19:24:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2012
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int f(int n)
{
    int i;
    if(n==1) return 0;
    for(i=2;i<n;i++)
        if(n%i==0)
            break;
        if(i==n) return 1;
        else return 0;
}

main ()
{
    int x,y,m,i;
    while(scanf("%d%d",&x,&y)!=EOF)
    {
        if(x==0&&y==0)
            break;
        for(i=x;i<=y;i++)
        {
            m=i*i+i+41;
            if(f(m)==0) break;
        }
        if(i==y+1) printf("OK\n");
        else printf("Sorry\n");

    }
return 0;
}