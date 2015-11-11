////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-10 23:15:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1207
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
__int64 w(int n)
{
	int i;
	__int64 s=1;
	for(i=1;i<=n;i++)
		s<<=1;
return s-1;
}
main ()
{
	int i,j;
	double f[65],min;
	f[1]=1;f[2]=3;
	for(i=1;i<=64;i++)
	{
		min=1000000000;
		for(j=1;j<i;j++)
		{
			f[i]=2*f[j]+w(i-j);
			if(min>f[i])
				min=f[i];
			else f[i]=min;
		}
	}
		int n;
		while(scanf("%d",&n)!=EOF)
			printf("%.0lf\n",f[n]);
return 0;
}