////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-04-11 17:53:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1170
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:224KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int T;
	char x;
	int a,b;
	scanf("%d",&T);
	getchar();
	while(T--)
	{
		scanf("%c %d%d",&x,&a,&b);
		getchar();
		if(x=='+') printf("%d\n",a+b);
		else if(x=='-') printf("%d\n",a-b);
		else if(x=='*') printf("%d\n",a*b);
		else
		{
			if(a%b==0) printf("%d\n",a/b);
			else printf("%.2lf\n",a*1.0/b);
		}
	}
return 0;
}