////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2012-01-17 21:02:02
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2715
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:260KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
int N;
int main()
{
	int i;
	while(scanf("%d",&N)!=EOF)
	{
		int ans=1;
		if(N==1) {printf("1\n");continue;}
		if(N%2) ans++;
		for(i=3;i<=N;i++)
		{
			if(i%2)
			{
				if(N%i==0&&(N/i-i/2>=1)) ans++;
			}
			else
			{
				if(N%(i/2)==0&&(N/(i/2)&1)&&(N/i-i/2+1>=1)) ans++;
			}
		}
		printf("%d\n",ans);
	}
return 0;
}