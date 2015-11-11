////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-12 14:59:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1280
////Problem Title: 
////Run result: Accept
////Run time:375MS
////Run memory:17872KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
using namespace std;
int a[5000];
int b[10000000];
int main()
{
	int N,M,i,j;
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		for(i=1;i<=N;i++)
			scanf("%d",&a[i]);
		int k=0;
		for(i=1;i<=N;i++)
			for(j=i+1;j<=N;j++)
			b[++k]=a[i]+a[j];
			sort(b+1,b+1+N*(N-1)/2);
			printf("%d",b[N*(N-1)/2]);
			for(i=2,j=N*(N-1)/2-1;i<=M;i++,j--)
				printf(" %d",b[j]);
			printf("\n"); 	 
	} 
return 0;
}