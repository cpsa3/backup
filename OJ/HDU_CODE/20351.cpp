////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-28 15:53:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2035
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include <iostream>
int f(int m,int n,int p)
{
	int w;
	if(n==1)
		return m%p;
	w=f(m,n/2,p);
	return (w*w*(n%2?m%p:1))%p;
}
main ()
{
	int n,m;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		if(n==0&&m==0)
			break;
		printf("%d\n",f(m,n,1000)%1000);
	}
	return 0;
}