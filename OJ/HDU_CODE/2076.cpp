////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-29 14:17:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2076
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>
main ()
{
	int t;
	double h,m,s;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf",&h,&m,&s);
		if(h>12)
			h-=12;
		double d1,d2,D;
		d1=((60*m+s)*1.0/3600+h)*360/12;
		d2=(m+s*1.0/60)*360/60;
		D=fabs(d1-d2);
		if(D>180)
			printf("%d\n",(int)(360-D));
		else
			printf("%d\n",(int)D);
	}
return 0;
}