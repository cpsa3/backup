////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-08 15:41:23
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2113
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
int f(int n)
{
	int s=0,w;
	if(n==0)
		return 0;
	if(n<0)
		n=-n;
	while(n)
	{
		w=n%10;
		n/=10;
		if(w%2==0)
			s+=w;	
	}
return s;
}
main ()
{
	int n,flag=0;
	while(scanf("%d",&n)!=EOF)
	{
		if(flag==1)
			printf("\n");
		printf("%d\n",f(n));
		flag=1;
	}
return 0;
}