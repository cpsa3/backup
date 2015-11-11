////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-12 14:22:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1292
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <iostream>
__int64 f[26][26];
int main()
{
	int i,j,T,n;
	for(i=1;i<25;i++)
	{
		f[i][i]=1;
		f[i][0]=0;
		for(j=1;j<i;j++)
			f[i][j]=f[i-1][j-1]+f[i-1][j]*j;//µ›Õ∆ Ω
	}
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		__int64 ans=1;
		for(i=2;i<=n;i++)
			ans+=f[n][i];
		printf("%I64d\n",ans);
	}
return 0;
}
