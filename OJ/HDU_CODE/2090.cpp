////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-26 14:05:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2090
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:196KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	double sum,a,b,w;
	char v[100];
	sum=0;
	while(scanf("%s%lf%lf",v,&a,&b)!=EOF)
	{
		w=a*b;
		//int x=((int)(w*100))%10;
		//if(x>=5)
			//w=((int)w*10+1)/10;
		sum+=w;
	}
	printf("%.1lf\n",sum);
return 0;
}