////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-14 13:37:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1037
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
main ()
{
	int a,b,c;
	while(scanf("%d%d%d",&a,&b,&c)!=EOF)
	{
		if(a<=168)
			printf("CRASH %d\n",a);
		else if(b<=168)
			printf("CRASH %d\n",b);
		else if(c<=168)
			printf("CRASH %d\n",c);
		else
			printf("NO CRASH\n");
	}
return 0;
}