////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-17 16:36:00
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2098
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:196KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <math.h>
using namespace std;
int f(int n)
{
	int i,flag=0;
	if(n==1) return 0;
	for(i=2;i<=sqrt(n*1.0)+1;i++)
		if(n%i==0)
		{flag=1;break;}
		if(flag==1) return 0;
		else return 1;
}

main ()
{
	int m,i;
	while(scanf("%d",&m)!=EOF)
	{
		if(m==0) break;
		int s=0;
		for(i=2;i<m/2;i++)
		{
			if(f(i)&&f(m-i))
				s++;
		}
		printf("%d\n",s);
	}
return 0;
}