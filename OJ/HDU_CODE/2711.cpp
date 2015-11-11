////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2012-03-12 14:14:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2711
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:508KB
//////////////////System Comment End//////////////////
#include <iostream>
#define lch(a) (2*(a))
#define rch(a) (2*(a)+1)
#define MAXN 20005
struct Tree
{
    int s,e,len; 
}Tnode[3*MAXN];
int S[MAXN];
int ans[MAXN];

void Build(int p,int s,int e)
{
    Tnode[p].s=s;
    Tnode[p].e=e;
    Tnode[p].len=e-s+1;
    if(s==e)
        return;
    int mid=(s+e)>>1;
    Build(lch(p),s,mid);
    Build(rch(p),mid+1,e);
}

int Find(int p,int s,int e,int v)
{
    int mid=(Tnode[p].s+Tnode[p].e)>>1;
    Tnode[p].len--;
    if(Tnode[p].s==Tnode[p].e)
        return Tnode[p].s;
    if(Tnode[lch(p)].len>=v)
        return Find(lch(p),s,mid,v);
    else
        return Find(rch(p),mid+1,e,v-Tnode[lch(p)].len);
}

int main ()
{
    int N,i;
    while(scanf("%d",&N)!=EOF)
    {
    for(i=2;i<=N;i++)
        scanf("%d",&S[i]);
    Build(1,1,N);
    for(i=N;i>=2;i--)
        ans[i]=Find(1,1,N,S[i]+1);
    ans[1]=Find(1,1,N,1);
    for(i=1;i<=N;i++)
        printf("%d\n",ans[i]);
    }
return 0;
}