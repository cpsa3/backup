////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-27 19:18:32
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1420
////Problem Title: 
////Run result: Accept
////Run time:203MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include<iostream>
int a,b,c;
__int64 mypow(int x,int n)
{
	if(n==0)
		return 1;
	if(n==1)
		return x;
	if(n&1)
		return (((mypow(x,n>>1)%c)*(mypow(x,n>>1)%c))%c*x)%c;
	return (mypow(x,n>>1)%c)*(mypow(x,n>>1)%c)%c;
}
int main()
{
	int N;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d%d%d",&a,&b,&c);
		__int64 ans;
		ans=mypow(a,b)%c;
		printf("%I64d\n",ans);
	}
return 0;
}