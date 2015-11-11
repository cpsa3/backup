////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2010-11-28 19:55:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3333
////Problem Title: 
////Run result: Accept
////Run time:500MS
////Run memory:3572KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define lch(a) (2*(a))
#define rch(a) (2*(a)+1)
#define MAXN 30005
#define MAXQ 100005
struct px 
{
	int s,e;
	__int64 v;
};
struct px Tnode[3*MAXN];
struct py
{
	int s,e,id;
};
struct py Q[MAXQ];
int cmp(const void *p1,const void *p2)
{
	if(((struct py *)p1)->e!=((struct py *)p2)->e)
		return ((struct py *)p1)->e-((struct py *)p2)->e;
	else
		return ((struct py *)p1)->s-((struct py *)p2)->s;
	return ((struct py *)p1)->id-((struct py *)p2)->id;	
}
int S[MAXN],N,Q1,temp[MAXN],K,mark[MAXN];
__int64 ans[MAXQ];
int Bsearch(int v)//���ֲ���
{
	int l=1,r=K;
	int mid;
	while(l<=r)
	{
		mid=(l+r+1)>>1;
		if(temp[mid]==v) return mid;
		else if(temp[mid]<v) l=mid+1;
		else r=mid-1;
	}
return mid;
}
void Build(int p,int s,int e)//����
{
	int mid=(s+e)>>1;
	Tnode[p].s=s;
	Tnode[p].e=e;
	Tnode[p].v=0;
	if(s==e)
		return;
	Build(lch(p),s,mid);
	Build(rch(p),mid+1,e);
}
__int64 Find(int p,int s,int e)//���������
{
	if(Tnode[p].s==s&&Tnode[p].e==e)
		return Tnode[p].v;
	int mid=(Tnode[p].s+Tnode[p].e)>>1;
	if(e<=mid) return Find(lch(p),s,e);
	else if(s>mid) return Find(rch(p),s,e);
	else return Find(lch(p),s,mid)+Find(rch(p),mid+1,e);
}
void Insert(int p,int k,int v)//����
{
	Tnode[p].v+=v;
	if(Tnode[p].s==Tnode[p].e)
		return;
	int mid=(Tnode[p].s+Tnode[p].e)>>1;
	if(k<=mid) Insert(lch(p),k,v);
	else Insert(rch(p),k,v);
}
int main ()
{
	int T,i,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(i=1;i<=N;i++)
		{
			scanf("%d",&S[i]);
			temp[i]=S[i];
		}
		sort(temp+1,temp+1+N);
		K=1;
		for(i=2;i<=N;i++)
		{
			if(temp[i]!=temp[i-1])
				temp[++K]=temp[i];
		}
		Build(1,1,N);
		scanf("%d",&Q1);
		for(i=1;i<=Q1;i++)
		{
			scanf("%d%d",&Q[i].s,&Q[i].e);
			Q[i].id=i;
		}
		qsort(Q+1,Q1,sizeof(Q[0]),cmp);
		memset(mark,0,sizeof(mark));
		//���Ĵ���
		int p=1;
		for(i=1;i<=N&&p<=Q1;i++)
		{
			int u=Bsearch(S[i]);
			if(mark[u])//��ʾ��ǰ���߶�����,���߶����м�ȥ
				Insert(1,mark[u],-S[i]);
			Insert(1,i,S[i]);//�ڵ�i��λ���ϲ���S[i];
			mark[u]=i;//�ص㣬��ʾS[i]��mark[u]��λ��
			while(i==Q[p].e&&p<=Q1)
			{
				ans[Q[p].id]=Find(1,Q[p].s,Q[p].e);
				p++;
			}
		}
		for(i=1;i<=Q1;i++)
			printf("%I64d\n",ans[i]);
	}
	return 0;
}