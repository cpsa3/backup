////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-09-19 21:03:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1199
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:576KB
//////////////////System Comment End//////////////////
/*线段树+离散化*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define lch(a) (2*(a))
#define rch(a) (2*(a)+1)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define INF 1e8
#define MAXN 3005
using namespace std;
struct Node
{
	int s,e;
	char w;
}node[8005];
int temp[5005],X[5005],cnt;//用于离散化
struct Tree
{
	int s,e;
	int x,y;//最大区间
	int ll,rr;
	int maxs;
	int len;
	int mark;//mark=-1,表示子节点都已更新，否则子节点没更新(mark=0表示全为黑，mark=1，表示全为白)}
	void go()
	{
		if(mark==0)
		{
			maxs=ll=rr=0;
			x=y=-1;
		}
		else
		{
			maxs=ll=rr=len;
			x=X[s];y=X[e]-1;
		}
	}
}Tnode[4*MAXN];
int N;
void swap(int &a,int &b)
{
	int t;
	if(a>b)
	{t=a;a=b;b=t;}
}
void Build(int p,int s,int e)
{
	Tnode[p].s=s;Tnode[p].e=e;
	Tnode[p].x=Tnode[p].y=-1;
	Tnode[p].ll=Tnode[p].rr=Tnode[p].maxs=0;
	Tnode[p].len=X[e]-X[s];
	if(s+1==e) return;
	int mid=(s+e)>>1;
	Build(lch(p),s,mid);
	Build(rch(p),mid,e); 
}
int get_index(int x)
{
	int l=1,r=cnt;
	while(r>l)
	{
		int mid=(l+r)>>1;
		if(X[mid]>x) r=mid-1;
		else if(X[mid]<x) l=mid+1;
		else return mid;  
	}
	return l;
}
void Update(int p,int s,int e,int flag)//flag=1表示'w'，flag=0表示'b'
{
	
	if(Tnode[p].s==s&&Tnode[p].e==e)
	{
		//printf("*\n");
		Tnode[p].mark=flag;
		Tnode[p].go();//只更新到当前层，未更新下面的，用于加快速度的优化
		return;
	}
	int mid=(Tnode[p].s+Tnode[p].e)>>1;
	if(Tnode[p].mark!=-1)//要先往下更新一层//核心
	{
		Tnode[lch(p)].mark=Tnode[rch(p)].mark=Tnode[p].mark;
		Tnode[lch(p)].go();
		Tnode[rch(p)].go();
		Tnode[p].mark=-1;
	}
	if(mid>=e) Update(lch(p),s,e,flag);
	else if(s>=mid) Update(rch(p),s,e,flag);
	else
	{
		Update(lch(p),s,mid,flag);
		Update(rch(p),mid,e,flag);
	}
	if(Tnode[lch(p)].ll==Tnode[lch(p)].len)
		Tnode[p].ll=Tnode[lch(p)].len+Tnode[rch(p)].ll;
	else
		Tnode[p].ll=Tnode[lch(p)].ll;
	if(Tnode[rch(p)].rr==Tnode[rch(p)].len)
		Tnode[p].rr=Tnode[rch(p)].len+Tnode[lch(p)].rr;
	else 
		Tnode[p].rr=Tnode[rch(p)].rr;
	Tnode[p].maxs=max(Tnode[lch(p)].rr+Tnode[rch(p)].ll,max(Tnode[lch(p)].maxs,Tnode[rch(p)].maxs));
	if(Tnode[p].maxs==Tnode[lch(p)].maxs)
	{
		Tnode[p].x=Tnode[lch(p)].x;
		Tnode[p].y=Tnode[lch(p)].y;
	}
	else if(Tnode[p].maxs==Tnode[lch(p)].rr+Tnode[rch(p)].ll)
	{
		Tnode[p].x=X[Tnode[lch(p)].e]-Tnode[lch(p)].rr;//注意+1
		Tnode[p].y=X[Tnode[rch(p)].s]+Tnode[rch(p)].ll-1;
	}
	else
	{
		Tnode[p].x=Tnode[rch(p)].x;
		Tnode[p].y=Tnode[rch(p)].y;
	}
}
int main()
{
	int i;
	while(scanf("%d",&N)!=EOF)
	{
		for(i=1;i<=N;i++)
		{
			scanf("%d%d %c",&node[i].s,&node[i].e,&node[i].w);
			swap(node[i].s,node[i].e);//注意
			node[i].e++;
			temp[i]=node[i].s;temp[i+N]=node[i].e;
		}
		sort(temp+1,temp+1+2*N);
		X[1]=temp[1];
		cnt=1;
		for(i=1;i<=2*N;i++)
		{
			if(temp[i]!=X[cnt])
				X[++cnt]=temp[i];
		}
		Build(1,1,cnt);//离散化建树
		for(i=1;i<=N;i++)
		{
			if(node[i].w=='w') Update(1,get_index(node[i].s),get_index(node[i].e),1);
			else Update(1,get_index(node[i].s),get_index(node[i].e),0);
			//printf("&\n");
		}
		if(Tnode[1].maxs==0) printf("Oh, my god\n");
		else printf("%d %d\n",Tnode[1].x,Tnode[1].y);
	}
return 0;
}
