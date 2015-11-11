////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-07 16:23:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2492
////Problem Title: 
////Run result: Accept
////Run time:421MS
////Run memory:5068KB
//////////////////System Comment End//////////////////
#include <iostream>
#define lch(a) (2*(a))
#define rch(a) (2*(a)+1)
#define MAXN 100005
struct Tree
{
	int s,e;
	__int64 v;
}Tnode[3*MAXN];
int n,max,a[MAXN];
__int64 ans,c1[MAXN][2],c2[MAXN][2];
void Build(int p,int s,int e)
{
	Tnode[p].s=s;
	Tnode[p].e=e;
	Tnode[p].v=0;
	if(s==e)
		return;
	int mid=(s+e)>>1;
	Build(lch(p),s,mid);
	Build(rch(p),mid+1,e);
}
void Insert(int p,int v)
{
	Tnode[p].v++;
	if(Tnode[p].s==Tnode[p].e)
		return;
	int mid=(Tnode[p].s+Tnode[p].e)>>1;
	if(v<=mid)
		Insert(lch(p),v);
	else
		Insert(rch(p),v);
}
__int64 Find(int p,int s,int e)
{
	if(Tnode[p].s==s&&Tnode[p].e==e)
		return Tnode[p].v;
	int mid=(Tnode[p].s+Tnode[p].e)>>1;
	if(e<=mid)
		return Find(lch(p),s,e);
	else if(s>mid)
		return Find(rch(p),s,e);
	else
		return Find(lch(p),s,mid)+Find(rch(p),mid+1,e);
}
int main()
{
	int T,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		max=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(max<a[i])
				max=a[i];
		}
		Build(1,1,max);
		ans=0;
		for(i=1;i<=n;i++)
		{
			c1[i][0]=Find(1,1,a[i]);
			c1[i][1]=i-c1[i][0]-1;
			Insert(1,a[i]);
		}
		Build(1,1,max);
		for(i=n;i>=1;i--)
		{
			c2[i][0]=Find(1,1,a[i]);
			c2[i][1]=n-i-c2[i][0];
			Insert(1,a[i]);
		}
		for(i=1;i<=n;i++)
		{
			ans+=c1[i][0]*c2[i][1];
			ans+=c1[i][1]*c2[i][0];
		}
		printf("%I64d\n",ans);
	}
return 0;
}