////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-29 13:25:49
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1587
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
using namespace std;
int v[10000];
int main()
{
	int N,M,i;
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		for(i=1;i<=N;i++)
			scanf("%d",&v[i]);
		sort(v+1,v+1+N);
		int ans;
		ans=M/v[1];
		printf("%d\n",ans);
	
	}

return 0;
}