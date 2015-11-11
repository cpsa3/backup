////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-09-13 17:50:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4022
////Problem Title: 
////Run result: Accept
////Run time:359MS
////Run memory:7976KB
//////////////////System Comment End//////////////////
/*∫˙∏„+¿Î…¢ªØ*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 300005
#define INF (1<<30)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct edge
{
    int u,v,next;
}Ex[2000000],Ey[2000000];
int xhead[MAXN],xcnt;
int yhead[MAXN],ycnt;
int ans[MAXN];
bool vis[MAXN];
int xx[MAXN],yy[MAXN];
int H[MAXN];
int N,M,cnt;
void xInsert(int u,int v)
{
    Ex[xcnt].u=u;
    Ex[xcnt].v=v;
    Ex[xcnt].next=xhead[u];
    xhead[u]=xcnt++;
}
void yInsert(int u,int v)
{
    Ey[ycnt].u=u;
    Ey[ycnt].v=v;
    Ey[ycnt].next=yhead[u];
    yhead[u]=ycnt++;
}
int Binary(int x)
{
    int l,r,mid;
    l=0;r=cnt-1;
    while(l!=r)
    {
        mid=(l+r)>>1;
        if(H[mid]==x) return mid;
        if(H[mid]>x)
            r=mid;
        else
            l=mid+1;
    }
    if(H[l]==x) return l;
    return -1;
}
void Build()
{
    int i,u,v;
    for(i=1;i<=N;i++)
    {
        u=Binary(xx[i]);
        v=Binary(yy[i]);
        xInsert(u,i);
        yInsert(v,i);
    }
}
void Init()
{
    int i,n;
    cnt=0;
    memset(vis,false,sizeof(vis));
    memset(xhead,-1,sizeof(xhead));xcnt=0;
    memset(yhead,-1,sizeof(yhead));ycnt=0;
    for(i=1;i<=N;i++)
    {
        scanf("%d%d",&xx[i],&yy[i]);
        H[cnt++]=xx[i];
        H[cnt++]=yy[i];
    }
    sort(H,H+cnt);
    n=1;
    for(i=1;i<cnt;i++)
    {
        if(H[i]!=H[n-1])
            H[n++]=H[i];
    }
    cnt=n;
    Build();
}
void Solve()
{
    int i,j,c,d,u,v;
    memset(ans,0,sizeof(ans));
    for(i=1;i<=M;i++)
    {
        scanf("%d%d",&c,&d);
        u=Binary(d);
        if(u==-1) continue;
        if(c==0)
        {
            for(j=xhead[u];j!=-1;j=Ex[j].next)
            {
                v=Ex[j].v;
                if(!vis[v])
                {
                    vis[v]=true;
                    ans[i]++;
                }
            }
        }
        else
        {
            for(j=yhead[u];j!=-1;j=Ey[j].next)
            {
                v=Ey[j].v;
                if(!vis[v])
                {
                    vis[v]=true;
                    ans[i]++;
                }
            }
        }
    }
    for(i=1;i<=M;i++)
        printf("%d\n",ans[i]);
    printf("\n");
}
int main()
{
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        if(N==0&&M==0) break;
        Init();
        Solve();
    }
return 0;
}