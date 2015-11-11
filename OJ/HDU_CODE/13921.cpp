////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-05-19 00:13:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1392
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:240KB
//////////////////System Comment End//////////////////
/*凸包*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <memory.h>
#define MAXN 105
using namespace std;
/*==================================================*\ 
| Graham 求凸包 O(N * logN) 
| CALL: nr = graham(pnt, int n, res); res[]为凸包点集; 
\*==================================================*/ 
struct point {double x,y;};
struct point pnt[MAXN],res[MAXN]; 
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
double get_dis(point p1,point p2)
{return sqrt((double)((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)));}
int main()
{
	int i,N;
	while(scanf("%d",&N),N)
	{
		for(i=0;i<N;i++)
			scanf("%lf%lf",&pnt[i].x,&pnt[i].y);
		int m=graham(pnt,N,res);
		double ans=0;
		for(i=0;i<m-1;i++)
			ans+=get_dis(res[i],res[i+1]);
		ans+=get_dis(res[m-1],res[0]);
		if(N==2) ans/=2;
		printf("%.2lf\n",ans);
	}
return 0;
}