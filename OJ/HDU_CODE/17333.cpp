////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-11-26 15:10:29
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1733
////Problem Title: 
////Run result: Accept
////Run time:437MS
////Run memory:2280KB
//////////////////System Comment End//////////////////



#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <queue>
#define MAXN 200005
#define INF (1<<30)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define ID(t,x,y,side) ((t)*(nn)*2+(x-1)*M+(y)+(nn)*side+1)
#define VN(t) ((t+1)*(nn)*2+2)
using namespace std;

struct Node
{
	int x,y;
	Node(int x1,int y1)
	{
		x=x1;y=y1;
	}
	Node(){} 
};
struct edge
{
	int u,v,w,next;
}E[2000000];
int head[MAXN],ecnt;
int gap[MAXN],cur[MAXN],dis[MAXN],pre[MAXN];
int N,M,scr,sink,vn,Ti,nn,Sum;
bool ok;
char map[20][20];
bool vis[20][20];
int dir[5][2]={0,1,0,-1,1,0,-1,0,0,0};

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
bool In(int x,int y)
{
	if(x>=1&&x<=N&&y>=1&&y<=M)
		return true;
	return false;
}
queue<Node>Q;
bool BFS(int sx,int sy)
{
	int i,j;
	Node u;
	memset(vis,false,sizeof(vis));
	while(!Q.empty()) Q.pop();
	vis[sx][sy]=true;
	Q.push(Node(sx,sy));
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
void Init()
{
	int i,j;
	memset(head,-1,sizeof(head));ecnt=0;
	scr=0;sink=1;
	nn=N*M;
	vn=nn*2+2;
	Sum=0;
	for(i=1;i<=N;i++)
		scanf("%s",map[i]+1);
	ok=true;
	for(i=1;i<=N&&ok;i++)
	{
		for(j=1;j<=M&&ok;j++)
		{
			Insert(ID(0,i,j,0),ID(0,i,j,1),1);//拆点 
			if(map[i][j]=='X')
			{
				Sum++;
				Insert(scr,ID(0,i,j,0),1);
				if(BFS(i,j)==false)
				{
					ok=false;
					break;
				}
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
bool Judge(int Ti)
{
	int i,j,k;
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=M;j++)
		{
			Insert(ID(Ti,i,j,0),ID(Ti,i,j,1),1);
			if(map[i][j]=='@') Insert(ID(Ti,i,j,1),sink,INF);
			if(map[i][j]=='#') continue;
			for(k=0;k<5;k++)
			{
				int dx=i+dir[k][0];
				int dy=j+dir[k][1];
				if(In(dx,dy)&&map[dx][dy]!='#')
					Insert(ID(Ti-1,i,j,1),ID(Ti,dx,dy,0),INF);
			}
		}
	}
	vn+=(nn*2);
	//vn=VN(Ti);
	int ans=Sap(scr,sink,vn);
	Sum-=ans;
	if(Sum==0) return true;
	return false;
}
void Solve()
{
	//printf("*%d\n",Sum);
	if(!ok) 
	{
		printf("-1\n");return;
	}
	if(Sum==0) 
	{
		printf("0\n");return;
	}
	
	Ti=1;
	while(true)
	{
		//puts("^");
		if(Judge(Ti))
			break;
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