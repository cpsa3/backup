////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-08-11 21:34:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3884
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:272KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#define MAXN 20006
#define INF 1e9
using namespace std;
struct Node
{
	int x,p;
	bool operator <(const Node & rhs) const
	{
		return x<rhs.x;
	}
}node[MAXN];
int N;
__int64 K;
__int64 ans;
void Init()
{
	int i;
	for(i=1;i<=N;i++)
		scanf("%d%d",&node[i].x,&node[i].p);
	sort(node+1,node+1+N);
}
void Solve()
{
	int i,j;
	__int64 k;
	ans=0;
	for(i=1;i<=N;i++)
	{
		int l=i-1,r=i+1,res=node[i].p;
		__int64 cost=0;
		int n=N;
		k=K;
		while(true)
		{
			if ((l==0)&&(r==n+1)) break;
			if ((r==n+1)||((l!=0)&&((node[i].x-node[l].x)<(node[r].x-node[i].x))))
			{
				if (cost+__int64(node[l].p)*(node[i].x-node[l].x)>k)
				{
					res+=(k-cost)/(node[i].x-node[l].x);
					break;
				}
				else
				{
					res+=node[l].p;
					cost+=__int64(node[l].p)*(node[i].x-node[l].x);
					l--;
				}
			}
			else
			{
				if ((cost+__int64(node[r].p)*(node[r].x-node[i].x)>k))
				{
					res+=(k-cost)/(node[r].x-node[i].x);
					break;
				}
				else
				{
					res+=node[r].p;
					cost+=__int64(node[r].p)*(node[r].x-node[i].x);
					r++;
				}
			}
		}		  
		if (res>ans) ans=res;	  
	}
	printf("%I64d\n",ans);
}
int main()
{
	while(scanf("%d%I64d",&N,&K)!=EOF)
	{
		Init();
		Solve();
	}
	return 0;
}
