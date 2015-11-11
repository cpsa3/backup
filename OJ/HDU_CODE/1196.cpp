////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-04-11 17:44:21
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1196
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
using namespace std;
int N;
void Solve()
{
	int k=1;
	while(1)
	{
		if(N%2==0)
			k<<=1;
		else
			break;
		N>>=1;
	}
	printf("%d\n",k);
}
int main()
{
	while(scanf("%d",&N),N)
		Solve();
return 0;
}