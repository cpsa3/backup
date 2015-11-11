////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2012-03-17 10:37:21
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2608
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>
__int64 n;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%I64d",&n);
		__int64 sum =0;
		sum=(__int64)sqrt((double)n)+(__int64)sqrt((double)(n/2));
		sum=sum%2;
		printf("%I64d\n",sum);
	}
return 0;
}

