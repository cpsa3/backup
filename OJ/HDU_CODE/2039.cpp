////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-25 14:08:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2039
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:196KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>
main ()
{
	double a,b,c;
	int n;
	scanf("%d",&n);
		while(n--)
		{
			scanf("%lf%lf%lf",&a,&b,&c);
			if(a+b>c&&a+c>b&&b+c>a)
				printf("YES\n");
			else printf("NO\n");
		}
return 0;
}
