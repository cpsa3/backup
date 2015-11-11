////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-06 22:22:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2602
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include <iostream>
int max(int a,int b){return a>b?a:b;}
int a[1001],b[1001];
int main ()
{
	int T,n,i,v,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&v);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(i=1;i<=n;i++)
			scanf("%d",&b[i]);
		int f[1001]={0};
		for(i=1;i<=n;i++)
		{
			for(j=v-b[i];j>=0;j--)
				f[j+b[i]]=max(f[j+b[i]],f[j]+a[i]);
		}
		printf("%d\n",f[v]);
	}
return 0;
}
