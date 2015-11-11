////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-25 17:57:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2041
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
int f[50];
main ()
{
	int n,s,i;
	f[0]=0;f[1]=1;f[2]=2;
	for(i=3;i<=40;i++)
		f[i]=f[i-1]+f[i-2];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&s);
		printf("%d\n",f[s-1]);
	}
return 0;
}