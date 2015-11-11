////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-09-02 18:22:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3996
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:1728KB
//////////////////System Comment End//////////////////
/*最大权闭合图*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <vector>
#define MAXN 3000
#define INF (((__int64)1)<<50)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct Node
{
    int a,b;
};
struct edge
{
    int u,v,next;
    __int64 w;
}E[2000000];
int head[MAXN],ecnt;
int N,scr,sink,vn,cas,cnt;
int Num[105],Sum[105];
__int64 W[MAXN],S;
int gap[MAXN],cur[MAXN],dis[MAXN],pre[MAXN];
vector<Node>V[MAXN];
void Insert(int u,int v,__int64 w)
{
    E[ecnt].u=u;
    E[ecnt].v=v;
    E[ecnt].w=w;
    E[ecnt].next=head[u];
    head[u]=ecnt++;
    E[ecnt].u=v;
    E[ecnt].v=u;
    E[ecnt].w=0;
    E[ecnt].next=head[v];
    head[v]=ecnt++;
}
void Init()
{
    int i,j,k,m,c,d,id;
    __int64 a,b;
    Node u;
    scanf("%d",&N);
    for(i=1;i<MAXN;i++)
        V[i].clear();
    memset(Sum,0,sizeof(Sum));
    for(i=1;i<=N;i++)
    {
        scanf("%d",&Num[i]);
        Sum[i]=Sum[i-1]+Num[i];
        for(j=1;j<=Num[i];j++)
        {
            id=Sum[i-1]+j;
            scanf("%I64d%I64d%d",&a,&b,&m);
            W[id]=b-a;
            for(k=1;k<=m;k++)
            {
                scanf("%d%d",&u.a,&u.b);
                V[id].push_back(u);
            }
        }
    }
    cnt=Sum[N];
}
void Build()
{
    int i,j,size,id;
    S=0;
    memset(head,-1,sizeof(head));ecnt=0;
    scr=0;sink=cnt+1;vn=sink+1;
    for(i=1;i<=cnt;i++)
    {
        if(W[i]>0)
        {
            Insert(scr,i,W[i]);
            S+=W[i];
        }
        else if(W[i]<0)
        {
            Insert(i,sink,-W[i]);
        }
        size=V[i].size();
        for(j=0;j<size;j++)
        {
            id=Sum[V[i][j].a-1]+V[i][j].b;
            Insert(i,id,INF);
        }
    }
}
__int64 Sap(int s,int t,int n)//核心代码(模版)
{
    __int64 ans=0,aug=INF;//aug表示增广路的流量
    int i,v,u=pre[s]=s;
    for(i=0;i<=n;i++)
    {
        cur[i]=head[i];
        dis[i]=gap[i]=0;
    }
    gap[s]=n;
    bool flag;
    while(dis[s]<n)
    {
        flag=false;
        for(int &j=cur[u];j!=-1;j=E[j].next)//一定要定义成int &j,why
        {
            v=E[j].v;
            if(E[j].w>0&&dis[u]==dis[v]+1)
            {
                flag=true;//找到容许边
                aug=min(aug,E[j].w);
                pre[v]=u;
                u=v;
                if(u==t)
                {
                    ans+=aug;
                    while(u!=s)
                    {
                        u=pre[u];
                        E[cur[u]].w-=aug;
                        E[cur[u]^1].w+=aug;//注意
                    }
                    aug=INF;
                }
                break;//找到一条就退出
            }
        }
        if(flag) continue;
        int mindis=n;
        for(i=head[u];i!=-1;i=E[i].next)
        {
            v=E[i].v;
            if(E[i].w>0&&dis[v]<mindis)
            {
                mindis=dis[v];
                cur[u]=i;
            }
        }
        if((--gap[dis[u]])==0) break;
        gap[dis[u]=mindis+1]++;
        u=pre[u];
    }
    return ans;
}
void Solve()
{
    Build();//建图
    __int64 ans=Sap(scr,sink,vn);
    ans=S-ans;
    printf("Case #%d: %I64d\n",cas++,ans);
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