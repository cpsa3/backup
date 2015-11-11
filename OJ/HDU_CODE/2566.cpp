////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-19 23:32:49
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2566
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
		int s=0;
		for(i=0;i*5<=m;i++)
			for(j=0;j*2+i*5<=m;j++)
				if(m-j-4*i==n)
					s++;
				printf("%d\n",s);
	}
return 0;
}