////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-11 22:37:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1096
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:272KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int t,i,j,n,w;
	while(cin>>t)
	{
		for(i=1;i<=t;i++)
		{
			scanf("%d",&n);
			int s=0;
			for(j=1;j<=n;j++)
			{
				scanf("%d",&w);
				s+=w;
			}
			if(i<t)
				printf("%d\n\n",s);
			else printf("%d\n",s);//◊¢“‚µ„
		}
	}
	return 0;
}