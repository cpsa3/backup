////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-04-12 01:34:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1072
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:252KB
//////////////////System Comment End//////////////////
/*bfs*/
#include <iostream>
#include <queue>
using namespace std;
struct point 
{
	int x,y,s,t;
};
int map[10][10];
bool mark[10][10];
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int N,M;
bool flag;
struct point s,e;
bool judge(point p)
{
	if(p.x>=1&&p.x<=N&&p.y>=1&&p.y<=M)
		return true;
	return false;
}
queue<point>Q;
void bfs()
{
	int i;
	while(!Q.empty())
		Q.pop();
	s.s=6;s.t=0;
	mark[s.x][s.y]=true;
	Q.push(s);
	struct point p,h;
	while(!Q.empty())
	{
		p=Q.front();
		Q.pop();
		if(map[p.x][p.y]==3)
		{printf("%d\n",p.t);return;}
		for(i=0;i<4;i++)
		{
			h=p;
			h.x+=dir[i][0];h.y+=dir[i][1];
			h.s--;h.t++;
			if(judge(h)&&!mark[h.x][h.y]&&h.s&&map[h.x][h.y])
			{
				if(map[h.x][h.y]==4)//注意，标1的地方可以重复走，但标2，4的地方重复走没意义
				{mark[h.x][h.y]=true;h.s=6;}
				Q.push(h);
			}
		}
	}
	printf("-1\n");
	return;
}
int main()
{
	int T,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&M);
		for(i=1;i<=N;i++)
		{
			for(j=1;j<=M;j++)
			{
				scanf("%d",&map[i][j]);
				if(map[i][j]==2)
				{s.x=i;s.y=j;}
			}
		}
		memset(mark,false,sizeof(mark));
		bfs();
	}
	return 0;
}