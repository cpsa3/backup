////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-04 20:28:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1018
////Problem Title: 
////Run result: Accept
////Run time:406MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>
using namespace std;
main()
{
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n==1)
		{printf("1\n");continue;}
		double s=0.0;
		for(i=1;i<=n;i++)
			s+=log10((double)i);
		printf("%d\n",(int)s+1);
	}
	return 0;
}