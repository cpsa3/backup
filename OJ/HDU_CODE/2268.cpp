////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-05-01 22:36:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2268
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
/*ÊýÑ§Ìâ*/
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	double a,b,c,x,t;
	while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF)
	{
		if(a>=b) 
		{printf("%.3lf\n",c/a);continue;}
		x=(b*b*c-a*a*c)/(2*a*b-3*a*a+b*b);
		t=x/b+(c-x)/a;
		printf("%.3lf\n",t);
	}
return 0;
}