////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2012-03-12 14:02:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1533
////Problem Title: 
////Run result: Accept
////Run time:437MS
////Run memory:684KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cmath>
#include <queue>
#define MAXN 250
#define INF (1<<30)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;

struct Point
{
    int x,y;
}Pn[MAXN],Pm[MAXN];
struct Node 
{
    int u,v,w,c,next;
}E[200000];
int head[MAXN],ecnt;
int pre[MAXN],dis[MAXN];
bool vis[MAXN];
int N,M,nn,mm,scr,sink,vn,cnt;
char map[105][105];
void Insert(int u,int v,int w,int c)
{
    E[ecnt].u=u;
    E[ecnt].v=v;
    E[ecnt].w=w;
    E[ecnt].c=c;
    E[ecnt].next=head[u];
    head[u]=ecnt++;
    E[ecnt].u=v;
    E[ecnt].v=u;
    E[ecnt].w=0;
    E[ecnt].c=-c;
    E[ecnt].next=head[v];
    head[v]=ecnt++;
}
void Init()
{
    int i,j;
    for(i=0;i<nn;i++)
        scanf("%s",map[i]);
    int nx=1,ny=1;
    for(i=0;i<nn;i++)
    {
        for(j=0;j<mm;j++)
        {
            if(map[i][j]=='m')
            {
                Pn[nx].x=i;Pn[nx].y=j;
                nx++;
            }
            else if(map[i][j]=='H')
            {
                Pm[ny].x=i;Pm[ny].y=j;
                ny++;
            }
        }
    }
    cnt=nx-1;
}
int d(int a,int b)
{
    return abs(Pn[a].x-Pm[b].x)+abs(Pn[a].y-Pm[b].y);
}
void Print()
{
    int i,j;
    for(i=1;i<=cnt;i++)
    {
        for(j=1;j<=cnt;j++)
        {
            printf("%d ",d(i,j));
        }
        printf("\n");
    }
    printf("&*******\n");
    for(i=1;i<=cnt;i++)
        printf("%d %d\n",Pn[i].x,Pn[i].y);

    puts("");
    for(i=1;i<=cnt;i++)
        printf("%d %d\n",Pm[i].x,Pm[i].y);
}
void Build()
{
    int i,j,k;
    memset(head,-1,sizeof(head));ecnt=0;
    scr=0;sink=cnt*2+1;vn=sink+1;
    for(i=1;i<=cnt;i++)
        Insert(scr,i,1,0);
    for(i=cnt+1;i<=sink-1;i++)
        Insert(i,sink,1,0);
    for(i=1;i<=cnt;i++)
    {
        for(j=1;j<=cnt;j++)
        {
            Insert(i,j+cnt,1,d(i,j));
        }
    }
    //Print();
}
queue<int>Q;  
bool SPFA(int s,int t,int n)  
{  
      
    int i,u,v,c;  
    memset(vis,false,sizeof(vis));  
    for(i=0;i<=n;i++)  
        dis[i]=INF;  
    Q.push(s);  
    pre[s]=-1;  
    dis[s]=0;  
    vis[s]=true;  
    while(!Q.empty())  
    {  
        //printf("^\n");  
        u=Q.front();Q.pop();  
        vis[u]=false;  
        for(i=head[u];i!=-1;i=E[i].next)  
        {  
            v=E[i].v;c=E[i].c;  
            if(E[i].w>0&&dis[v]>dis[u]+c)//前提是E[i].w>0  
            {  
                dis[v]=dis[u]+c;  
                pre[v]=i;  
                if(!vis[v])  
                {  
                    vis[v]=true;  
                    Q.push(v);  
                }  
            }  
        }  
    }  
    if(dis[t]<INF) return true;  
    return false;  
}  
void Solve()
{
    Build();
    int i,u,v,du,dv,ans=0,flow;  
    while(SPFA(scr,sink,vn))
    {
        ans+=dis[sink];
        for(i=pre[sink];i!=-1;i=pre[E[i].u])//更新容量  
        {  
            E[i].w--;  
            E[i^1].w++;  
        }  
    }
    printf("%d\n",ans);
}
int main()
{
    while(scanf("%d%d",&nn,&mm)!=EOF)
    {
        if(nn==0&&mm==0) break;
        Init();
        Solve();
    }
return 0;
}