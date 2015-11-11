////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-24 14:46:36
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2016
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int a[100],n,i;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		scanf("%d",&a[1]);
		int min=a[1],w=1;
		for(i=2;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(min>a[i])
			{min=a[i];w=i;}
		}
		int t;
		t=a[1];
		a[1]=a[w];
		a[w]=t;
		for(i=1;i<n;i++)
			printf("%d ",a[i]);
		printf("%d\n",a[i]);
	}
return 0;
}