////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-21 15:25:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1157
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:268KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
int a[10005];
using namespace std;
int main ()
{
	int n,i;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		printf("%d\n",a[(n+1)/2]); 
	}
	return 0;
} 