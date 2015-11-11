////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-06 15:30:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1013
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
char a[1000];
int f(int n)
{
	int s=0,i;
	for(i=0;i<n;i++)
		s=s+a[i]-'0';
return s;
}
int f1(int n)
{
	int s=0;
	while(n)
	{
		s+=n%10;
		n/=10;
	}
return s;
}
main ()
{
	while(scanf("%s",a)!=EOF)
	{
		if(a[0]=='0')
			break;
		int s=f(strlen(a));
		while(s>9)
		{
			s=f1(s);
		}
		printf("%d\n",s);
	}
return 0;
}