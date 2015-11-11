////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-30 09:43:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2200
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <iostream>
__int64 f[100];
__int64 mypow(int n)
{
	__int64 ans=1;
	int i;
	for(i=1;i<=n;i++)
		ans<<=1;
	return ans;
}
int main()
{
	int i,n;
	f[2]=1;f[3]=5; 
	for(i=4;i<100;i++)
		f[i]=(i-1)*mypow(i-2)+f[i-1];
	while(scanf("%d",&n)!=EOF)
		printf("%I64d\n",f[n]); 
return 0;
}