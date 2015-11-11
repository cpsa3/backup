////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-07-27 20:39:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3685
////Problem Title: 
////Run result: Accept
////Run time:203MS
////Run memory:1372KB
//////////////////System Comment End//////////////////
/*AC代码：187ms*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 50000
using namespace std;
/*==================================================*\ 
| Graham 求凸包 O(N * logN) 
| CALL: nr = graham(pnt, int n, res); res[]为凸包点集; 
\*==================================================*/ 
struct point {double x,y;};
struct point pnt[MAXN],res[MAXN],center; 
int N,M;
bool mult(point sp,point ep,point op)
{ 
	return (sp.x-op.x)*(ep.y-op.y)>=(ep.x-op.x)*(sp.y-op.y); 
} 
bool operator<(const point &l,const point &r)
{ 
	return l.y<r.y||(l.y==r.y&&l.x<r.x); 
}
int graham(point pnt[],int n,point res[])//注意都是从0开始存
{ 
	int i,len,k=0,top=1; 
	sort(pnt,pnt+n); 
	if (n == 0) return 0; res[0]=pnt[0]; 
	if (n == 1) return 1; res[1]=pnt[1]; 
	if (n == 2) return 2; res[2]=pnt[2]; 
	for(i=2;i<n;i++) 
	{ 
		while(top&&mult(pnt[i],res[top],res[top-1]))
			top--; 
		res[++top]=pnt[i]; 
	} 
	len=top;res[++top]=pnt[n-2]; 
	for(i=n-3;i>=0;i--) 
	{ 
		while(top!=len&&mult(pnt[i],res[top],res[top-1]))
			top--; 
		res[++top]=pnt[i]; 
	} 
	return top;       // 返回凸包中点的个数 
}
//----------------------------------------------------------//
//----------------------------------------------------------// 
// 求多边形重心 
// INIT: pnt[]已按顺时针(或逆时针)排好序; 
// CALL: res = bcenter(pnt, n); 
//----------------------------------------------------------// 
point bcenter(point pnt[], int n){ 
	point p, s; 
	double tp, area = 0, tpx = 0, tpy = 0; 
	p.x = pnt[0].x; p.y = pnt[0].y; 
	for (int i = 1; i <= n; ++i) {   // point: 0 ~ n-1 
		s.x = pnt[(i == n) ? 0 : i].x; 
		s.y = pnt[(i == n) ? 0 : i].y; 
		tp = (p.x * s.y - s.x * p.y); area += tp / 2; 
		tpx += (p.x + s.x) * tp; tpy += (p.y + s.y) * tp; 
		p.x = s.x; p.y = s.y; 
	} 
	s.x = tpx / (6 * area); s.y = tpy / (6 * area); 
	return s; 
} 
void Init()
{
	int i;
	scanf("%d",&N);
	for(i=0;i<N;i++)
		scanf("%lf%lf",&pnt[i].x,&pnt[i].y); 
	center=bcenter(pnt,N);
	M=graham(pnt,N,res);
}
double mul(point p1,point p2)//点积
{
	return p1.x*p2.x+p1.y*p2.y;
}
bool Judge(point p1,point p2)//判断两个夹角是否都是锐角
{
	point a,b;
	double x1,x2,y1,y2,xo,yo;
	x1=p1.x;y1=p1.y;
	x2=p2.x;y2=p2.y;
	xo=center.x;yo=center.y;
	a.x=(x2-x1);a.y=(y2-y1);
	b.x=(xo-x1);b.y=(yo-y1);
	if(mul(a,b)<=0) return false;
	a.x=(x1-x2);a.y=(y1-y2);
	b.x=(xo-x2);b.y=(yo-y2);
	if(mul(a,b)<=0) return false;
	return true;
} 
void Solve()
{
	int i,ans=0;
	for(i=0;i<M-1;i++)
		ans+=Judge(res[i],res[i+1]);
	ans+=Judge(res[M-1],res[0]);
	//printf("&%.3lf %.3lf\n",center.x,center.y);
	printf("%d\n",ans);
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