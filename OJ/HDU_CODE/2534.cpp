////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-22 16:38:01
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2534
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <iostream>
__int64  gcd(__int64 a,__int64 b)
{
	__int64 t;
	if(a<b)
	{t=a;a=b;b=t;}
	t=a%b;//t<b
	while(t!=0)
	{
		a=b;
		b=t;
		t=a%b;
	}
return b;
}
main ()
{
	__int64 x,y;
	while(scanf("%I64d%I64d",&x,&y)!=EOF)
	{
		if(x==0&&y==0)
			break;
		if(gcd(x,y)==1)
			printf("%I64d\n",x*y-x-y);
		else
			printf("Inf\n");
	}
return 0;
}