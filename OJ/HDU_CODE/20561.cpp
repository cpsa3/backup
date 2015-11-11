////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-02 18:42:01
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2056
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
using namespace std;
double MAX(double a,double b)
{
	return a>b?a:b;
}
double MIN(double a,double b)
{
	return a<b?a:b;
}

main ()
{
	int i;
	double a[3],b[3],x[5],y[5];
	while(scanf("%lf%lf",&x[1],&y[1])!=EOF)
	{
		for(i=2;i<=4;i++)
			scanf("%lf%lf",&x[i],&y[i]);
		if(x[1]>x[2]) swap(x[1],x[2]);
		if(x[3]>x[4]) swap(x[3],x[4]);
		if(y[1]>y[2]) swap(y[1],y[2]);
		if(y[3]>y[4]) swap(y[3],y[4]);
		/*a[1]=MAX(x[1],x[3]);
		a[2]=MIN(x[2],x[4]);
		b[1]=MAX(y[1],y[3]);
		b[2]=MIN(y[2],y[4]);*/
		a[1] = x[1] > x[3] ? x[1] : x[3];
        a[2] = x[2] < x[4] ? x[2] : x[4];
        b[1] = y[1] > y[3] ? y[1] : y[3];
        b[2] = y[2] < y[4] ? y[2] : y[4];
		printf("%.2f\n", a[1]<a[2] && b[1]<b[2]? (b[2]-b[1])*(a[2]-a[1]) : 0);
		/*if(b[2]>b[1]&&a[2]>a[1])
			printf("%.2lf\n",(a[2]-a[1])*(b[2]-b[1]));
		else 
			printf("0\n");*/
	}
return 0;
}