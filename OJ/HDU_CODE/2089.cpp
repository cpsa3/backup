////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-02 20:32:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2089
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:4116KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int A(int n)
{
	int i=1;
	while(n)
	{
		if(n%10==4||n%100==62)
			return i;
		n/=10;
		i*=10;	
	}
	return 0;
}

main ()
{
	int *a=new int[1000001];//æ≤Ã¨…Í«Îø’º‰
	int b,c,n,m,i;
	a[0]=0;//≥ı ºªØ
	for(c=0,i=1;i<=1000000;i+=b)
	{
		b=A(i);
		if(!b)
			c+=b=1;
		for(n=0;n<b;n++)
			a[i+n]=c;
	}
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
			break;
		printf("%d\n",a[m]-a[n-1]);
	}
return 0;
}