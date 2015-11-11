////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-29 15:46:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2114
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:236KB
//////////////////System Comment End//////////////////
/*1^3 + 2^3 + °≠°≠ n^3 = [n (n+1) / 2]^2=£®1+2+°≠°≠+n£©^2*/
#include <iostream>
int ans[100000];
__int64 N;
int main()
{
	
	while(scanf("%I64d",&N)!=EOF)
	{
		N=(N+1)*N/2;
		N=N%10000;
		N=N*N;
		N=N%10000;
		printf("%04I64d\n",N);
	}
return 0;
}