////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-11-17 23:04:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1874
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:296KB
//////////////////System Comment End//////////////////
#include <iostream>
const int MAX=201;
const int INF=99999999;
int map[MAX][MAX],path[MAX],N,M;
bool hash[MAX];
void Dijkstra(int s,int e)
{
	int i,j;
	path[s]=0;
	for(i=1;i<=N;i++)
	{
		int min=INF,w;
		for(j=0;j<N;j++)
		{
			if(hash[j]&&path[j]<min)
			{min=path[j];w=j;}
		}
		if(w==e)
			break;
		hash[w]=false;
		for(j=0;j<N;j++)
		{
			if(map[w][j]!=INF&&path[j]>path[w]+map[w][j])
				path[j]=path[w]+map[w][j];
		}
	}
return;
}
main ()
{
	int i,j,a,b,d,s1,e1;
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		for(i=0;i<=N;i++)
			for(j=0;j<=N;j++)
			{
				hash[i]=true;
				map[i][j]=INF;
				map[i][i]=0;
				path[i]=INF;
			}
		for(i=1;i<=M;i++)
		{
			scanf("%d%d%d",&a,&b,&d);
			if(map[a][b]>d)
			{map[a][b]=map[b][a]=d;}
		}
		scanf("%d%d",&s1,&e1);
		Dijkstra(s1,e1);
		if(path[e1]==INF)
			printf("-1\n");
		else
			printf("%d\n",path[e1]);
	}
return 0;
}