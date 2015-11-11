////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-24 01:01:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2795
////Problem Title: 
////Run result: Accept
////Run time:2234MS
////Run memory:8456KB
//////////////////System Comment End//////////////////
/*线段树*/
#include <iostream>
#define lch(a) (2*(a))
#define rch(a) (2*(a)+1)
#define MAXN 200005 
#define min(a,b) (a<b?a:b)
struct hh
{
	int x,dh;
};
struct Tree
{
	int s,e;
	hh H;//核心
}Tnode[4*MAXN];
int h,w,n,N;
void Build(int p,int s,int e)
{
	Tnode[p].s=s;Tnode[p].e=e;
	Tnode[p].H.x=s;//标记剩余高度最大的所在的列x
	Tnode[p].H.dh=w;
	if(s==e)
		return;
	int mid=(s+e)>>1;
	Build(lch(p),s,mid);
	Build(rch(p),mid+1,e);
}
void Update(int p,int k,int dh)
{
	if(Tnode[p].e==Tnode[p].s)
	{
		Tnode[p].H.dh-=dh;
		return;
	}
	int mid=(Tnode[p].s+Tnode[p].e)>>1;
	if(k<=mid)
		Update(lch(p),k,dh);
	else
		Update(rch(p),k,dh);
	if(Tnode[lch(p)].H.dh>=Tnode[rch(p)].H.dh)
		Tnode[p].H=Tnode[lch(p)].H;
	else
		Tnode[p].H=Tnode[rch(p)].H;
}
int Query(int p,int dh)
{
	if(Tnode[p].H.dh<dh)
		return -1;
	if(Tnode[p].s==Tnode[p].e)
	{
		if(Tnode[p].H.dh>=dh)
			return Tnode[p].H.x;
		else
			return -1;
	}
	int mid=(Tnode[p].s+Tnode[p].e)>>1;
	if(Tnode[lch(p)].H.dh>=dh)
		return Query(lch(p),dh);
	return Query(rch(p),dh); 
}
int main()
{
	int i,x;
	while(scanf("%d%d%d",&h,&w,&n)!=EOF)
	{
		int N=min(h,n);
		Build(1,1,N);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			int ans=Query(1,x);
			printf("%d\n",ans);
			if(ans!=-1)
				Update(1,ans,x);
		}
	}
	return 0;
}