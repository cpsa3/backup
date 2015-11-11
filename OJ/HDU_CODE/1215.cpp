////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-31 21:02:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1215
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:2164KB
//////////////////System Comment End//////////////////
#include <iostream>
int v[500001]={0};
main ()
{
    int T,n,i,j;
    for(i=1;i<=500000;i++)
    {
        for(j=2;j*i<=500000;j++)
            v[j*i]+=i;
    }
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        printf("%d\n",v[n]);
    }
    return 0;
}