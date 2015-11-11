////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-10 10:20:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1789
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdlib.h>
using namespace std;
struct px
{
    int dl;
    int re;
};
int cmp(const void *x,const void *y)
{
    if(((struct px *)x)->dl!=((struct px *)y)->dl)
        return ((struct px *)x)->dl-((struct px *)y)->dl;
    else
        return ((struct px *)y)->re-((struct px *)y)->re;
}
struct px stu[1001];
main()
{
    int t,n,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&stu[i].dl);
        for(i=1;i<=n;i++)
            scanf("%d",&stu[i].re);
        qsort(stu+1,n,sizeof(stu[0]),cmp);
        int sum=0;
        for(i=1;i<=n;i++)
        {
            if(stu[i].dl<i)
            {
                int min=stu[1].re,a=1;
                for(j=1;j<=i;j++)
                    if(min>stu[j].re)
                    {min=stu[j].re;a=j;}
                    sum+=min;
                    stu[a]=stu[i];
                    for(j=i;j<=n-1;j++)
                        stu[j]=stu[j+1];
                    n--;
                    i--;
            }
        }
        printf("%d\n",sum);
    }
return 0;
}