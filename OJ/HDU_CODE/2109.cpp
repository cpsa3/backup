////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-25 23:08:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2109
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
using namespace std;
main ()
{
	int n,a[101],b[101],i;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(i=1;i<=n;i++)
			scanf("%d",&b[i]);
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		int w1=0,w2=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]>b[i])
				w1+=2;
			else if(a[i]==b[i])
			{w1++;w2++;}
			else
				w2+=2;
		}
		printf("%d vs %d\n",w1,w2);
	}
return 0;
}