////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-18 00:15:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2007
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int a,b,w,s,i,t;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		w=s=0;
		if(a>b)
		{t=a;a=b;b=t;}
		for(i=a;i<=b;i++)
		{
			if(i%2==0)
				s+=i*i;
			else
				w+=i*i*i;
		}
		printf("%d %d\n",s,w);
	}
return 0;
}