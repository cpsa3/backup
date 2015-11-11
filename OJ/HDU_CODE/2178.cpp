////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-29 16:56:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2178
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <iostream>
__int64 mypow(int n)
{
	int i;
	__int64 ans=1;
	for(i=1;i<=n;i++)
		ans<<=1;
	return ans;
}
int main()
{
	int T,n;
	__int64 w;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		w=mypow(n)-1;
		printf("%I64d\n",w);
	}
return 0;
}