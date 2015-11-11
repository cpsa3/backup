////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-11 13:32:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1143
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int f(int n)
{
	int s=0,t;
	if(n==0)
		s=1;
	else if(n==2)
		s=3;
	else  
	{
		t=n;
		s+=3*f(n-2);
		while(t>=4)
		{
			s+=2*f(n-t);
			t-=2;
		}
	}
	return s;		
}

main ()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==-1)
			break;
		if(n%2!=0)
			printf("0\n");
		else
			printf("%d\n",f(n));
	}
	return 0;
}