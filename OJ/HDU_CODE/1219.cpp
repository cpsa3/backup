////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-21 23:14:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1219
////Problem Title: 
////Run result: Accept
////Run time:765MS
////Run memory:276KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
char a[100001];
main ()
{
	while(gets(a))
	{
		int b[27]={0};
		int i;
		for(i=0;i<strlen(a);i++)
		{
			if(a[i]>='a'&&a[i]<='z')
				b[a[i]-96]++;
		}
		for(i=1;i<=26;i++)
				printf("%c:%d\n",i+96,b[i]);
		printf("\n");
	}
return 0;
}