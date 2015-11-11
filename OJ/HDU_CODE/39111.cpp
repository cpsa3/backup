////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-20 00:52:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3911
////Problem Title: 
////Run result: Accept
////Run time:828MS
////Run memory:10880KB
//////////////////System Comment End//////////////////
/*线段树*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 100005
#define lch(a) (a<<1)
#define rch(a) (a<<1|1)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
struct Tree
{
	int s,e,len;
	int ll_b,rr_b,maxs_b;
	int ll_w,rr_w,maxs_w;
	bool mark;
	void go()
	{
		int t;
		t=ll_b;ll_b=ll_w;ll_w=t;
		t=rr_b;rr_b=rr_w;rr_w=t;
		t=maxs_b;maxs_b=maxs_w;maxs_w=t;
	}
}Tnode[4*MAXN];
int W[MAXN];
int N,Q;
void fuck(int p)
{
	//更新黑色
	Tnode[p].ll_b=Tnode[lch(p)].ll_b;
	if(Tnode[lch(p)].len==Tnode[lch(p)].ll_b)
		Tnode[p].ll_b+=Tnode[rch(p)].ll_b;

	Tnode[p].rr_b=Tnode[rch(p)].rr_b;
	if(Tnode[rch(p)].len==Tnode[rch(p)].rr_b)
		Tnode[p].rr_b+=Tnode[lch(p)].rr_b;

	Tnode[p].maxs_b=max(Tnode[lch(p)].rr_b+Tnode[rch(p)].ll_b,max(Tnode[lch(p)].maxs_b,Tnode[rch(p)].maxs_b));

	//更新白色
	Tnode[p].ll_w=Tnode[lch(p)].ll_w;
	if(Tnode[lch(p)].len==Tnode[lch(p)].ll_w)
		Tnode[p].ll_w+=Tnode[rch(p)].ll_w;

	Tnode[p].rr_w=Tnode[rch(p)].rr_w;
	if(Tnode[rch(p)].len==Tnode[rch(p)].rr_w)
		Tnode[p].rr_w+=Tnode[lch(p)].rr_w;

	Tnode[p].maxs_w=max(Tnode[lch(p)].rr_w+Tnode[rch(p)].ll_w,max(Tnode[lch(p)].maxs_w,Tnode[rch(p)].maxs_w));

}
void Build(int p,int s,int e)
{
	Tnode[p].s=s;Tnode[p].e=e;Tnode[p].mark=false;Tnode[p].len=(e-s+1);
	if(s==e)
	{
		Tnode[p].ll_b=Tnode[p].rr_b=Tnode[p].maxs_b=W[s];
		Tnode[p].ll_w=Tnode[p].rr_w=Tnode[p].maxs_w=(W[s]^1);
		return;
	}
	int mid=(s+e)>>1;
	Build(lch(p),s,mid);
	Build(rch(p),mid+1,e);
	fuck(p);//更新p节点
}
void Init()
{
	int i;
	for(i=1;i<=N;i++)
		scanf("%d",&W[i]);
	scanf("%d",&Q);
}
void Update(int p,int s,int e)
{
	if(Tnode[p].s==s&&Tnode[p].e==e)
	{
		
		Tnode[p].go();
		Tnode[p].mark^=1;
		return ;
	}
	if(Tnode[p].mark)
	{
		Tnode[p].mark=0;
		Tnode[lch(p)].go();
		Tnode[rch(p)].go();
		Tnode[lch(p)].mark^=1;
		Tnode[rch(p)].mark^=1;
		//fuck(p);//注意
	}
	int mid=(Tnode[p].s+Tnode[p].e)>>1;
	if(e<=mid)
		Update(lch(p),s,e);
	else if(s>mid)
		Update(rch(p),s,e);
	else
	{
		Update(lch(p),s,mid);
		Update(rch(p),mid+1,e);
	}
	fuck(p);
}
int Query(int p,int s,int e)
{
	int res,res1,res2;
	if(Tnode[p].s==s&&Tnode[p].e==e)
		return Tnode[p].maxs_b;
	if(Tnode[p].mark)
	{
		Tnode[p].mark=false;
		Tnode[lch(p)].go();
		Tnode[rch(p)].go();
		Tnode[lch(p)].mark^=1;
		Tnode[rch(p)].mark^=1;
		fuck(p);//注意
	}
	int mid=(Tnode[p].s+Tnode[p].e)>>1;
	if(e<=mid)
		res=Query(lch(p),s,e);
	else if(s>mid)
		res=Query(rch(p),s,e);
	else
	{
		res1=Query(lch(p),s,mid);
		res2=Query(rch(p),mid+1,e);
		int ll=Tnode[lch(p)].rr_b;
		int rr=Tnode[rch(p)].ll_b;
		ll=min(ll,(mid-s+1));
		rr=min(rr,(e-mid));
		res=max(ll+rr,max(res1,res2));
	}
	fuck(p);
	return res;
}
void Solve()
{
	int s,e,kind;
	Build(1,1,N);
	//printf("*%d\n",Tnode[1].maxs_w);
	while(Q--)
	{
		scanf("%d%d%d",&kind,&s,&e);
		if(kind)
		{
			Update(1,s,e);
		}
		else
		{
			int ans=Query(1,s,e);
			printf("%d\n",ans);
		}
	}
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