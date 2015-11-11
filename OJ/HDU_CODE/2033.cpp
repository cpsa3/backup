////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-25 13:27:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2033
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
main ()
{
	int n,a[4],b[4];
	while(scanf("%d",&n)!=EOF)
	{
		while(n--)
		{
			scanf("%d%d%d%d%d%d",&a[1],&a[2],&a[3],&b[1],&b[2],&b[3]);
			int i,s[4],p;
			for(i=3;i>=2;i--)
			{
				if(a[i]+b[i]>=60)
				{s[i]=a[i]+b[i]-60;p=1;}
				else 
				{s[i]=a[i]+b[i];p=0;}
				a[i-1]+=p;
			}
			s[1]=a[1]+b[1];
			printf("%d %d %d\n",s[1],s[2],s[3]);
		}
	}
return 0;
}
