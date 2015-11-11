////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-11 19:15:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2521
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <iostream>
int f[5001]={0};
int fss(int n)
{
	int i,s=0;
	if(n==1)
		return 1;
	if(n==2||n==3)
		return 2;
	for(i=1;i<=n/2+1;i++)
		if(n%i==0)
			s++;
		return s+1;
}
main ()
{
	int t,i,a,b,j,temp;
	for(i=1;i<=5000;i++)
		f[i]=fss(i);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		int max=0,y=0;
		for(i=a;i<=b;i++)
		{
			if(f[i]>max)
			{
				max=f[i];
				y=i;
			}
		}
		printf("%d\n",y);
	}
	return 0;
}