////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-28 13:10:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2081
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int n,i;
	char w[20];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",w);
		printf("6");
		for(i=6;i<=10;i++)
			printf("%c",w[i]);
		printf("\n");
	}
return 0;
}