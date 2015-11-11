////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-05 19:53:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1032
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int f(int n)
{
	int i=1;
	for(i=1;n!=1;i++)
	{
		if(n%2==1)
			n=3*n+1;
		else
			n/=2;
	}
return i;
}
main ()
{
	int n,m,i;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int max=0,flag=0;
		if(n>m)
		{flag=1;swap(n,m);}
		for(i=n;i<=m;i++)
			if(max<f(i))
				max=f(i);
			if(flag)
				printf("%d %d %d\n",m,n,max);
			else
			printf("%d %d %d\n",n,m,max);
	}
return 0;
}