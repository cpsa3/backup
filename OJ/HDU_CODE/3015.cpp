////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-05-10 22:08:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3015
////Problem Title: 
////Run result: Accept
////Run time:265MS
////Run memory:4776KB
//////////////////System Comment End//////////////////
/*线段树*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <cstdlib>
#define MAXN 100005
#define lch(a) (2*(a))
#define rch(a) (2*(a)+1)
using namespace std;
struct Node
{
	__int64 h,x,id_h,id_x;
}node[MAXN];
struct Tree
{
	int s,e;
	__int64 num,sum;
}Tnode[4*MAXN];
int N;
int cmp1(const void *p1,const void *p2)//对h排序
{
	return ((struct Node *)p1)->h-((struct Node *)p2)->h;
}
int cmp2(const void *p1,const void *p2)//对x排序
{
	return ((struct Node *)p1)->x-((struct Node *)p2)->x;
}
void Build(int p,int s,int e)
{
	Tnode[p].s=s;Tnode[p].e=e;
	Tnode[p].num=Tnode[p].sum=0;
	if(s==e) return;
	int mid=(s+e)>>1;
	Build(lch(p),s,mid);
	Build(rch(p),mid+1,e);
}
void Insert(int p,int x)
{
	Tnode[p].num++;
	Tnode[p].sum+=x;
	if(Tnode[p].s==Tnode[p].e) return;
	int mid=(Tnode[p].s+Tnode[p].e)>>1;
	if(x<=mid) Insert(lch(p),x);
	else Insert(rch(p),x);
}
__int64 Q_num(int p,int s,int e)
{
	if(Tnode[p].s==s&&Tnode[p].e==e)
		return Tnode[p].num;
	int mid=(Tnode[p].s+Tnode[p].e)>>1;
	if(s>mid)
		return Q_num(rch(p),s,e);
	else if(e<=mid)
		return Q_num(lch(p),s,e);
	return Q_num(lch(p),s,mid)+Q_num(rch(p),mid+1,e);
}
__int64 Q_sum(int p,int s,int e)
{
	if(Tnode[p].s==s&&Tnode[p].e==e)
		return Tnode[p].sum;
	int mid=(Tnode[p].s+Tnode[p].e)>>1;
	if(s>mid)
		return Q_sum(rch(p),s,e);
	else if(e<=mid)
		return Q_sum(lch(p),s,e);
	return Q_sum(lch(p),s,mid)+Q_sum(rch(p),mid+1,e);
}
void Init()
{
	int i;
	__int64 cnt,pre;
	for(i=1;i<=N;i++)
		scanf("%I64d%I64d",&node[i].x,&node[i].h);
	//printf("*\n");
	qsort(node+1,N,sizeof(node[0]),cmp2);
	cnt=1;pre=node[1].x;
	for(i=1;i<=N;i++)
	{
		if(pre==node[i].x)
			node[i].id_x=cnt;
		else
		{
			node[i].id_x=i;
			pre=node[i].x;
			cnt=i;
		}
	}
	qsort(node+1,N,sizeof(node[0]),cmp1);
	cnt=1;pre=node[1].h;
	for(i=1;i<=N;i++)
	{
		if(pre==node[i].h)
			node[i].id_h=cnt;
		else
		{
			node[i].id_h=i;
			pre=node[i].h;
			cnt=i;
		}
	}
	//for(i=1;i<=N;i++)
	//	printf("%I64d ",node[i].id_h);
}
void Solve()
{
	int i;
	__int64 ans=0,sum1,sum2,num1,num2;
	Build(1,1,N);
	Insert(1,node[N].id_x);
	for(i=N-1;i>=1;i--)
	{
		if(node[i].id_x-1==0) sum1=num1=0;//特殊处理(不然会进死循环)
		else 
		{
			sum1=Q_sum(1,1,node[i].id_x-1);
			num1=Q_num(1,1,node[i].id_x-1);
		}
		if(node[i].id_x+1==N+1) sum2=num2=0;//特殊处理
		else
		{
			sum2=Q_sum(1,node[i].id_x+1,N);
			num2=Q_num(1,node[i].id_x+1,N);
		}
		ans=ans+node[i].id_h*(num1*node[i].id_x-sum1+sum2-num2*node[i].id_x);
		Insert(1,node[i].id_x);
	}
	printf("%I64d\n",ans);
}
int main()
{
	while(scanf("%d",&N)!=EOF)
	{
		Init();
		Solve();
	}
return 0;
}