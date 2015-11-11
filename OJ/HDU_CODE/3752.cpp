////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-25 19:58:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3752
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <iostream>
int main()
{
    int T,i,j,n,m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&m,&n);
        if(m<2*n)
        {printf("NO\n");continue;}
        if(m%2)
            printf("NO\n");
        else
            printf("YES\n");
    }
return 0;
}