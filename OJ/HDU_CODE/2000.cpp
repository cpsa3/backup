////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-17 19:12:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2000
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdlib.h>
int cmp(const void *x,const void *y)
{
	return *((char *)x)-*((char *)y);
}
main ()
{
	char a[20];
	int i;
	while(scanf("%s",a)!=EOF)
	{
		qsort(a,3,sizeof(char),cmp);
		for(i=0;i<2;i++)
			printf("%c ",a[i]);
		printf("%c\n",a[i]);	
	}
return 0;	
}