////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-08-24 18:56:26
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3968
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <memory.h>
#define E 2.7182818284590452
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	double x1,y1,x2,y2,t;
	double vx,vy,t1,t2,x,ans;
	while(T--)
	{
		scanf("%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&t);
		if(x1>x2)
		{
			double t;
			t=x1;
			x1=x2;
			x2=t;
			t=y1;
			y1=y2;
			y2=t;
		}
		if(t==0)
		{printf("Impossible.\n");continue;}
		double l=x2-x1;
		double h=y2-y1;
		vx=l/t;
		vy=h/t+0.5*9.8*t;
		double a=vx*vx;
		x=vy-9.8*t;

		ans=(-1)/9.8*(x*0.5*sqrt(x*x+a)+0.5*a*log10(x+sqrt(x*x+a))/log10(E));

		x=vy;
		ans=ans-(-1)/9.8*(x*0.5*sqrt(x*x+a)+0.5*a*log10(x+sqrt(x*x+a))/log10(E));
		printf("%.3lf\n",ans);
	}
return 0;
}