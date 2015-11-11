////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-04-29 19:04:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1565
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:320KB
//////////////////System Comment End//////////////////
/*最小割+拆点*/
/*AC代码：78ms*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 5005
#define INF 1e8
#define min(a,b) (a<b?a:b)
using namespace std;
struct edge
{
	int u,v,w,next;
}E[2000000];
int head[MAXN],ecnt;
int gap[MAXN],cur[MAXN],dis[MAXN],pre[MAXN];
int map[55][55];
int N,scr,sink,vn,sum;
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
	int i,j,u,v,id;
	memset(head,-1,sizeof(head));ecnt=0;
	scr=0;sink=N*N*2+1;vn=sink+1;sum=0;
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{scanf("%d",&map[i][j]);sum+=map[i][j];}
	}
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			id=(i-1)*N+j;
			Insert(id,id+N*N,map[i][j]);
			if((i+j)&1)
			Insert(scr,id,INF);
			else
			Insert(id+N*N,sink,INF);
			if(i-1>=1)
				Insert(id+N*N,id-N,INF);
			if(i+1<=N)
				Insert(id+N*N,id+N,INF);
			if(j-1>=1)
				Insert(id+N*N,id-1,INF);
			if(j+1<=N)
				Insert(id+N*N,id+1,INF);
		}
	}
}
int Sap(int s,int t,int n)//核心代码(模版)
{
    int ans=0,aug=INF;//aug表示增广路的流量
    int i,v,u=pre[s]=s;
    for(i=0;i<n;i++)
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
	//printf("%d\n",Sap(scr,sink,vn));
	printf("%d\n",sum-Sap(scr,sink,vn));
}
int main()
{
	while(scanf("%d",&N)!=EOF)
	{
		Init();
		Solve();
	}
return 0;
}