////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-11-04 12:09:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3279
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
using namespace std;
main ()
{
	int T,i,a[20],k,w;
	scanf("%d",&T);
	for(k=1;k<=T;k++)
	{
		scanf("%d",&w);
		for(i=1;i<=10;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+10);
		printf("%d ",k);
		printf("%d\n",a[8]);
	}
return 0;
}