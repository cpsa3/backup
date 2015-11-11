////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-10 22:35:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1108
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:268KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int min(int a,int b)
{
	return a<=b?a:b;

}
int f(int a,int b)
{
	int m=min(a,b);
	int i;
	for(i=m;i>=1;i--)
		if(a%i==0&&b%i==0)
			break;
		return a*b/i;
}

main ()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
		printf("%d\n",f(a,b));
return 0;
}