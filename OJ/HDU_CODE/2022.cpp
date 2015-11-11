////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-24 19:02:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2022
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>
using namespace std;
main ()
{
	int m,n,i,j,w;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		int max=0,x,y,flag=1;
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
			{
				scanf("%d",&w);
				if(max<abs(w))
				{
					max=abs(w);x=i;y=j;
					if(w<0)
						flag=-1;
					else
						flag=1;
				}
			}
			printf("%d %d %d\n",x,y,max*flag);
	}
return 0;
}