////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-31 18:47:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3991
////Problem Title: 
////Run result: Accept
////Run time:2468MS
////Run memory:6288KB
//////////////////System Comment End//////////////////
/*Floyd+最小路径覆盖*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 2005
#define INF 1e8
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
struct Node
{
    int p,t;
}node[MAXN];
struct edge
{
    int u,v,next;
}E[2000000];
int head[MAXN],ecnt;
int N,M,Q,cas;
__int64 map[105][105];
int result[MAXN];
bool flag[MAXN];
void Insert(int u,int v)
{
    E[ecnt].u=u;
    E[ecnt].v=v;
    E[ecnt].next=head[u];
    head[u]=ecnt++;
}
int cmp(const void *p1,const void *p2)
{
    return ((struct Node *)p1)->t-((struct Node *)p2)->t;
}
void Floyd()
{
    int i,j,k;
    for(k=0;k<N;k++)
    {
        for(i=0;i<N;i++)
        {
            if(i==k||map[i][k]==-1) continue;
            for(j=0;j<N;j++)
            {
                if(j==k||j==i||map[k][j]==-1) continue;
                if(map[i][j]==-1||map[i][j]>map[i][k]+map[k][j])
                    map[i][j]=map[i][k]+map[k][j];
            }
        }
    }
}
void Init()
{
    int i,u,v;
    __int64 c;
    scanf("%d%d%d",&N,&M,&Q);
    memset(map,-1,sizeof(map));
    for(i=1;i<=M;i++)
    {
        scanf("%d%d%I64d",&u,&v,&c);
        if(map[u][v]==-1||map[u][v]>c)
        {
            map[u][v]=map[v][u]=c;
        }
    }
    Floyd();
    for(i=1;i<=Q;i++)
        scanf("%d%d",&node[i].p,&node[i].t);
    qsort(node+1,Q,sizeof(node[0]),cmp);
}
void Build()
{
    int i,j,u,v;
    memset(head,-1,sizeof(head));ecnt=0;
    for(i=1;i<=Q;i++)
    {
        for(j=i+1;j<=Q;j++)
        {
            u=node[i].p;
            v=node[j].p;
            if(u==v)
            {
                Insert(i,j);
                continue;
            }
            if(map[u][v]==-1) continue;
            if((node[j].t-node[i].t)>=map[u][v])
                Insert(i,j);
        }
    }
}
bool Find(int u)
{
	int i,v;
	for(i=head[u];i!=-1;i=E[i].next)
	{
		v=E[i].v;
		if(!flag[v])
		{
			flag[v]=true;
			if(result[v]==-1||Find(result[v]))
			{
				result[v]=u;
				return true;
			}
		}
	}
	return false;
}
void Solve()
{
    int i,ans=0;
    Build();//构图
    memset(result,-1,sizeof(result));
    for(i=1;i<=Q;i++)
    {
        memset(flag,false,sizeof(flag));
        ans+=Find(i);
    }
    ans=Q-ans;
    printf("Case %d: %d\n",cas++,ans-1);
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
