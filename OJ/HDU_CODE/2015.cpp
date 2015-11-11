////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-17 22:33:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2015
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int n,m,s,i,w,j;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int flag=0;
		for(i=1,s=2,j=1,w=0;i<=n;i++,j++,s+=2)
		{
			w+=s;
			if(i==n&&flag==0)
			{printf("%d\n",w/j);break;}
			else if(i==n&&flag)
			{printf(" %d\n",w/j);break;}
			if(j==m&&flag==0)
			{printf("%d",w/m);flag=1;w=0;j=0;}
			else if(j==m&&flag)
			{printf(" %d",w/m);w=0;j=0;}
		}
		
	}
	return 0;
}