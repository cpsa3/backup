////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-13 22:36:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1337
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <iostream>
int a[105];
int main()
{
	int T,i,n,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++)
			for(j=i;j<=n;j+=i)
				a[j]^=1;
		int ans=0;
		for(i=1;i<=n;i++)
			if(a[i])
				ans++;
			printf("%d\n",ans);
	}
return 0;
}