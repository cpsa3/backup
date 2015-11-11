////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-19 08:58:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1161
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
	char a;
	while(scanf("%c",&a)!=EOF)
	{
			if(a>='A'&&a<='Z')
				printf("%c",a+32);
			else printf("%c",a);
	}
return 0;
}