////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-25 09:26:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2029
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	char a[100];
	int n,i,j;
	while(scanf("%d",&n)!=EOF)
	{
		while(n--)
		{
			scanf("%s",a);
			int m=strlen(a)-1;
			for(i=0,j=m;i<j;i++,j--)
			if(a[i]!=a[j])
				break;
			if(i<j)
				printf("no\n");
			else 
				printf("yes\n");
		}
	}
return 0;
}