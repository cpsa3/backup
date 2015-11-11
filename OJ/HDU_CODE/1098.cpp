////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-06 20:17:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1098
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
main ()
{
	int k,i;
	while(scanf("%d",&k)!=EOF)
	{
		if(k%65==0)
		{printf("no\n");continue;}
		else
		{
			for(i=1;;i++)
			{
				if(i==66)
				{printf("no\n");break;}
				if((18+i*k)%65==0)
				{printf("%d\n",i);break;}
			}
		}
	}
return 0;
}