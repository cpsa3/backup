////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-03 11:02:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1008
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int a[101],n,i;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int s=0;
		for(i=1;i<=n;i++)
		{
			if(i==1)
			{s+=a[i]*6+5;continue;}
			if(a[i]>a[i-1])
				s+=(a[i]-a[i-1])*6+5;
			else //if(a[i]<a[i-1])
				s+=(a[i-1]-a[i])*4+5;
		}
		printf("%d\n",s);	
	}
return 0;
}