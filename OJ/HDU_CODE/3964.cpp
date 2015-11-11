////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-08-24 19:04:25
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3964
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*±©¡¶*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <cstdio>
using namespace std;
int N;
int map[10][10];
int take[20];
bool vis[20];
void Init()
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			scanf("%d",&map[i][j]);
	}
}
void Print(int take[],int cnt,int now)
{
	int i;
	printf("%d",now);
	for(i=0;i<cnt;i++)
		printf("%d",take[i]);
	printf("\n");
}
void dfs(int now,int take[],int cnt,int p,bool vis[])
{
	int i;
	if(cnt!=0)
	{
		if(map[take[cnt-1]][now])
			Print(take,cnt,now);
	}
	//if(p==N) return;
	for(i=now+1;i<N;i++)
	{
		if(!vis[i]&&map[p][i])
		{
			vis[i]=true;
			take[cnt++]=i;
			dfs(now,take,cnt,i,vis);
			vis[i]=false;
			cnt--;
		}
	}
}
void Solve()
{
	int i,j;
	for(i=0;i<N;i++)
	{
		memset(vis,false,sizeof(vis));
		dfs(i,take,0,i,vis);
	}
}
int main()
{
	while(scanf("%d",&N)!=EOF)
	{
		Init();
		Solve();
		printf("\n");
	}
return 0;
}