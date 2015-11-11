////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-27 19:32:13
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1465
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <iostream>
__int64 f[30];
int main()
{
	int n,i;
	f[1]=0;
	f[2]=1;
	for(i=3;i<=21;i++)
		f[i]=(i-1)*(f[i-1]+f[i-2]);//¥Ì≈≈π´ Ω
	while(scanf("%d",&n)!=EOF)
		printf("%I64d\n",f[n]);
return 0;
}