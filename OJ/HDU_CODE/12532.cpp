////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-22 22:43:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1253
////Problem Title: 
////Run result: Accept
////Run time:531MS
////Run memory:780KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <queue>
using namespace std;
int map[51][51][51];
int dir[6][3]={0,-1,0,0,1,0,0,0,-1,0,0,1,1,0,0,-1,0,0};
int n,a,b,c,t,flag;
struct point
{
	int x,y,z,sum;
};
queue<point>Q;
struct point start,end;
bool over(struct point p)
{
	if(p.x>=0&&p.x<a&&p.y>=0&&p.y<b&&p.z>=0&&p.z<c)
		return true;
	return false;
}
void bfs()
{
	int i,x,y,z,sum;
	Q.push(start);
	map[start.x][start.y][start.z]=1;
	struct point p;
	while(!Q.empty())
	{
		x=Q.front().x;
		y=Q.front().y;
		z=Q.front().z;
		sum=Q.front().sum;
		if(sum>t||flag)
			return;
		if(x==end.x&&y==end.y&&z==end.z&&sum<=t)
		{
			flag=1;
			printf("%d\n",Q.front().sum);
			return;
		}
		for(i=0;i<6;i++)
		{
			p.x=x+dir[i][0];
			p.y=y+dir[i][1];
			p.z=z+dir[i][2];
			p.sum=Q.front().sum+1;
			if(over(p)&&map[p.x][p.y][p.z]==0)
			{
				map[p.x][p.y][p.z]=1;
				Q.push(p);
			}
		}
		Q.pop();
	}
return;
}
main ()
{
	int i,j,k;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&t);
		memset(map,0,sizeof(map));
		for(i=0;i<a;i++)
			for(j=0;j<b;j++)
				for(k=0;k<c;k++)
					scanf("%d",&map[i][j][k]);
				if(a+b+c-3>t||map[a-1][b-1][c-1]==1)
				{printf("-1\n");continue;}
				while(!Q.empty())
					Q.pop();
				flag=0;
		start.x=start.y=start.z=start.sum=0;
		end.x=a-1;end.y=b-1;end.z=c-1;
		bfs();
		if(!flag)
			printf("-1\n");
	}
return 0;
}