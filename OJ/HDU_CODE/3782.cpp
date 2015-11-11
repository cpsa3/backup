////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-12-01 00:39:55
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3782
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:260KB
//////////////////System Comment End//////////////////



#include <iostream>
#include <cstdio>
using namespace std;
int N;
int main()
{
	int i,j;
	while(scanf("%d",&N),N)
	{
		int num=0;
		while(N!=1)
		{
			if(N&1) N=(3*N+1)>>1;
			else N>>=1;
			num++;
		}
		printf("%d\n",num);
	}
	return 0;
}