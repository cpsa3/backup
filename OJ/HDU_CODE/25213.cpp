////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-11 19:18:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2521
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <iostream>
int f[5001]={0};
main ()
{
	int t,i,a,b,j;
	for(i=1;i<=5000;i++)
		f[i]=1;
	for(i=1;i<=5000;i++)
		for(j=1;j*i<=5000;j++)
		f[i*j]++;
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