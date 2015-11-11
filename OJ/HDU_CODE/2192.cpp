////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-30 09:18:05
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2192
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:264KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
using namespace std;
int v[10005];
int main()
{
	int T,n,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&v[i]);
		sort(v+1,v+1+n);
		int ans=1,temp=1,flag=0;
		for(i=2;i<=n;i++)
		{
			if(v[i]==v[i-ans])
				ans++;
		}
		printf("%d\n",ans);
	}
 return 0;
}