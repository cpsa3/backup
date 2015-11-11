////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-28 16:04:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2080
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>
main ()
{
	int t;
	double x1,y1,x2,y2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		double w,s1,s2;
		s1=sqrt(x1*x1+y1*y1);
		s2=sqrt(x2*x2+y2*y2);
		w=(x1*x2+y1*y2)*1.0/(s1*s2);
		double d;
		d=acos(w)*180/3.1415926;
		printf("%.2lf\n",d);	
	}
return 0;
}