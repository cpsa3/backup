////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-17 19:20:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2004
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n>=90&&n<=100)
			printf("A\n");
		else if(n>=80&&n<=89)
			printf("B\n");
		else if(n>=70&&n<=79)
			printf("C\n");
		else if(n>=60&&n<=69)
			printf("D\n");
		else if(n>=0&&n<=59)
			printf("E\n");
		else printf("Score is error!\n");
	}
return 0;
}