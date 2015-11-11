////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-07 23:01:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3911
////Problem Title: 
////Run result: Accept
////Run time:687MS
////Run memory:10860KB
//////////////////System Comment End//////////////////
/*线段树*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 100005
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define lch(a) (a<<1)
#define rch(a) (a<<1|1)
using namespace std;
struct Tree
{
	int s,e,len;
	int ll1,rr1,maxs1;//黑色
	int ll0,rr0,maxs0;//白色 
	bool mark;//是否需要被更新true:需要;false:不需要
	void go()//颜色改变
	{
		int ll,rr,maxs;
		ll=ll1;ll1=ll0;ll0=ll;
		rr=rr1;rr1=rr0;rr0=rr;
		maxs=maxs1;maxs1=maxs0;maxs0=maxs;
	}
}Tnode[4*MAXN];
int N,Q;
int col[MAXN];
void fuck(int p)//向上更新一层
{
	//更新黑色
	Tnode[p].maxs1=max(Tnode[lch(p)].rr1+Tnode[rch(p)].ll1,max(Tnode[lch(p)].maxs1,Tnode[rch(p)].maxs1));
	Tnode[p].ll1=Tnode[lch(p)].ll1;
	if(Tnode[lch(p)].ll1==Tnode[lch(p)].len) Tnode[p].ll1+=Tnode[rch(p)].ll1;
	Tnode[p].rr1=Tnode[rch(p)].rr1;
	if(Tnode[rch(p)].rr1==Tnode[rch(p)].len) Tnode[p].rr1+=Tnode[lch(p)].rr1;

	//更新白色
	Tnode[p].maxs0=max(Tnode[lch(p)].rr0+Tnode[rch(p)].ll0,max(Tnode[lch(p)].maxs0,Tnode[rch(p)].maxs0));
	Tnode[p].ll0=Tnode[lch(p)].ll0;
	if(Tnode[lch(p)].ll0==Tnode[lch(p)].len) Tnode[p].ll0+=Tnode[rch(p)].ll0;  
	Tnode[p].rr0=Tnode[rch(p)].rr0;
	if(Tnode[rch(p)].rr0==Tnode[rch(p)].len) Tnode[p].rr0+=Tnode[lch(p)].rr0;
}
void Build(int p,int s,int e)
{
	Tnode[p].s=s;Tnode[p].e=e;Tnode[p].len=(e-s+1);Tnode[p].mark=false;
	if(s==e)
	{
		Tnode[p].ll1=Tnode[p].rr1=Tnode[p].maxs1=col[s];
		Tnode[p].ll0=Tnode[p].rr0=Tnode[p].maxs0=col[s]^1;
		return; 
	}
	int mid=(s+e)>>1;
	Build(lch(p),s,mid);
	Build(rch(p),mid+1,e);
	fuck(p); 
}
void Update(int p,int s,int e)
{
	if(Tnode[p].s==s&&Tnode[p].e==e)
	{
		Tnode[p].go();
		Tnode[p].mark^=1;
		return; 
	}
	int mid=(Tnode[p].s+Tnode[p].e)>>1;
	if(Tnode[p].mark)//先往下更新一层
	{
		Tnode[p].mark=false;
		Tnode[lch(p)].go();
		Tnode[rch(p)].go(); 
		Tnode[lch(p)].mark^=1;
		Tnode[rch(p)].mark^=1;
	}
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
	if(Tnode[p].s==s&&Tnode[p].e==e)
	{
		return Tnode[p].maxs1;
	}
	int mid=(Tnode[p].s+Tnode[p].e)>>1;
	if(Tnode[p].mark)//往下更新
	{
		Tnode[p].mark=false;
		Tnode[lch(p)].go();
		Tnode[rch(p)].go(); 
		Tnode[lch(p)].mark^=1;
		Tnode[rch(p)].mark^=1;
		fuck(p); 
	}
	if(e<=mid)
		return Query(lch(p),s,e);
	else if(s>mid)
		return Query(rch(p),s,e);
	else
	{
		int res_l=Query(lch(p),s,mid);
		int res_r=Query(rch(p),mid+1,e);
		int ll=Tnode[lch(p)].rr1;
		int rr=Tnode[rch(p)].ll1;
		ll=min(ll,(mid-s+1));
		rr=min(rr,(e-mid));
		return max(ll+rr,max(res_l,res_r)); 
	} 
}
void Init()
{
	int i;
	for(i=1;i<=N;i++)
		scanf("%d",&col[i]);
	Build(1,1,N);//建树 
}
void Solve()
{
	int kind,s,e;
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d%d%d",&kind,&s,&e);
		if(kind)//改变颜色
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