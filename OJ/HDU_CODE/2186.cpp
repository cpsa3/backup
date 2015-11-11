////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-08 23:30:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2186
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
main ()
{
	int t,n,a,b,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		a=n/2;
		b=(n-a)*2/3;
		c=n-a-b;
		int w=0;
		w+=a/10;
		w+=b/10;
		w+=c/10;
		if(a%10!=0)
			w++;
		if(b%10!=0)
			w++;
		if(c%10!=0)
			w++;
		printf("%d\n",w);
	}
return 0;
}