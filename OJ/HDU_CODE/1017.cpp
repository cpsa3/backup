////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-05 20:29:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1017
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
main ()
{
	int N,i,n,m,j;
	scanf("%d",&N);
	while(N--)
	{
		int cas=1;
		while(scanf("%d%d",&n,&m)!=EOF)
		{
			if(n==0&&m==0)
				break;
			int s=0;
			for(i=2;i<n;i++)
				for(j=1;j<i;j++)
					if((i*i+j*j+m)%(i*j)==0)
						s++;
					printf("Case %d: %d\n",cas++,s);
		}
		if(N==0)
			continue;
		printf("\n");
	}
return 0;
}