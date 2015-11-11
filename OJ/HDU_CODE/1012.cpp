////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-03 13:01:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1012
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <iostream>
double f[11]={0};
main ()
{
	int i,j;
	f[0]=1;f[1]=2;f[2]=2.5;
	for(i=3;i<=9;i++)
	{
		f[i]=f[i-1];
		double w=1;
		for(j=1;j<=i;j++)
			w*=j;
		f[i]+=1.0/w;
	}
	printf("n e\n");
	printf("- -----------\n");
	printf("0 1\n");
	printf("1 2\n");
	printf("2 2.5\n");
	for(i=3;i<=9;i++)
		printf("%d %.9lf\n",i,f[i]);
return 0;
}