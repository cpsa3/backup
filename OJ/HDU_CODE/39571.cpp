////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-19 00:53:49
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3957
////Problem Title: 
////Run result: Accept
////Run time:7437MS
////Run memory:208KB
//////////////////System Comment End//////////////////
/*状态压缩+迭代加深搜索*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define ll(a) (a<<1)
#define rr(a) (a<<1|1)
#define ONE (__int64(1))
#define GOAL (__int64)((ONE<<(2*N))-1)//目标状态
using namespace std;
int N,cas,pn,M,K,depth;
__int64 st[100];
__int64 rest[100];
__int64 state;
void Init()
{
	int i,j,k,u,v,ith;
	scanf("%d",&N);
	state=0;
	pn=N<<1;
	for(i=0;i<pn;i++)
	{
		st[i]=rest[i]=0;
		st[i]|=(ONE<<i);
		st[i]|=(ONE<<(i^1)); 
	}
	for(i=0;i<N;i++)
	{
		scanf("%d",&M);
		if(M==1) state|=(ONE<<rr(i));//表示已经处理
		for(j=0;j<M;j++)
		{
			u=(ll(i))|j;
			scanf("%d",&K);
			{
				for(k=0;k<K;k++)
				{
					scanf("%d%d",&v,&ith);
					v=(ll(v))|ith;
					st[u]|=(ONE<<v);
				}
			}
		}
	}
	//预处理
	rest[pn-1]=st[pn-1];
	for(i=pn-2;i>=0;i--)
		rest[i]=st[i]|rest[i+1]; 
}
bool dfs(__int64 state,int d,int p)
{
	int i;
	if(d==depth) 
		return state==GOAL;
	for(i=p;i<N;i++)
	{
		if((state|rest[ll(i)])!=GOAL) break;
		if((state|st[ll(i)])==state) continue;
		if(dfs(state|st[ll(i)],d+1,i+1)) return true;

		if((state|rest[rr(i)])!=GOAL) break;
		if((state|st[rr(i)])==state) continue;
		if(dfs(state|st[rr(i)],d+1,i+1)) return true;
	}
	return false;
}
void Solve()
{
	depth=1;
	//printf("@%I64d\n",GOAL);
	while(depth<N)
	{
		if(dfs(state,0,0))
			break;
		depth++; 
	}
	printf("Case %d: %d\n",cas++,depth);
}
int main()
{
	int T;
	cas=1;
	scanf("%d",&T);
	while(T--)
	{
		Init();
		Solve();
	}
return 0;
}
