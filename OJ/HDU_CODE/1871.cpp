////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-11-29 22:30:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1871
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:268KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cstdlib>
using namespace std;

struct Node
{
    int id,num,w;
}node[105];
int C,M;
int cmp(const void *p1,const void *p2)
{
    return ((struct Node *)p1)->w-((struct Node *)p2)->w;    
}
void Init()
{
    int i;
    scanf("%d",&C);
    for(i=1;i<=C;i++)
        scanf("%d%d%d",&node[i].id,&node[i].num,&node[i].w);
    qsort(node+1,C,sizeof(node[0]),cmp);
}
void Solve()
{
    int i,j,num;
    scanf("%d",&M);
    for(i=1;i<=M;i++)
    {
        scanf("%d",&num);
        bool ok=false;
        for(j=1;j<=C;j++)
        {
            if(node[j].num>=num)
            {
                ok=true;
                printf("%d\n",node[j].id);
                node[j].num-=num;
                break;
            }
        }
        if(!ok) printf("sorry\n");
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        Init();
        Solve();
    }
    return 0;
}