////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-07-30 11:36:45
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3410
////Problem Title: 
////Run result: Accept
////Run time:515MS
////Run memory:6704KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cmath>
#define MAXN 50005
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
int Max_p[MAXN][30];
int W[MAXN],N,cas;
int ll[MAXN],rr[MAXN];
void RMQ_Index()
{
	int i,j,m;
	for(i=1;i<=N;i++)
		Max_p[i][0]=i;
	m=(int)(log((double)N)/log(2.0));
	for(i=1;i<=m;i++)
	{
		for(j=1;j+(1<<i)-1<=N;j++)
			Max_p[j][i]=W[Max_p[j][i-1]]>W[Max_p[j+(1<<(i-1))][i-1]]?Max_p[j][i-1]:Max_p[j+(1<<(i-1))][i-1];
	}
}
int Index_max(int l,int r)
{
	int m=(int)(log((double)(r-l+1))/log(2.0));
	return W[Max_p[l][m]]>W[Max_p[r-(1<<m)+1][m]]?Max_p[l][m]:Max_p[r-(1<<m)+1][m];
}
void Init()
{
	int i;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
		scanf("%d",&W[i]);
	RMQ_Index();
}
int get_ll(int l,int r,int ith)
{
	if(l>r) return 0;
	if(l==r)
	{
		if(W[l]<W[ith]) return l;
		else return 0;
	}
	int id=Index_max(l,r);
	if(W[id]<W[ith]) return id;
	else
	{
		return get_ll(id+1,r,ith);
	}
}
int get_rr(int l,int r,int ith)
{
	if(l>r) return 0;
	if(l==r)
	{
		if(W[l]<W[ith]) return l;
		else return 0;
	}
	int id=Index_max(l,r);
	if(W[id]<W[ith]) return id;
	else
	{
		return get_rr(l,id-1,ith);
	}
}
void Solve()
{
	int i,j;
	for(i=1;i<=N;i++)
	{
		ll[i]=get_ll(1,i-1,i);
		rr[i]=get_rr(i+1,N,i);
	}
	printf("Case %d:\n",cas++);
	for(i=1;i<=N;i++)
		printf("%d %d\n",ll[i],rr[i]);
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