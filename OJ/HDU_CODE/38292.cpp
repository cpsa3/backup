////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-08-08 19:54:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3829
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:1220KB
//////////////////System Comment End//////////////////
/*¶þ·ÖÆ¥Åä*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cstring>
#define MAXN 1005
using namespace std;
struct Node
{
	char like[20];
	char dislike[20];
}node[1005];
bool map[MAXN][MAXN];
bool flag[MAXN];
int result[MAXN];
int N,M,P;
void Init()
{
	int i,j;
	memset(map,false,sizeof(map));
	for(i=1;i<=P;i++)
		scanf("%s%s",node[i].like,node[i].dislike);
	//¹¹Í¼
	for(i=1;i<=P;i++)
	{
		for(j=i+1;j<=P;j++)
		{
			if(!strcmp(node[i].like,node[j].dislike)||!strcmp(node[i].dislike,node[j].like))
			{
				//if(node[i].like[0]=='C')
					map[i][j]=true;
				//else
					map[j][i]=true;
			}
		}
	}
}
bool Find(int a)
{
	int i;
	for(i=1;i<=P;i++)
	{
		if(map[a][i]&&!flag[i])
		{
			flag[i]=true;
			if(result[i]==0||Find(result[i]))
			{
				result[i]=a;
				return true;
			}
		}
	}
	return false;
}
void Solve()
{
	int i,num=0;
	memset(result,0,sizeof(result));
	for(i=1;i<=P;i++)
	{
		memset(flag,false,sizeof(flag));
		if(Find(i)) num++;
	}
	printf("%d\n",P-num/2);
}
int main()
{
	while(scanf("%d%d%d",&N,&M,&P)!=EOF)
	{
		Init();
		Solve();
	}
	return 0;
}