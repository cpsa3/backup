////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-08 19:07:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2156
////Problem Title: 
////Run result: Accept
////Run time:281MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include <iostream>
main ()
{
	int n,i,j;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		double s=0;
		for(i=n,j=1;i>=2;i--,j++)
			s+=1.0/i*j;
		s*=2;
		s+=n;
		printf("%.2lf\n",s);
	}
return 0;
}