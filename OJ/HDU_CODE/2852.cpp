////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-05-05 23:01:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2852
////Problem Title: 
////Run result: Accept
////Run time:468MS
////Run memory:3700KB
//////////////////System Comment End//////////////////
/*Ïß¶ÎÊ÷*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#define MAXN 100005
#define lch(a) (2*(a))
#define rch(a) (2*(a)+1)
struct Tree
{
	int s,e,v;
}Tnode[4*MAXN];
int M;
int num[MAXN];
void Build(int p,int s,int e)
{
	Tnode[p].s=s;Tnode[p].e=e;Tnode[p].v=0;
	if(s==e) return;
	int mid=(s+e)>>1;
	Build(lch(p),s,mid);
	Build(rch(p),mid+1,e);
}
void Insert(int p,int x)
{
	Tnode[p].v++;
	if(Tnode[p].s==Tnode[p].e) return;
	int mid=(Tnode[p].s+Tnode[p].e)>>1;
	if(x<=mid) Insert(lch(p),x);
	else Insert(rch(p),x);
}
void Delete(int p,int x)
{
	Tnode[p].v--;
	if(Tnode[p].s==Tnode[p].e) return;
	int mid=(Tnode[p].s+Tnode[p].e)>>1;
	if(x<=mid) Delete(lch(p),x);
	else Delete(rch(p),x);
}
int Find(int p,int s,int e)
{
	if(Tnode[p].s==s&&Tnode[p].e==e)
		return Tnode[p].v;
	int mid=(Tnode[p].s+Tnode[p].e)>>1;
	if(e<=mid)
		return Find(lch(p),s,e);
	else if(s>mid)
		return Find(rch(p),s,e); 
	return Find(lch(p),s,mid)+Find(rch(p),mid+1,e);
}
void Query(int p,int n)
{
	//printf("&&\n");
	if(Tnode[p].s==Tnode[p].e)
	{printf("%d\n",Tnode[p].e);return;}
	if(Tnode[rch(p)].v>=n)
	{
		//printf("^%d\n",Tnode[rch(p)].v);
		Query(rch(p),n);
	}
	else
	{
		//printf("&\n");
		Query(lch(p),n-Tnode[rch(p)].v);
	}
}
int main()
{
	int i,p,a,k;
	while(scanf("%d",&M)!=EOF)
	{
		memset(num,0,sizeof(num));
		Build(1,1,100000);
		for(i=1;i<=M;i++)
		{
			scanf("%d",&p);
			if(p==0)
			{
				scanf("%d",&a);
				num[a]++;
				Insert(1,a);
			}
			else if(p==1)
			{
				scanf("%d",&a);
				if(num[a]==0) printf("No Elment!\n");
				else
				{
					num[a]--;
					Delete(1,a);
				}
			}
			else
			{
				scanf("%d%d",&a,&k);
				int n=Find(1,a+1,100000);
				//printf("*%d\n",n);
				if(n<k)
					printf("Not Find!\n");
				else
					Query(1,n-k+1);
			}
		}
	}
return 0;
}

