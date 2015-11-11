////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-11-09 22:59:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2066
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:4200KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
const int INF=99999999;
const int MAX=1010;
int max(int a,int b)
{
	return a>b?a:b;
}
int T,S,D,L;
int map[MAX][MAX];
int Dijkstra(int start,int end)
{
	bool hash[MAX];
	int path[MAX];//记录从起始点到i点的最短路径
	for(int i=0;i<=L;i++)
	{
		hash[i]=true;//表示该点没有处理过
		path[i]=INF;//表示i点没被处理过，此时最短路为无穷大
	}
	hash[start]=false;
	path[start]=0;//注意点
	while(start!=end)
	{
		for(i=0;i<=L;i++)
		{
			if(map[start][i]!=0)
			{
				if(path[i]>path[start]+map[start][i])
					path[i]=path[start]+map[start][i];
			}
		}
		int min=INF;
		for(i=0;i<=L;i++)
		{
			if(path[i]<min&&hash[i])//找新的起始点
			{
				min=path[i];
				start=i;
			}
		}
		hash[start]=false;
	}
return path[end];
}
int main ()
{
	int i,a,b,time,s,d;
	while(scanf("%d%d%d",&T,&S,&D)!=EOF)
	{
		memset(map,0,sizeof(map));//初始化
		L=0;
		for(i=1;i<=T;i++)
		{
			scanf("%d%d%d",&a,&b,&time);
			if(!map[a][b])
				map[a][b]=map[b][a]=time;
			else
			{
				if(map[a][b]>time)
					map[a][b]=map[b][a]=time;
			}
			if(L<max(a,b))
				L=max(a,b);//更新最大编号的点
		}
		for(i=1;i<=S;i++)
		{
			scanf("%d",&s);
			map[0][s]=map[s][0]=1;//添加总的起始点
		}
		L++;//添加结束点
		for(i=1;i<=D;i++)
		{
			scanf("%d",&d);
			map[L][d]=map[d][L]=1;
		}
		printf("%d\n",Dijkstra(0,L)-2);
	}
return 0;
}