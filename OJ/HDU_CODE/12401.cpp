////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-12-29 22:00:06
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1240
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <queue>
#define MAXN 11
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;

struct Node
{
	int x,y,z,step;
	Node(){}
	Node(int x1,int y1,int z1,int step1)
	{
		x=x1;
		y=y1;
		z=z1;
		step=step1;
	}
};
int dir[6][3]={
	0,0,1,
	0,0,-1,
	0,1,0,
	0,-1,0,
	1,0,0,
	-1,0,0
};
char s[10];
int N;
char map[11][11][11];//z,x,y
bool vis[11][11][11];
int sx,sy,sz;
int ex,ey,ez;
Node Q[20000];
int Head,Tail;

void Init()
{
	int i,j,k;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			scanf("%s",map[i][j]);
	}
	scanf("%d%d%d%d%d%d",&sy,&sx,&sz,&ey,&ex,&ez);
	scanf("%s",s);
}
bool Judge(int x,int y,int z)
{
	if(x>=0&&x<N&&y>=0&&y<N&&z>=0&&z<N)
		return true;
	return false;
}
int BFS()
{
	if(sx==ex&&sy==ey&&sz==ez) return 0;
	int i,j;
	Node u;
	memset(vis,false,sizeof(vis));
	Head=Tail=0;
	Q[Head++]=Node(sx,sy,sz,0);
	vis[sz][sx][sy]=true;
	while(Head!=Tail)
	{
		u=Q[Tail++];
		for(i=0;i<6;i++)
		{
			int dx=u.x+dir[i][1];
			int dy=u.y+dir[i][2];
			int dz=u.z+dir[i][0];
			if(Judge(dx,dy,dz)&&!vis[dz][dx][dy]&&map[dz][dx][dy]=='O')
			{
				if(dx==ex&&dy==ey&&dz==ez)
					return u.step+1;
				vis[dz][dx][dy]=true;
				Q[Head++]=Node(dx,dy,dz,u.step+1);
			}
		}
	}
	return -1;
}
void Solve()
{
	int ans=BFS();
	if(ans==-1)
		printf("NO ROUTE\n");
	else 
		printf("%d %d\n",N,ans);
}
int main()
{
	while(scanf("%s%d",s,&N)!=EOF)
	{
		Init();
		Solve();
	}
return 0;
}
