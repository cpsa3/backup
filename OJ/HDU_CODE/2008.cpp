////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-19 09:03:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2008
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:196KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int n,a,b,c,i;
	double w;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		a=b=c=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lf",&w);
			if(w<0) a++;
			else if(w==0) b++;
			else c++;
		}
		printf("%d %d %d\n",a,b,c);
	}
return 0;
}