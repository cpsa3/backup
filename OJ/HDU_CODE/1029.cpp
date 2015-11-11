////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-14 12:50:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1029
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:1392KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
using namespace std;
int a[1000001];
main ()
{
	int n,i;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		int k=1,w=a[1];
		for(i=2;i<=n;i++)
		{	
			if(a[i]==w)
				k++;
			else
			{
				if(k>=(n+1)/2)
				{printf("%d\n",w);break;}
				k=1;
				w=a[i];
			}
			if(i==n)
			{
				if(k>=(n+1)/2)
				{printf("%d\n",w);break;}
			}
		}
	}
return 0;
}