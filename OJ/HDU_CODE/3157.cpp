////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-09-22 01:09:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3157
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:244KB
//////////////////System Comment End//////////////////
/*有上下界最小流*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <cstring>
#define MAXN 105
#define INF (1<<30)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
struct edge
{
	int u,v,w,next;
}E[200000];
int head[MAXN],ecnt;
int gap[MAXN],cur[MAXN],dis[MAXN],pre[MAXN];
int N,M,s,t,ss,tt,vn,Sum;
int D[MAXN];
int U[205],V[205];
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
int ID(char ss[])
{
	if(ss[0]=='-') return t;
	if(ss[0]=='+') return s;
	int res=0,i,len;
	len=strlen(ss);
	for(i=0;i<len;i++)
		res=res*10+ss[i]-'0';
	return res;
}
void Init()
{
	int i,u,v,w;
	char x[20];
	memset(head,-1,sizeof(head));ecnt=0;
	memset(D,0,sizeof(D));
	s=0;t=N+1;ss=t+1;tt=ss+1;vn=tt+1;
	Sum=0;
	for(i=1;i<=M;i++)
	{
		scanf("%s",x);
		u=ID(x);
		scanf("%s",x);
		v=ID(x);
		scanf("%d",&w);
		D[v]+=w;
		D[u]-=w;
		U[i]=u;V[i]=v;
		//Insert(u,v,INF);
	}
	for(i=0;i<=N+1;i++)
	{
		if(D[i]>0) Sum+=D[i];
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

bool Judge(int mid)
{
    int i,j,u,v,w;
    memset(head,-1,sizeof(head));ecnt=0;
    for(i=1;i<=M;i++)
        Insert(U[i],V[i],INF);
    for(i=0;i<=N+1;i++)
    {
        if(D[i]>0) Insert(ss,i,D[i]);
        else if(D[i]<0) Insert(i,tt,-D[i]);
    }
    Insert(t,s,mid);//二分上界
    int res=Sap(ss,tt,vn);
    return res==Sum;
}
void Solve()
{
	int l,r,mid;
	if(!Judge(INF)) {printf("impossible\n");return;}
	l=0;r=Sum+5;
	while(l!=r)
	{
		mid=(l+r)>>1;
		if(Judge(mid))
			r=mid;
		else 
			l=mid+1;
	}
	printf("%d\n",l);
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