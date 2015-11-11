////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-05-19 11:55:32
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2202
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:684KB
//////////////////System Comment End//////////////////
/*凸包+枚举*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 50005
#define max(a,b) (a>b?a:b)
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
double cross(point a,point b,point c)
{
	return ((b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x))/2;
}
int main()
{
	int N,i,j,k;
	while(scanf("%d",&N)!=EOF)
	{
		for(i=0;i<N;i++)
			scanf("%lf%lf",&pnt[i].x,&pnt[i].y);
		int m=graham(pnt,N,res);
		double ans=0;
		for(i=0;i<m;i++)
		{
			for(j=i+1;j<m;j++)
			{
				for(k=j+1;k<m;k++)
					ans=max(ans,cross(res[i],res[j],res[k])); 
			} 
		} 
		printf("%.2lf\n",ans);
	}
return 0;
}
