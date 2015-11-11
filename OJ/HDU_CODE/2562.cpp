////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-14 22:11:07
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2562
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
main  ()
{
	char a[100];
	int t,i;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		scanf("%s",a);
		for(i=0;i<=strlen(a)-2;i=i+2)
			printf("%c%c",a[i+1],a[i]);
		printf("\n");
	}
return 0;
}