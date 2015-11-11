////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-28 22:54:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2504
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
int gcd(int m,int n)
{
	int t;
	if(m<n)
	{t=n;n=m;m=t;}
	if(n==0)
		return m;
	else
		return gcd(n,m%n);		
}
main ()
{
	int n,a,b,w,i;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&a,&b);
		for(i=2;;i++)
		{
			w=gcd(a,b*i);
			if(w==b)
			{printf("%d\n",b*i);break;}
		}
	}
return 0;
}