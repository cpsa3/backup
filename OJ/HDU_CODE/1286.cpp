////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-04-11 22:55:01
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1286
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <cmath>
int euler(int m)
{
	int i,s=1;
	for(i=2;i*i<=m;i++)
	{
		if(m%i==0)
		{
			m/=i;
			s*=(i-1);
			while(m%i==0)
			{
				m/=i;
				s*=i;
			}
		}
	}
	if(m>1)
		s*=(m-1);
	return s;
}

int main()
{
	int T,N;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		printf("%d\n",euler(N));
	}
return 0;
}