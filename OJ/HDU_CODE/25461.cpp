////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-23 20:48:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2546
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
using namespace std;
main ()
{
	int n,a[1001],m,i,j;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		scanf("%d",&m);
		if(m<5)
		{printf("%d\n",m);continue;}
		int f[1100]={0},max=0;
		f[0]=1;
		for(i=1;i<=n;i++)
		{
			for(j=m-5;j>=0;j--)
				if(f[j])
				{
					f[j+a[i]]=1;
					if(max<j+a[i])
						max=j+a[i];
				}
		}
			printf("%d\n",m-max);
	}
return 0;
}