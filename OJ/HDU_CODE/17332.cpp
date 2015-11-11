////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-10-17 13:45:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1733
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:1100KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <queue>
#define MAXN 5500*3
#define INF (1<<30)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define ID(x,y,t) ((x-1)*M+(y)+1+(t)*Num)
using namespace std;

struct Node
{
	int x,y;
	Node(int x1,int y1) {x=x1;y=y1;}
	Node(){}
};
struct edge
{
	int u,v,w,next;
}E[2000000];
int head[MAXN],ecnt;
int gap[MAXN],dis[MAXN],pre[MAXN],cur[MAXN];
char map[20][20];
bool vis[20][20];
int dir[5][2]={0,1,0,-1,1,0,-1,0,0,0};
int N,M,scr,sink,vn,Num,Now,Ti,Sum;

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
	for(i=1;i<=N;i++)
		scanf("%s",map[i]+1);
	scr=0;sink=1;vn=2;
	Num=N*M;
	Sum=0;
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=M;j++)
		{
			if(map[i][j]=='X')
			{
				Sum++;
				Insert(scr,ID(i,j,0),1);
			}
		}
	}
	vn+=Num;
}
bool In(int x,int y)
{
	if(x>=1&&x<=N&&y>=1&&y<=M)
		return true;
	return false;
}
queue<Node>Q;
bool BFS(Node s)
{
	int i;
	Node u;
	memset(vis,false,sizeof(vis));
	while(!Q.empty()) Q.pop();
	vis[s.x][s.y]=true;
	Q.push(s);
	while(!Q.empty())
	{
		u=Q.front();Q.pop();
		for(i=0;i<4;i++)
		{
			int dx=u.x+dir[i][0];
			int dy=u.y+dir[i][1];
			if(In(dx,dy)&&!vis[dx][dy]&&map[dx][dy]!='#')
			{
				if(map[dx][dy]=='@') return true;
				vis[dx][dy]=true;
				Q.push(Node(dx,dy));
			}
		}
	}
	return false;
}
bool Judge()
{
	int i,j;
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=M;j++)
		{
			if(map[i][j]=='X'&&!BFS(Node(i,j))) return false;
		}
	}
	return true;
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

bool Run()
{
	int i,j,k,dx,dy,u,v;
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=M;j++)
		{
			if(map[i][j]=='#') continue;
			u=ID(i,j,Ti-1);
			for(k=0;k<5;k++)
			{
				int dx=i+dir[k][0];
				int dy=j+dir[k][1];
				if(In(dx,dy)&&map[dx][dy]!='#')
				{
					v=ID(dx,dy,Ti);
					Insert(u,v,1);
				}
			}
			if(map[i][j]=='@')
			{
				Insert(ID(i,j,Ti),sink,1);
			}
		}
	}
	vn+=Num;
	Now+=Sap(scr,sink,vn);
	return Now==Sum;
}
void Solve()
{
	if(!Sum) {printf("0\n");return;}
	if(!Judge()) {printf("-1\n");return;}
	Ti=1;
	Now=0;
	while(true)
	{
		//printf("*\n");
		if(Run()) break;
		Ti++;
	}
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