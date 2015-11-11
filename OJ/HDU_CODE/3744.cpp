////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-25 19:55:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3744
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdlib.h>
using namespace std;
struct px
{
    int x,r,s;
};
struct px stu[105];
int cmp(const void *p1,const void *p2)
{
    return ((struct px *)p1)->r-((struct px *)p2)->r;
}
int main()
{
    int T,n,m,q,lens,i,j,flag;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        q=m/400;
        for(i=1;i<=n;i++)
            scanf("%d%d",&stu[i].x,&stu[i].r);
        qsort(stu+1,n,sizeof(stu[0]),cmp);
        stu[1].s=q*400+stu[1].x;
        if(stu[1].s>m)
            stu[1].s-=400;
        for(i=2;i<=n;i++)
        {
            lens=stu[i-1].s;
            flag=0;
            for(j=q;j>=0;j--)
            {
                if((j*400+stu[i].x)<lens)
                {
                    stu[i].s=j*400+stu[i].x;
                    flag=1;
                    break;
                }
            }
            if(!flag)
                break;
        }
        if(!flag)
            printf("NO\n");
        else
            printf("YES\n");
    
    }
return 0;
}