////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-08-24 18:59:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3968
////Problem Title: 
////Run result: Accept
////Run time:875MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<iostream>
#include<memory.h>
#include <cmath>
#define MAXN 35000
using namespace std;
double lim;
double gao(double vx,double &vy,double t)
{

	double d1=atan(fabs(vy/vx));
	double h=vy*lim-0.5*9.8*lim*lim;
	double l=vx*lim;
	double d2=atan(fabs(h/l));
	double d3=d1-d2;

	vy = (vy-9.8*lim);
	double s =sqrt(h*h+l*l);
	double r=s/(sin(d3)*2);
	return 2*r*d3;
	//return sum;
}
int main()
{
	int T;
	scanf("%d",&T);
	double x1,y1,x2,y2,t;
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
		lim=t/MAXN;
		double vx,vy;
		double l=x2-x1;
		double h=y2-y1;
		vx=l/t;
		vy=h/t+0.5*9.8*t;
		double i;
		double ans=0;
		for(int ii=0;ii<MAXN;ii++)
		{
			ans +=  gao(vx,vy,t);
		}
		printf("%.3lf\n",ans);
	}
	return 0;
}