////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-29 14:00:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1898
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <iostream>
int N;
int main()
{
	scanf("%d",&N);
	int A,B,T;
	while(N--)
	{
		scanf("%d%d%d",&A,&B,&T);
		if(T%A==T%B)
			printf("Both!\n");
		else
		{
			if(T%A<T%B)
				printf("Sempr!\n");
			else
				printf("Xiangsanzi!\n");
		}
	}
return 0;
}