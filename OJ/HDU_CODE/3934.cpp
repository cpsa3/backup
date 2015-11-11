////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-24 19:52:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3934
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:536KB
//////////////////System Comment End//////////////////
/*求最大三角形面积(旋转卡壳)*/
/*AC代码：141ms*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 1000005
#define eps 1e-5
#define max(a,b) (a>b?a:b)
using namespace std;

/*==================================================*\ 
| Graham 求凸包 O(N * logN) 
| CALL: nr = graham(pnt, int n, res); res[]为凸包点集; 
\*==================================================*/ 
struct point {double x,y;};
struct point pnt[MAXN],res[MAXN],center; 
int N,M;
double mult(point sp,point ep,point op)//叉积
{ 
	return (sp.x-op.x)*(ep.y-op.y)-(ep.x-op.x)*(sp.y-op.y); 
} 
bool operator<(const point &l,const point &r)
{ 
	return l.y<r.y||(l.y==r.y&&l.x<r.x); 
}
int graham(point pnt[],int n,point res[])//注意都是从0开始存,res内的点最后是逆时针排好序的
{ 
	int i,len,k=0,top=1; 
	sort(pnt,pnt+n); 
	if (n == 0) return 0; res[0]=pnt[0]; 
	if (n == 1) return 1; res[1]=pnt[1]; 
	if (n == 2) return 2; res[2]=pnt[2]; 
	for(i=2;i<n;i++) 
	{ 
		while(top&&(mult(pnt[i],res[top],res[top-1])+eps>=0))
			top--; 
		res[++top]=pnt[i]; 
	} 
	len=top;res[++top]=pnt[n-2]; 
	for(i=n-3;i>=0;i--) 
	{ 
		while(top!=len&&(mult(pnt[i],res[top],res[top-1])+eps>=0))
			top--; 
		res[++top]=pnt[i]; 
	} 
	return top;       // 返回凸包中点的个数 
}
//----------------------------------------------------------//

void Init()
{
	int i;
	for(i=0;i<N;i++)
		scanf("%lf%lf",&pnt[i].x,&pnt[i].y); 
}
void Print(int m)
{
	int i;
	for(i=0;i<m;i++)
		printf("%.2lf %.2lf\n",res[i].x,res[i].y);
	printf("----------------------\n");
}
double get_Max(point res[],int m)//旋转卡壳(旋转向量):求最大三角形面积
{
	int i,p,q;
	double ans=0;
	p=1;q=2;
	res[m]=res[0];
	res[m+1]=res[1];
	res[m+2]=res[2];
	for(i=0;i<m;i++)
	{
		//旋q点
		while(mult(res[p],res[q+1],res[i])>mult(res[p],res[q],res[i])+eps)
			q=(q+1)%m;
		ans=max(ans,mult(res[p],res[q],res[i])); 
		//旋p点
		while(mult(res[p+1],res[q],res[i])>mult(res[p],res[q],res[i])+eps)
			p=(p+1)%m;
		ans=max(ans,mult(res[p],res[q],res[i])); 
	}
	return ans;
}
void Solve()
{
	int m=graham(pnt,N,res);
	//Print(m);
	double ans=get_Max(res,m);
	printf("%.2lf\n",ans/2);
}
int main()
{
	while(scanf("%d",&N)!=EOF)
	{
		//if(N==-1) break;
		Init();
		Solve();
	}
return 0;
}