////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-07-30 11:49:28
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3410
////Problem Title: 
////Run result: Accept
////Run time:421MS
////Run memory:6704KB
//////////////////System Comment End//////////////////
/*RMQ+¶þ·Ö*/
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
	W[0]=W[N+1]=0;
	RMQ_Index();
}
int get_ll(int l,int r,int ith,int lim)
{
	if(l>r) return lim;
	if(l==r) 
	{
		if(W[l]<W[ith]) return l;
		else return lim; 
	}
	int mid=(l+r)>>1;
	int id1=Index_max(l,mid);
	int id2=Index_max(mid+1,r);
	if(W[id2]>W[ith])
		return get_ll(id2,r,ith,lim);
	else
	{
		lim=W[lim]>W[id2]?lim:id2;
		if(W[id1]>W[ith])
		{
			return get_ll(id1,mid,ith,lim);
		}
		else
		{
			int temp=W[id1]>W[lim]?id1:lim;
			return temp;
		}
	}
}
int get_rr(int l,int r,int ith,int lim)
{
	if(l>r) return lim;
	if(l==r) 
	{
		if(W[l]<W[ith]) return l;
		else return lim; 
	}
	int mid=(l+r)>>1;
	int id1=Index_max(l,mid);
	int id2=Index_max(mid+1,r);
	if(W[id1]>W[ith])
		return get_rr(l,id1,ith,lim);
	else
	{
		lim=W[lim]>W[id1]?lim:id1;
		if(W[id2]>W[ith])
		{
			return get_rr(mid+1,id2,ith,lim);
		}
		else
		{
			int temp=W[id2]>W[lim]?id2:lim;
			return temp;
		}
	}
}
void Solve()
{
	int i;
	for(i=1;i<=N;i++)
	{
		ll[i]=get_ll(1,i-1,i,0);
		rr[i]=get_rr(i+1,N,i,0);
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