////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-28 21:48:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3313
////Problem Title: 
////Run result: Accept
////Run time:390MS
////Run memory:2892KB
//////////////////System Comment End//////////////////
/*有向图割点(两次BFS)*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 100007
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define INF 1e8
using namespace std;
struct edge
{
    int v,next;
}E[300008];
int head[MAXN],ecnt;
int Q[MAXN],pre[MAXN],low[MAXN];
bool vis[MAXN];
int N,M,scr,sink,Head,Tail,cnt;
void Insert(int u,int v)
{
    E[ecnt].v=v;
    E[ecnt].next=head[u];
    head[u]=ecnt++;
}
bool BFS1()
{
    int i,u,v;
    memset(vis,false,sizeof(vis));
    Head=Tail=0;
    Q[Head++]=scr;
    vis[scr]=true;
    pre[scr]=-1;
    while(Head!=Tail)
    {
        u=Q[Tail++];
        for(i=head[u];i!=-1;i=E[i].next)
        {
            v=E[i].v;
            if(!vis[v])
            {
                pre[v]=u;
                vis[v]=true;
                Q[Head++]=v;
                if(v==sink) return true;
            }
        }
    }
    return false;
}
int BFS2(int s)
{
    int i,u,v;
    int res=s;
    Head=Tail=0;
    Q[Head++]=s;
    vis[s]=true;
    while(Head!=Tail)
    {
        u=Q[Tail++];
        for(i=head[u];i!=-1;i=E[i].next)
        {
            v=E[i].v;
            if(!vis[v])
            {
                vis[v]=true;
                if(low[v]==0) Q[Head++]=v;//不是在最短路上的点进行拓展
                else if(low[v]<low[res])//取一个low最小的点
                    res=v;
            }
        }
    }
    return res;
}
int Scan()//输入外挂
{
    int res=0,ch;
    while(!((ch=getchar())>='0'&&ch<='9'));
        res=ch-'0';
    while((ch=getchar())>='0'&&ch<='9')
        res=res*10+(ch-'0');
    return res;
}
void Init()
{
    int i,u,v;
    memset(head,-1,sizeof(head));ecnt=0;
    memset(low,0,sizeof(low));
    for(i=1;i<=M;i++)
    {
        //scanf("%d%d",&u,&v);
        u=Scan();v=Scan();
        Insert(u,v);
    }
    scanf("%d%d",&scr,&sink);
}
void Solve()
{
    int i,u;
    if(N==0||N==1||!BFS1())
    {printf("%d\n",N);return;}
    cnt=0;
    u=sink;
    while(true)
    {
        low[u]=++cnt;
        u=pre[u];
        if(u==-1) break;
    }
    int ans=1;
    u=scr;
    memset(vis,false,sizeof(vis));
    while(u!=sink)
    {
        u=BFS2(u);
        ans++;
    }
    printf("%d\n",ans);
}
int main()
{
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        Init();
        Solve();
    }
return 0;
}