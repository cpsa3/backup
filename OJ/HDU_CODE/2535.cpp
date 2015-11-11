////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-22 18:27:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2535
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
using namespace std;
main ()
{
	int n,a[120],i;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		int sum=n/2+1,w=0;
		for(i=1;i<=sum;i++)
			w+=a[i]/2+1;
		printf("%d\n",w);
	}
return 0;
}