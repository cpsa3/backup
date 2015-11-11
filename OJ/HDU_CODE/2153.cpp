////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-11-28 20:30:32
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2153
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <iostream>
int main ()
{
    int n,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==1)
        {printf("%3d\n",n);continue;}
        if(n==0)
            continue;
        int m=4*n-4;
        for(i=1;i<=n;i++)
            printf("%3d",i);
        printf("\n");
        for(i=1;i<=n-2;i++)
        {
            printf("%3d",m-i+1);
                for(j=1;j<=3*(n-2);j++)
                    printf(" ");
                printf("%3d\n",n+i);
        }
        int w=3*n-2;
        for(i=1;i<=n;i++)
            printf("%3d",w-i+1);
        printf("\n");
    }
return 0;
}
