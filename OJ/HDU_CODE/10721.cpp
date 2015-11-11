////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-08-21 18:31:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1072
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:260KB
//////////////////System Comment End//////////////////
/*BFSªÚDP*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <queue>
using namespace std;
struct Node
{
	int x,y,step,t;
	Node(int x1,int y1,int step1,int t1)
	{
		x=x1;
		y=y1;
		step=step1;
		t=t1;
	}
	Node(){}
};
struct Node s;
int map[20][20];
bool vis[20][20];
int N,M;
int dir[4][2]={0,1,0,-1,1,0,-1,0};
queue<Node>Q;
void Init()
{
	int i,j;
	scanf("%d%d",&N,&M);
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=M;j++)
		{
			scanf("%d",&map[i][j]);
			if(map[i][j]==2)
			{
				s.x=i;
				s.y=j;
				s.t=6;
				s.step=0;
			}
		}
	}
}
bool Judge(int x,int y)
{
	if(x>=1&&x<=N&&y>=1&&y<=M)
		return true;
	return false;
}
int BFS()
{
	int i,step;
	Node v,u;
	while(!Q.empty()) Q.pop();
	memset(vis,false,sizeof(vis));
	Q.push(s);
//	vis[s.x][s.y]=true;
	while(!Q.empty())
	{
		u=Q.front();Q.pop();
		step=u.step+1;
		for(i=0;i<4;i++)
		{
			int dx=u.x+dir[i][0];
			int dy=u.y+dir[i][1];
			if(Judge(dx,dy)&&!vis[dx][dy]&&map[dx][dy]!=0)
			{
				v.x=dx;
				v.y=dy;
				v.step=step;
				if(map[dx][dy]==4) 
				{
					v.t=6;
					vis[dx][dy]=true;
				}
				else v.t=u.t-1;
				if(v.t!=1)
					Q.push(v);
				if(map[dx][dy]==3) return v.step;
			}
		}
	}
	return -1;
}
void Solve()
{
	int ans=BFS();
	printf("%d\n",ans);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		Init();
		Solve();
	}
return 0;
}
