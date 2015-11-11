////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-24 19:43:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2026
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:180KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
using namespace std;
main ()
{
	int i;
	char a[101];
	while(gets(a))
	{
		for(i=0;i<strlen(a);i++)
		{
			if(i==0)
				a[i]=a[i]-32;
			if(a[i]==' ')
				a[i+1]=a[i+1]-32;
			printf("%c",a[i]);
		}
		printf("\n");
	
	}
return 0;
}