////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-14 16:01:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2524
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
main ()
{
	int t,i,j,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		int w=0;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
			w+=(n-i+1)*(m-j+1);
			printf("%d\n",w);
	}
return 0;
}