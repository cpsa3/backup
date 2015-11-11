////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-08 17:40:49
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3829
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:4220KB
//////////////////System Comment End//////////////////
/*网络流*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 2006
#define INF 1e8
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct Node
{
	char like[20];
	char dislike[20];
}node[2005];
struct edge
{
	int u,v,w,next;
}E[2000000];
int head[MAXN],ecnt;
int dis[MAXN],cur[MAXN],pre[MAXN],gap[MAXN];
int N,M,P,scr,sink,vn;
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
	int i,j;
	memset(head,-1,sizeof(head));ecnt=0;
	scr=0;sink=2*P+1;vn=sink+1;
	for(i=1;i<=P;i++)
		scanf("%s%s",node[i].like,node[i].dislike);
	for(i=1;i<=P;i++)
	{
		Insert(scr,i,1);
		Insert(i+P,sink,1);
	}
	//构图
	for(i=1;i<=P;i++)
	{
		for(j=i+1;j<=P;j++)
		{
			if(!strcmp(node[i].like,node[j].dislike)||!strcmp(node[i].dislike,node[j].like))
			{
				Insert(i,j+P,INF);
				Insert(j,i+P,INF);
			}
		}
	}
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
void Solve()
{
	int num=Sap(scr,sink,vn);
	printf("%d\n",P-num/2);
}
int main()
{
	while(scanf("%d%d%d",&N,&M,&P)!=EOF)
	{
		Init();
		Solve();
	}
return 0;
}		