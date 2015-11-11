////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-25 21:58:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2092
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:196KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>
main ()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
			break;
		if(n*n-4*m<0)
		{printf("No\n");continue;}
		double w=sqrt((n*n-4*m)*1.0);
		if(w!=(int)w)
		{printf("No\n");continue;}
		if((n-(int)w)%2!=0&&(n+(int)w)%2!=0)
		{printf("No\n");continue;}
		printf("Yes\n");
	}
	return 0;
}