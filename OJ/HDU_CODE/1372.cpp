////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-03 20:52:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1372
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <queue>
using namespace std;
char a[4],b[4];
struct node
{
	int x,y,step;
};
queue<node>Q;
struct node start,end;
int dir[8][2]={2,-1,2,1,-2,-1,-2,1,1,2,1,-2,-1,2,-1,-2};
void bfs(int map[10][10])
{
	int x,y,i;
	Q.push(start);
	map[start.x][start.y]=1;
	struct node w;
	while(!Q.empty())
	{
		x=Q.front().x;
		y=Q.front().y;
		if(x==end.x&&y==end.y)
		{
			printf("To get from %s to %s takes %d knight moves.\n",a,b,Q.front().step);
			break;
		}
		for(i=0;i<8;i++)
		{
			w.x=x+dir[i][0];
			w.y=y+dir[i][1];
			w.step=Q.front().step+1;
			if(w.x>0&&w.x<9&&w.y>0&&w.y<9&&!map[w.x][w.y])
			{
				map[w.x][w.y]=1;
				Q.push(w);
			}
		}
		Q.pop();
	}
return;
}

main ()
{
	while(scanf("%s%s",a,b)!=EOF)
	{
		int map[10][10]={0};
		start.x=a[1]-'0';
		start.y=a[0]-96;
		end.x=b[1]-'0';
		end.y=b[0]-96;
		while(!Q.empty())
			Q.pop();
		bfs(map);
	}
return 0;
}