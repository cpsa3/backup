////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-27 19:22:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1563
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <iostream>
int main()
{
	int n,x,i;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		int ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			ans^=x;
		}
	printf("%d\n",ans);
	}
return 0;
}