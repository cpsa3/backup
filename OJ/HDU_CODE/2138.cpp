////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-04-11 22:18:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2138
////Problem Title: 
////Run result: Accept
////Run time:234MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <cmath>
bool isPrime(int x)
{
	if(x==1) return false;
	if(x==2||x==3) return true;
	if(x%2==0) return false;
	int i;
	for(i=3;i<=sqrt((double)x);i+=2)
		if(x%i==0) return false;
		return true;
} 
int main()
{
	int i,N,x;
	while(scanf("%d",&N)!=EOF)
	{
		int ans=0;
		for(i=1;i<=N;i++)
		{
			scanf("%d",&x);
			if(isPrime(x)) ans++; 
		} 
		printf("%d\n",ans);
	}
return 0;
}