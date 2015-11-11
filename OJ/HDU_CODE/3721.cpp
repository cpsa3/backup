////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-05 19:37:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3721
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:356KB
//////////////////System Comment End//////////////////
/*枚举+求最长路*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <queue>
#define MAXN 2505
#define INF 1e8
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct edge
{
    int u,v,w,next;
    bool ok;
}E[3*MAXN];
int head[MAXN];
int ecnt;
int dis[MAXN],road[MAXN],pre[MAXN],cnt;
bool vis[MAXN],col[MAXN];
int N,ans_l,cas,lenc;
queue<int>Q;

void Insert(int u,int v,int w)
{
    E[ecnt].u=u;
    E[ecnt].v=v;
    E[ecnt].w=w;
    E[ecnt].ok=true;
    E[ecnt].next=head[u];
    head[u]=ecnt++;
}
void Print()
{
    int i;
    for(i=1;i<=N;i++)
        printf("%d ",col[i]);
    printf("**\n");
}
void Init()
{
    int i,u,v,w;
    memset(head,-1,sizeof(head));ecnt=0;
    scanf("%d",&N);
    for(i=1;i<N;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        u++;v++;
        Insert(u,v,w);
        Insert(v,u,w);
    }
}
int BFS(int s)
{
    int i,u,v,w,res;
    while(!Q.empty()) Q.pop();
    memset(vis,false,sizeof(vis));
    memset(dis,-1,sizeof(dis));
    memset(pre,-1,sizeof(pre));
    vis[s]=true;
    dis[s]=0;
    Q.push(s);
    while(!Q.empty())
    {
        u=Q.front();Q.pop();
        for(i=head[u];i!=-1;i=E[i].next)
        {
            if(E[i].ok==false) continue;
            v=E[i].v;w=E[i].w;
            if(!vis[v])
            {
                dis[v]=dis[u]+w;
                pre[v]=i;
                vis[v]=true;
                Q.push(v);
            }
        }
    }
	res=0;
	for(i=1;i<=N;i++)
	{
		if(dis[i]==-1) continue;
		if(dis[i]>res) res=dis[i];
	}
	return res;
}
int Go(int x,bool flag)
{
    int i,u,v,s,e,Max,l,temp[MAXN],tcnt;
    BFS(x);
    s=0;Max=0;lenc=INF;
    for(i=1;i<=N;i++)//染色
    {
        if(vis[i])
        {
            col[i]=flag;
            if(dis[i]>Max)
            {s=i;Max=dis[i];}
        }
    }
    BFS(s);
    e=0;Max=0;
    for(i=1;i<=N;i++)
    {
        if(vis[i])
        {
            if(dis[i]>Max)
            {e=i;Max=dis[i];}
        }
    }
	int sum=0;
	tcnt=0;
    u=e;
    while(true)
    {
        l=pre[u];
        if(l==-1) break;
        temp[tcnt++]=l;
		sum+=E[l].w;
        u=E[l].u;
    }
	sum/=2;
	int len=0;
	for(i=0;i<tcnt;i++)
	{
		len+=E[temp[i]].w;
		if(len>sum) break;
	}
	//最好的点就在这两个点之间
	if(tcnt==0)
	{
		lenc=0;
		return Max;
	}
	u=E[temp[i]].u;
	v=E[temp[i]].v;
	int lu=BFS(u);
	int lv=BFS(v);
	//printf("&%d %d %d %d %d\n",tcnt,u,v,lu,lv);
	lenc=min(lu,lv);
    return Max;
}
void fuck(int ith)
{
    int i,u,v,s,e,ss,ee,ds,de,dw,Max;
    memset(col,false,sizeof(col));
    //printf("%d %d \n",road[ith],road[ith]^1);
    E[road[ith]].ok=E[road[ith]^1].ok=false;
    s=E[road[ith]].u;
    e=E[road[ith]].v;
    ds=Go(s,1); ss=lenc;
    de=Go(e,0); ee=lenc;

	//printf("**%d %d \n",ss,ee);
    //Print();
    //int ss=get_min(s,1);
    //int ee=get_min(e,0);
    dw=ss+ee+E[road[ith]].w;
    int res=max(dw,max(ds,de));
	
    //printf("*%d %d %d %d %d %d\n",s,e,ans_l,ds,de,dw);
    ans_l=min(ans_l,res);
    E[road[ith]].ok=E[road[ith]^1].ok=true;
}
void Run()
{
    int i,s,e,u,Max,l;
    BFS(1);
    s=1;Max=dis[1];
    for(i=2;i<=N;i++)
    {
        if(dis[i]>Max)
        {s=i;Max=dis[i];}
    }
    BFS(s);
    e=1;Max=dis[1];
    for(i=2;i<=N;i++)
    {
        if(dis[i]>Max)
        {e=i;Max=dis[i];}
    }
    ans_l=Max;
    cnt=0;
    u=e;
    while(true)
    {
        l=pre[u];
        if(l==-1) break;
        road[cnt++]=l;
        u=E[l].u;
    }
    //printf("&%d\n",cnt);
    for(i=0;i<cnt;i++)
    {
        fuck(i);
    }
}
void Solve()
{
    int i;
    Run();//求出最长路径
    printf("Case %d: %d\n",cas++,ans_l);
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