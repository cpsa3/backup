////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-09-08 10:14:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4020
////Problem Title: 
////Run result: Accept
////Run time:4281MS
////Run memory:16268KB
//////////////////System Comment End//////////////////
/*HDU_4020 Ads Proposal*/
/*∏¥‘”∂»O(NlogN)*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 100005
using namespace std;
__int64 ans[500005];
int num[MAXN];
struct Node
{
    int u;
    __int64 c,l;
}node[500005];
int N,M,Q,cas;
int cmp(const void *p1,const void *p2)
{
    return ((struct Node *)p2)->c-((struct Node *)p1)->c;
}
inline int Scan()
{
    int res=0,ch;
    while(!((ch=getchar())>='0'&&ch<='9'))
    {
        if(ch==EOF) return 1<<30;
    }
    res=ch-'0';
    while((ch=getchar())>='0'&&ch<='9')
        res=res*10+(ch-'0');
    return res;
}
void Init()
{
    int i,t;
    N=Scan();M=Scan();Q=Scan();
    for(i=1;i<=M;i++)
    {
        node[i].u=Scan();
        t=Scan();
        node[i].c=(__int64)(t);
        t=Scan();
        node[i].l=(__int64)(t);
    }
    qsort(node+1,M,sizeof(node[0]),cmp);
}
void Solve()
{
    int i,j,u,K;
    memset(num,0,sizeof(num));
    memset(ans,0,sizeof(ans));
    for(i=1;i<=M;i++)
    {
        u=node[i].u;
        num[u]++;
        ans[num[u]]+=node[i].l;
    }
    for(i=1;i<=M;i++)
        ans[i]+=ans[i-1];
    printf("Case #%d:\n",cas++);
    while(Q--)
    {
        K=Scan();
        if(K>M) K=M;
        printf("%I64d\n",ans[K]);
    }
}
int main()
{
    int T;
    cas=1;
    scanf("%d",&T);
    while(T--)
    {
        Init();
        Solve();
    }
return 0;
}