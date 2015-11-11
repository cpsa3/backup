////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-21 22:58:01
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1210
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <iostream>
main ()
{
	int n,i,t;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1,t=1;;i++)
		{
			t<<=1;
			t%=(n*2+1);
			if(t==1)
				break;
		}
		printf("%d\n",i);
	}
return 0;
}