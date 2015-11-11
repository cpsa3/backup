////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-07-27 19:01:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3264
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:264KB
//////////////////System Comment End//////////////////
/*枚举圆心+二分半径*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cmath>
#define min(a,b) (a<b?a:b)
#define PI 3.14159265358979323
#define eps 1e-7
using namespace std;
struct Node
{
	int x,y,r; 
	double m_area,br;
}node[30];
int N;
double map[30][30];
double ans;
double get_l(int a,int b)
{
	double x=node[a].x-node[b].x;
	double y=node[a].y-node[b].y;
	return sqrt(double(x*x+y*y));
}
void Init()
{
	int i,j;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		scanf("%d%d%d",&node[i].x,&node[i].y,&node[i].r);
		node[i].m_area=(PI*node[i].r*node[i].r)/2.0;
		node[i].br=sqrt(node[i].m_area/PI);
	}
	for(i=1;i<=N;i++)
	{
		for(j=i+1;j<=N;j++)
		{
			map[i][j]=map[j][i]=get_l(i,j);
		}
	}
}
void swap(double &a,double &b)
{
	double t;
	if(a<b)
	{t=a;a=b;b=t;}
}
//求两圆的相交面(r1>r2,l为向圆心的距离)
double get_area(double r1,double r2,double l)
{
	double a1,a2,c1,c2,s1,s2;
	swap(r1,r2);
	if(l>=r1+r2) return 0;
	if(l<=fabs(r1-r2)) return PI*r2*r2;
	a2=(l*l+r2*r2-r1*r1)/(2*l);
	a1=l-a2;
	c1=2*acos(a1/r1);
	c2=2*acos(a2/r2);
	s1=r1*r1*c1/2-r1*r1*sin(c1)/2;
	s2=r2*r2*c2/2-r2*r2*sin(c2)/2;
	return s1+s2;
}
bool f(int ith,double mid,int a)
{
	double l=map[ith][a];
	double r1,r2;
	r1=mid;r2=node[a].r;
	if(r1<=r2) return false;
	if(r1-r2>=l) return true;
	double area=get_area(r1,r2,l);
	if((area-node[a].m_area)>eps) return true;
	return false; 
}
bool Judge(int ith,double mid)
{
	int i;
	bool ok=true;
	for(i=1;i<=N;i++)
	{
		if(i==ith) continue;
		if(!f(ith,mid,i))
		{ok=false;break;}
	}
	return ok;
}
void Run(int ith)
{
	double l,r,mid;
	l=node[ith].br;r=40000;
	while(fabs(r-l)>eps)
	{
		mid=(l+r)/2;
		if(Judge(ith,mid))
			r=mid;
		else
			l=mid; 
	}
	ans=min(ans,l);
}
void Solve()
{
	int i=1;
	ans=70000;
	for(i=1;i<=N;i++)
		Run(i);
	//double area=get_area(2,1,1.5);
	//printf("%.4lf\n",area);
	printf("%.4lf\n",ans);
	//printf("%.4lf\n",2*0.7071*0.7071*PI);
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