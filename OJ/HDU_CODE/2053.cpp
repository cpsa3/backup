////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-02 16:16:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2053
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int n,i,flag;
	while(scanf("%d",&n)!=EOF)
	{
		flag=-1;
		for(i=1;i<=n;i++)
			if(n%i==0)
				flag=-flag;
			if(flag==1)
			printf("%d\n",flag);
			else
				printf("0\n");
	}
return 0;
}