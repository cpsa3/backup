////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-25 17:17:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3756
////Problem Title: 
////Run result: Accept
////Run time:937MS
////Run memory:636KB
//////////////////System Comment End//////////////////
/*三分*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cmath>
#define MAXN 10005
#define INF 1e6
#define eps 1e-6
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct Node
{
	double x,y,z;
	double r,h;
	void H()
	{ h=z; }
	void R()
	{ r=sqrt(x*x+y*y); }
}node[MAXN];
int N;
double l,r;
void Init()
{
	int i;
	l=0;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		scanf("%lf%lf%lf",&node[i].x,&node[i].y,&node[i].z);
		node[i].H();
		node[i].R();
		l=max(l,node[i].r);
	}
}
double fuck(double r)//计算H
{
	int i;
	double res=0;
	for(i=1;i<=N;i++)
		res=max(res,node[i].h/(r-node[i].r));
	return res*r;
}
void Solve()
{
	int i;
	r=INF;
	double ml,mr;
	while(r-l>eps)//对R三分
	{
		ml=l+(r-l)/3.0;
		mr=r-(r-l)/3.0;
		double tl=ml*ml*fuck(ml);
		double tr=mr*mr*fuck(mr);
		if(tl<tr) r=mr;
		else l=ml;
	}
	double H,R;
	H=fuck(l);
	R=l;
	printf("%.3lf %.3lf\n",H,R);
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