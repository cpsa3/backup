////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-10-18 19:16:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1255
////Problem Title: 
////Run result: Accept
////Run time:390MS
////Run memory:644KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cmath>
#define MAXN 1100
#define eps 1e-6
#define lch(a) (a<<1)
#define rch(a) (a<<1|1)
using namespace std;

struct Line
{
	double x,y1,y2;
	int side;
}line[2*MAXN];

struct Tree
{
	double len;
	int y1,y2;
	int cover;
	double one,more; 
}Tnode[8*MAXN];
double Y[2*MAXN];
int N,K;

bool cmp(Line a,Line b)
{
	return a.x<b.x;//比较函数，用于排序(按X从小到大)
}
void Build(int p,int s,int e)
{
	Tnode[p].y1=s;
	Tnode[p].y2=e;
	Tnode[p].len=Y[e]-Y[s];
	Tnode[p].one=Tnode[p].more=0;
	Tnode[p].cover=0;
	if(s+1==e)
		return;
	int mid=(s+e)>>1;
	Build(lch(p),s,mid);
	Build(rch(p),mid,e);
}
void Update(int p)
{
	if(Tnode[p].cover>1)
	{
		Tnode[p].one=0;
		Tnode[p].more=Tnode[p].len;
	}
	else if(Tnode[p].cover==1)
	{
		Tnode[p].more=Tnode[lch(p)].one+Tnode[lch(p)].more+Tnode[rch(p)].one+Tnode[rch(p)].more;
		Tnode[p].one=Tnode[p].len-Tnode[p].more;
	}
	else       //注意(当p为叶子节点时特殊考虑)
	{
		if(Tnode[p].y1+1==Tnode[p].y2)
			Tnode[p].one=Tnode[p].more=0; 
		else
		{
			Tnode[p].one=Tnode[lch(p)].one+Tnode[rch(p)].one;
			Tnode[p].more=Tnode[lch(p)].more+Tnode[rch(p)].more;
		}
	}
}
void Insert(int p,int y1,int y2,int side)
{
	if(Tnode[p].y1==y1&&Tnode[p].y2==y2)
	{
		Tnode[p].cover+=side;
		Update(p);
		return;
	}	
	int mid=(Tnode[p].y1+Tnode[p].y2)>>1;
	if(y2<=mid) Insert(lch(p),y1,y2,side);
	else if(y1>=mid) Insert(rch(p),y1,y2,side);
	else 
	{
		Insert(lch(p),y1,mid,side);
		Insert(rch(p),mid,y2,side);
	}
	Update(p);
}
int Binary(double x)
{
	int l,r,mid;
	l=1;r=K;
	while(l!=r)
	{
		mid=(l+r)>>1;
		if(fabs(x-Y[mid])<eps) return mid;
		else if(x+eps<Y[mid]) r=mid-1;
		else l=mid+1;
	}
	return l;
}
void Init()
{
	int i;
	double x1,x2,y1,y2;
	scanf("%d",&N);
	int cnt=0;
	for(i=1;i<=N;i++)
	{
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		cnt++;
		line[cnt].x=x1;
		line[cnt].y1=y1;
		line[cnt].y2=y2;
		line[cnt].side=1;
		Y[cnt]=y1;
		cnt++;
		line[cnt].x=x2;
		line[cnt].y1=y1;
		line[cnt].y2=y2;
		line[cnt].side=-1;
		Y[cnt]=y2;
	}
	sort(line+1,line+1+2*N,cmp);
	sort(Y+1,Y+1+2*N);
	K=1;
	for(i=2;i<=2*N;i++) //离散化 
	{
		if(Y[i]!=Y[K])
			Y[++K]=Y[i];
	}
}
void Print()
{
	int i;
	for(i=1;i<=2*N;i++)
		printf("%.1lf %.1lf %.1lf %d\n",line[i].x,line[i].y1,line[i].y2,line[i].side);
	printf("******************\n");
	for(i=1;i<=K;i++)
		printf("*%.1lf\n",Y[i]);
}
void Solve()
{
	int i;
	//Print();
	Build(1,1,K);
	double ans=0;
	Insert(1,Binary(line[1].y1),Binary(line[1].y2),line[1].side);
	for(i=2;i<=2*N;i++)
	{
		ans+=(line[i].x-line[i-1].x)*Tnode[1].more;
		int y1=Binary(line[i].y1);
		int y2=Binary(line[i].y2);
		//printf("&%d %d %.2lf\n",y1,y2,Tnode[1].more);
		if(y1<y2)
			Insert(1,y1,y2,line[i].side);
	}
	printf("%.2lf\n",ans);
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