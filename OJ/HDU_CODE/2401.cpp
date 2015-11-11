////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-31 21:01:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2401
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
main ()
{
    int n,w,d,s,i;
    while(scanf("%d%d%d%d",&n,&w,&d,&s)!=EOF)
    {
        int temp=0;
        for(i=1;i<n;i++)
            temp+=i;
        if((temp*w-s)==0)
            printf("%d\n",n);
        else
        printf("%d\n",(temp*w-s)/d);
    }
return 0;
}