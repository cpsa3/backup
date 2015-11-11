////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-10-28 22:15:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1728
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:360KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <queue>
using namespace std;
int m,n,K,x1,x2,y1,y2,mark[101][101];//mark[i][j]用来记录到达(i,j)点所需的最少转弯数
int dir[5][2]={{0,0},{1,0},{0,1},{-1,0},{0,-1}};
char map[101][101];
struct point
{
	int x,y,sum,D;
};
struct point start;
queue<point>Q;
void bfs()
{
	if(x1==x2&&y1==y2)
		{printf("yes\n");return;}
	int i,j;
	struct point p,s;
	while(!Q.empty())
		Q.pop();
	for(i=1;i<=m;i++)
	for(j=1;j<=n;j++)
		mark[i][j]=9999999;
		mark[x1][y1]=0;//初始化
	for(i=1;i<=4;i++)
	{
		p=start;
		p.x+=dir[i][0];p.y+=dir[i][1];
		p.D=i;//记录初始方向
		if(p.x>=1&&p.x<=m&&p.y>=1&&p.y<=n&&map[p.x][p.y]=='.')
		{mark[p.x][p.y]=0;Q.push(p);}
	}
	while(!Q.empty())
	{
		p=Q.front();
		Q.pop();
		//if(p.sum>K)
		//{flag=1;printf("no\n");break;}
		if(p.x==x2&&p.y==y2&&p.sum<=K)
		{printf("yes\n");return;}
		for(i=1;i<=4;i++)
		{
			s=p;
			s.x+=dir[i][0];
			s.y+=dir[i][1];
			if(s.D!=i){s.sum++;s.D=i;}
			if(s.sum<=K&&s.x>=1&&s.x<=m&&s.y>=1&&s.y<=n&&map[s.x][s.y]=='.')
			{
				if(s.sum<=mark[s.x][s.y])//核心，判断更新点
				{Q.push(s);mark[s.x][s.y]=s.sum;}
			}
		}	
	}
printf("no\n");//技巧
return;
}
main ()
{
	int T,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&m,&n);
		getchar();
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
				scanf("%c",&map[i][j]);
			getchar();
		}

		scanf("%d %d %d %d %d",&K,&y1,&x1,&y2,&x2);
		start.x=x1;
		start.y=y1;
		start.sum=0;
		start.D=0;
		bfs();
	}
	return 0;
}
