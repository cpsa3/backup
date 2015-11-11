////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-16 20:39:49
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2503
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
int f(int a,int b)
{
	int t,i;
	if(b>a)
	{t=a;a=b;b=t;}
	if(b==0)
		return a;
	else
		return f(b,a%b);
}
main ()
{
	int t,a,b,c,d,w,s,v;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		 w=a*d+c*b;
		 s=b*d;
		 v=f(w,s);
		printf("%d %d\n",w/v,s/v);
	}
	return 0;
}