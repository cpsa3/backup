////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-08 16:49:07
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3874
////Problem Title: 
////Run result: Accept
////Run time:2046MS
////Run memory:10468KB
//////////////////System Comment End//////////////////
/*线段树+离散化*/
/*
离散化:区间按照e从小到大排序
*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 50005
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define lch(a) (a<<1)
#define rch(a) (a<<1|1)
using namespace std;
struct Node
{
	int s,e,id;
}node[200005];
struct Tree
{
	int s,e;
	__int64 num;
}Tnode[4*MAXN];
int W[MAXN];
int pre[MAXN];//pre[i]记录前面一个值为W[i]的下标
__int64 ans[200005];
int head[1000005],N,M;

int cmp(const void *p1,const void *p2)//区间按照e从小到大排序
{
	return ((struct Node *)p1)->e-((struct Node *)p2)->e;
}
void Build(int p,int s,int e)
{
	Tnode[p].s=s;Tnode[p].e=e;
	if(s==e) 
	{
		Tnode[p].num=W[s];
		return;
	}
	int mid=(s+e)>>1;
	Build(lch(p),s,mid);
	Build(rch(p),mid+1,e);
	Tnode[p].num=Tnode[lch(p)].num+Tnode[rch(p)].num;
}
void Delete(int p,int k)//删除第k个数
{
	
	Tnode[p].num-=W[k];
	if(Tnode[p].s==Tnode[p].e)
		return;
	int mid=(Tnode[p].s+Tnode[p].e)>>1;
	if(k<=mid)
		Delete(lch(p),k);
	else
		Delete(rch(p),k);
}
__int64 Query(int p,int s,int e)
{
	if(Tnode[p].s==s&&Tnode[p].e==e)
		return Tnode[p].num;
	int mid=(Tnode[p].s+Tnode[p].e)>>1;
	if(e<=mid)
		return Query(lch(p),s,e);
	else if(s>mid)
		return Query(rch(p),s,e);
	else
		return Query(lch(p),s,mid)+Query(rch(p),mid+1,e);
}
void Init()
{
	int i;
	memset(head,-1,sizeof(head));
	memset(pre,-1,sizeof(pre));
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		scanf("%d",&W[i]);
		pre[i]=head[W[i]];
		head[W[i]]=i;
	}
	scanf("%d",&M);
	for(i=1;i<=M;i++)
	{
		scanf("%d%d",&node[i].s,&node[i].e);
		node[i].id=i;
	}
	qsort(node+1,M,sizeof(node[0]),cmp);
	Build(1,1,N);
}
void Solve()
{
	int i,j,r=0;
	
	for(i=1;i<=M;i++)
	{
		for(j=node[i].e;j>r;j--)
		{
			if(pre[j]!=-1)
			{
				Delete(1,pre[j]);
			}
		}
		r=node[i].e;
		ans[node[i].id]=Query(1,node[i].s,node[i].e);
	}
	for(i=1;i<=M;i++)
		printf("%I64d\n",ans[i]);
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
