////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-17 23:28:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1281
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:200KB
//////////////////System Comment End//////////////////
/*二分匹配+枚举判定*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
int N,M,K,L,C;
bool map[105][105];
bool flag[105];
int result[105];
int U[105],V[105],cnt,cas;
void Init()
{
	int i,u,v;
	memset(map,false,sizeof(map));
	for(i=1;i<=K;i++)
	{
		scanf("%d%d",&u,&v);
		map[u][v]=true; 
	}
}
bool Find(int u)
{
	int i;
	for(i=1;i<=M;i++)
	{
		if(map[u][i]&&!flag[i])
		{
			flag[i]=true;
			if(result[i]==-1||Find(result[i]))
			{
				result[i]=u;
				return true; 
			} 
		} 
	}
	return false;
}
bool Judge(int ith)
{
	int i,res=0;
	map[U[ith]][V[ith]]=false;
	memset(result,-1,sizeof(result));
	for(i=1;i<=N;i++)
	{
		memset(flag,false,sizeof(flag));
		res+=Find(i); 
	}
	map[U[ith]][V[ith]]=true;
	if(res<L) return true;
	return false;
}
void Print()
{
	int i;
	printf("---------------------\n");
	for(i=1;i<=cnt;i++)
		printf("%d %d\n",U[i],V[i]);
	printf("----------------------\n");
}
void Solve()
{
	int i;
	L=0;
	memset(result,-1,sizeof(result));
	for(i=1;i<=N;i++)
	{
		memset(flag,false,sizeof(flag));
		L+=Find(i); 
	}
	cnt=0;
	for(i=1;i<=N;i++)
	{
		if(result[i]!=-1)
		{
			cnt++;
			U[cnt]=result[i];
			V[cnt]=i; 
		} 
	}
	//Print();
	int C=0;
	for(i=1;i<=cnt;i++)
	{
		C+=Judge(i); 
	}
	printf("Board %d have %d important blanks for %d chessmen.\n",cas++,C,L);
}
int main()
{
	cas=1;
	while(scanf("%d%d%d",&N,&M,&K)!=EOF)
	{
		Init();
		Solve();
	}
return 0;
}