////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-16 00:13:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2010
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:188KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int a[1001]={0};
int f(int n)
{
	int a[4];
	a[1]=n%10;
	a[2]=(n/10)%10;
	a[3]=n/100;
	if(a[1]*a[1]*a[1]+a[2]*a[2]*a[2]+a[3]*a[3]*a[3]==n)
		return 1;
	else return 0;
}
main ()
{
	int i,num1,num2;
	for(i=100;i<1000;i++)
		if(f(i))
			a[i]=1;
		while(scanf("%d%d",&num1,&num2)!=EOF)
		{
			int flag=0;
			for(i=num1;i<=num2;i++)
			{
				if(a[i]&&flag==0)
				{printf("%d",i);flag=1;continue;}
				if(a[i]&&flag==1)
					printf(" %d",i);
			}
				if(flag==0)
					printf("no\n");
				else printf("\n");
		}
return 0;
}