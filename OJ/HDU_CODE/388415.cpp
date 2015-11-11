////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-08-11 22:43:06
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
#define min(a,b) (a<b?a:b)
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
    int i,j,k,now,t;
    __int64 M,d1,d2;
    
    ans=0;
    for(i=1;i<=N;i++)
    {
        k=i-1;j=i+1;
        M=K;now=node[i].p;
        while(true)
        {
            if(k<1&&j<=N) 
            {
                d1=INF;
                d2=node[j].x-node[i].x;
            }
            else if(k>=1&&j>N)
            {
                d1=node[i].x-node[k].x;
                d2=INF;
            }
            else if(k>=1&&j<=N)
            {
                d1=node[i].x-node[k].x;
                d2=node[j].x-node[i].x;
            }
            else break;
            if(d1<=d2)
            {
                if(d1*node[k].p<=M)
                    t=node[k].p;
                else
                    t=M/d1;
                
                M-=t*d1;
                now+=t;
				if(t<node[k].p) break;
                k--;
                
            }
            else
            {
                if(d2*node[j].p<=M)
                    t=node[j].p;
                else
                    t=M/d2;
                
                M-=t*d2;
                now+=t;
				if(t<node[j].p) break;
                j++;
                
            }
        }
        //printf("*%I64d\n",now);
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