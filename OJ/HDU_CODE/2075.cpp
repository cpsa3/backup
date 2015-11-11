////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-16 14:30:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2075
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int t,a,b;
	while(scanf("%d",&t)!=EOF)
	{
		while(t--)
		{
			scanf("%d%d",&a,&b);
			if(a%b==0) printf("YES\n");
			else printf("NO\n");
		}
	}
return 0;
}