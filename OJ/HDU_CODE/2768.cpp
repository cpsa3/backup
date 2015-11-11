////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2012-03-12 17:13:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2768
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:504KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <cstring>
#define MAXN 505
using namespace std;
struct Node
{
	char s1[10];
	char s2[10];
}node[MAXN];

bool map[MAXN][MAXN];
bool vis[MAXN];
int result[MAXN];
int Cn,Dn,M;

bool Judge(int a,int b)
{
	if(strcmp(node[a].s1,node[b].s2)==0)
		return true;
	if(strcmp(node[a].s2,node[b].s1)==0)
		return true;
	return false;
}
void Build()
{
	int i,j;
	for(i=1;i<=M;i++)
	{
		for(j=i+1;j<=M;j++)
		{
			if(Judge(i,j))
				map[i][j]=map[j][i]=true;
		}
	}
}
void Init()
{
	int i,j,k;
	memset(map,false,sizeof(map));
	memset(result,-1,sizeof(result));
	scanf("%d%d%d",&Cn,&Dn,&M);
	for(i=1;i<=M;i++)
		scanf("%s%s",node[i].s1,node[i].s2);
	Build();
}
int Find(int x)//找增广路
{
	int i;
	for(i=1;i<=M;i++)
	{
		if(map[x][i]&&!vis[i])
		{
			vis[i]=true;
			if(result[i]==-1||Find(result[i]))
			{
				result[i]=x;
				return 1;
			}
		}
	}
	return 0; 
}
int Max_Match()//二分匹配
{
	int i,ans=0;
	for(i=1;i<=M;i++)
	{
		memset(vis,false,sizeof(vis));
		ans+=Find(i); 
	}
	return ans; 
}
void Solve()
{
	int ans=M-Max_Match()/2;
	//printf("%d\n",Max_Match());
	printf("%d\n",ans);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		Init();
		Solve();
	}
return 0;
}