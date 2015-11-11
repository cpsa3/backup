////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-12-29 22:29:53
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1372
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;

struct Node
{
	int x,y,step;
	Node(){}
	Node(int x1,int y1,int step1)
	{
		x=x1;
		y=y1;
		step=step1;
	}
};
int dir[8][2]={2,1,2,-1,1,2,1,-2,-2,1,-2,-1,-1,2,-1,-2};
char s1[3],s2[3];
int sx,sy,ex,ey;
Node Q[20000];
int Head,Tail;
bool vis[10][10];
bool Judge(int x,int y)
{
	if(x>=1&&x<=8&&y>=1&&y<=8)
		return true;
	return false;
}
int BFS()
{
	if(sx==ex&&sy==ey) return 0;
	int i;
	Node u;
	memset(vis,false,sizeof(vis));
	Head=Tail=0;
	Q[Head++]=Node(sx,sy,0);
	vis[sx][sy]=true;
	while(Head!=Tail)
	{
		u=Q[Tail++];
		for(i=0;i<8;i++)
		{
			int dx=u.x+dir[i][0];
			int dy=u.y+dir[i][1];
			if(Judge(dx,dy)&&!vis[dx][dy])
			{
				if(dx==ex&&dy==ey) return u.step+1;
				vis[dx][dy]=true;
				Q[Head++]=Node(dx,dy,u.step+1);
			}
		}
	}
	return -1;
}
void Solve()
{
	sx=s1[0]-'a'+1;
	sy=s1[1]-'0';
	ex=s2[0]-'a'+1;
	ey=s2[1]-'0';
	int ans=BFS();
	//if(ans==-1)
	printf("To get from %s to %s takes %d knight moves.\n",s1,s2,ans);
}
int main()
{
	while(scanf("%s%s",s1,s2)!=EOF)
		Solve();
return 0;
}