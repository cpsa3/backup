////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-10-26 14:52:26
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2339
////Problem Title: 
////Run result: Accept
////Run time:406MS
////Run memory:5184KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <queue>
#include <stdlib.h>
using namespace std;
const int dir[4][2]={1,0,-1,0,0,1,0,-1};
struct px
{
	int x,y,high;
};
struct px S[260000];
int cmp(const void *a,const void *b)
{
	return ((struct px *)a)->high-((struct px *)b)->high;
}
queue<struct px>Q;
int mark[501][501];//记录改点是否已处理
int hight[501][501]={0};
main ()
{
	int T,h,w,d,i,j;
	struct px temp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&h,&w,&d);
		memset(hight,0,sizeof(hight));
		//queue<px>S;
		int k=0;
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				scanf("%d",&hight[i][j]);
				temp.x=i;temp.y=j;temp.high=hight[i][j];
				S[k++]=temp;
			}
		}
			qsort(S,k,sizeof(S[0]),cmp);
			int res=0;//记录总峰数
			for(i=0;i<501;i++)
				for(j=0;j<501;j++)
					mark[i][j]=-1;
				for(i=h*w-1;i>=0;i--)//先处理最高的
				{
					int dx=S[i].x;
					int dy=S[i].y;
					if(mark[dx][dy]!=-1)//已被处理过就不用再处理
						continue;
					int flag=1;//标记该点是否为峰
					int sum=0;//和该点等高度的数目
					//queue<struct px>Q;
					while(!Q.empty())
					Q.pop();
					Q.push(S[i]);
					while(!Q.empty())
					{
						struct px temp2=Q.front();
						Q.pop();
						if(mark[temp2.x][temp2.y]!=-1)
							continue;
						mark[temp2.x][temp2.y]=i;//记录下高度
						if(hight[temp2.x][temp2.y]==hight[dx][dy])
							sum++;//和该点等高度的数目
						for(j=0;j<4;j++)
						{ 
							int nx=temp2.x+dir[j][0];
							int ny=temp2.y+dir[j][1];
							if(nx<0||nx>=h||ny<0||ny>=w) continue;
							if(hight[nx][ny]<=hight[dx][dy]-d) continue;
							if(mark[nx][ny]>i) flag=0;
							//if(hight[nx][ny]>hight[dx][dy]) flag=0;//符合条件的前提下遇到比他高的点，说明该点不是峰
							if(mark[nx][ny]==-1)
							{
								struct px temp1;
								temp1.x=nx;temp1.y=ny;temp1.high=hight[nx][ny];
								Q.push(temp1);
							}
						}
					}
					if(flag) res+=sum;
				}
				printf("%d\n",res);
	}
	return 0;
}