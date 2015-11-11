////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-24 15:18:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2017
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
using namespace std;
main ()
{
	int t,i;
	char a[500];
	while(scanf("%d\n",&t)!=EOF)
	{
		while(t--)
		{
			scanf("%s",a);
			int s=0;
			for(i=0;i<strlen(a);i++)
				if(a[i]>='0'&&a[i]<='9')
					s++;
				printf("%d\n",s);
		}
	}

return 0;
}