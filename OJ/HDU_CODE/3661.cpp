////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-05-19 11:34:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3661
////Problem Title: 
////Run result: Accept
////Run time:203MS
////Run memory:188KB
//////////////////System Comment End//////////////////
/*Ì°ÐÄ*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;
int a[1005],b[1005];
int main()
{
	int N,T,i,j;
	while(scanf("%d%d",&N,&T)!=EOF)
	{
		for(i=1;i<=N;i++)
			scanf("%d",&a[i]);
		for(i=1;i<=N;i++)
			scanf("%d",&b[i]);
		sort(a+1,a+1+N);
		sort(b+1,b+1+N);
		int ans=0;
		for(i=1,j=N;i<=N;i++,j--)
		{
			if(a[i]+b[j]>T)
				ans+=a[i]+b[j]-T; 
		}
		printf("%d\n",ans);
	}
return 0;
}