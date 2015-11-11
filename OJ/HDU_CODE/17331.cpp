////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-09-17 19:43:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1733
////Problem Title: 
////Run result: Accept
////Run time:250MS
////Run memory:2108KB
//////////////////System Comment End//////////////////
/*HDU_1733 Escape*/
/*分层图网络流+枚举*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 20005
#define Lim 75
#define INF (1<<30)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
struct edge
{
    int u,v,w,next;
}E[2000000];
int head[MAXN],ecnt;
int gap[MAXN],cur[MAXN],dis[MAXN],pre[MAXN];
int N,M,scr,sink,vn,Ti,Sum,now;
int ans;
int dir[5][2]={0,1,0,-1,1,0,-1,0,0,0};
char map[20][20];
void Insert(int u,int v,int w)
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
    int i,j,u;
    memset(head,-1,sizeof(head));ecnt=0;
    for(i=0;i<N;i++)
        scanf("%s",map[i]);
    scr=0;sink=1;vn=2;
    Sum=0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            if(map[i][j]=='X')
            {
                Sum++;
                u=i*M+j+2;
                Insert(scr,u,1);
            }
        }
    }
    now=(M*N);
    vn+=now;
}
int Sap(int s,int t,int n)//核心代码(模版)
{
    int ans=0,aug=INF;//aug表示增广路的流量
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

bool Judge(int Ti)
{
    int i,j,k,u,v,a,b,dx,dy;
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            if(map[i][j]=='#') continue;
            u=i*M+j+1;
            a=(Ti-1)*N*M;
            b=a+N*M;
            u=a+u+1;
            for(k=0;k<5;k++)
            {
                dx=i+dir[k][0];
                dy=j+dir[k][1];
                if(dx>=0&&dx<N&&dy>=0&&dy<M&&map[dx][dy]!='#')
                {
                    v=dx*M+dy+1;
                    v=b+v+1;
                    Insert(u,v,1);
                }
            }

            if(map[i][j]=='@')
            {
                v=b+i*M+j+2;
                Insert(v,sink,1);
            }
        }
    }
    vn+=(N*M);
    now+=(N*M);
    int t=Sap(scr,sink,vn);
    ans+=t;
    return ans==Sum;
}
void Solve()
{
    if(Sum==0) {printf("0\n");return;}
    ans=Ti=0;
    while(true)
    {
        Ti++;
        if(Judge(Ti)) break;
        if(Ti==Lim) break;
    }
    if(Ti==Lim) Ti=-1;
    printf("%d\n",Ti);
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