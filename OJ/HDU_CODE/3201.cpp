////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-25 20:58:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3201
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <iostream>
#define P 3.14159
int L;
int main()
{
	while(scanf("%d",&L)!=EOF)
	{
		if(L==0)
			break;
		double ans=L*L;
		printf("%.2lf\n",ans/(2*P));
	}
return 0;
}