////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2010-10-04 21:35:01
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2058
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>
main ()
{
	int n,m,d;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
			break;
		for(d=sqrt((double)2.0*m);d>=1;d--)//dҪ�Ӵ�С���
		{
			int w=m-(1+d)*d/2;
			if(w%d==0)
				printf("[%d,%d]\n",w/d+1,w/d+d);
		}
		printf("\n");
	}
return 0;
}