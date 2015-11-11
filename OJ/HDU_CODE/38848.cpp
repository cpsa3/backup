////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-08-11 22:19:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3884
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:264KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#define MAXN 10006
#define INF 1e9
#define max(a,b) (a>b?a:b)
using namespace std;
struct Node
{
    int x,p;
}node[MAXN];
int N;
__int64 K,ans;
int cmp(const void *p1,const void *p2)
{
    return ((struct Node *)p1)->x-((struct Node *)p2)->x;
}
void Init()
{
    int i;
    for(i=1;i<=N;i++)
        scanf("%d%d",&node[i].x,&node[i].p);
    qsort(node+1,N,sizeof(node[0]),cmp);
}
void Solve()
{
    int i,j,k,d1,d2;
    __int64 now,M,t;
    ans=0;
    for(i=1;i<=N;i++)
    {
        k=i-1;j=i+1;
        M=K;now=node[i].p; 
        while(true)
        {
            if(k==0&&j==N+1) break;
            if((j==N+1)||((k!=0)&&(node[i].x-node[k].x<node[j].x-node[i].x)))
            {
                if(__int64(node[i].x-node[k].x)*node[k].p>M)
                {
                    now+=M/(node[i].x-node[k].x);
                    break; 
                }
                else
                {
                    now+=node[k].p;
                    M-=__int64(node[i].x-node[k].x)*node[k].p;
                    k--;  
                } 
            }
            else
            {
                if(__int64(node[j].x-node[i].x)*node[j].p>M)
                {
                    now+=M/(node[j].x-node[i].x);
                    break; 
                }
                else
                {
                    now+=node[j].p;
                    M-=__int64(node[j].x-node[i].x)*node[j].p;
                    j++;
                }
            }
        }
        //if(now>ans) ans=now;
        ans=max(ans,now);
    }
    printf("%I64d\n",ans);
}
int main()
{
    while(scanf("%d%I64d",&N,&K)!=EOF)
    {
        Init();
        Solve();
    }
return 0;
}