////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-29 19:11:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2078
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include"stdio.h"
 
void main()
{
    int n,m,s,temp,max,t;
    while(scanf("%d",&t)!=EOF)
    {
        for(int i=0;i<t;i++)
        {
            scanf("%d%d",&n,&m);
            for(int j=0,s=100;j<n;j++)
            {
                scanf("%d",&temp);
                if(s>temp) s=temp;
            }
            max=(100-s)*(100-s);
            printf("%d\n",max);
        }
    }
}