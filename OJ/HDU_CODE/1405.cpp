////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-27 18:16:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1405
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:276KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>
int prime[65537];
void get_prime()
{
	int k=0;
	for(long i=1;i<=65536;i++)
	{
		long a=1;
		for(long n=2;n<=sqrt((double)i);n++)
		{
			a=a*(i%n);
			if(i%n>=2)
				a=a/2;
		}
		if(a!=0)
			prime[k++]=i;
	}
}
int main()
{
	int n,i,k=1;
	get_prime();
	//for(i=0;i<=10;i++)
	//	printf("%d ",prime[i]);
	while(scanf("%d",&n)!=EOF)
	{
		if(n<=0)
			break;
		if(k==1)
			printf("Case %d.\n",k++);
		else
			printf("\nCase %d.\n",k++);
		i=1;
		while(n!=1)
		{
			int w=0;
			while(n%prime[i]==0)
			{
				w++;
				n/=prime[i];
			}
			if(w!=0)
				printf("%d %d ",prime[i],w);
			i++;
		}
		printf("\n");
	}
	return 0;
}