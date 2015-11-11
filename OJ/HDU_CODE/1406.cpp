////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-15 16:24:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1406
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int f(int n)
{
	int i,s,w;
	w=n;
	if(n==1) return 0;
	for(i=1,s=0;i<n;i++)
		if(n%i==0)
		s+=i;
	if(s==n) return 1;
	else return 0;
}
main ()
{
	int t,i,num1,num2,s;
	while(scanf("%d",&t)!=EOF)
	{
		while(t--)
		{
			scanf("%d%d",&num1,&num2);
			if(num1<=num2)
			{
			for(i=num1,s=0;i<=num2;i++)
				if(f(i))
					s++;
			}
			else 
			{
				for(i=num2,s=0;i<=num1;i++)
				if(f(i))
					s++;
			
			}
				printf("%d\n",s);
		}
	}
return 0;
}