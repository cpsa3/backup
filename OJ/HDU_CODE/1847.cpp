////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-22 13:52:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1847
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <iostream>
int f[1001];
main ()
{
	int i,n;
	f[1]=f[2]=f[4]=f[5]=1;
	f[0]=f[3]=f[6]=0;
	for(i=7;i<=1000;i++)
	{
		int temp=1;
		while(i-temp>=0)
		{
			if(f[i-temp]==0)
			{f[i]=1;break;}
			temp<<=1;
		}
	}
	while(scanf("%d",&n)!=EOF)
	{
		if(f[n])
			printf("Kiki\n");
		else
			printf("Cici\n");
	}
return 0;
}