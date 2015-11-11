////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-12-01 19:29:33
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3785
////Problem Title: 
////Run result: Accept
////Run time:484MS
////Run memory:656KB
//////////////////System Comment End//////////////////



#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 100005
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;

int N,M;
int w[MAXN];
int main()
{
	int i,j;
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		if(N==0&&M==0) break;
		for(i=1;i<=N;i++)
			scanf("%d",&w[i]);
		sort(w+1,w+1+N);
		M=min(N,M);
		for(i=N,j=M;j>=2;j--,i--)
			printf("%d ",w[i]);
		printf("%d\n",w[i]);
	}
	return 0;
}