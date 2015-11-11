////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2010-10-03 15:08:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1248
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int t,n,i,j,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int min=99999999;
		for(i=0;i<=n/150;i++)
			for(j=0;j<=n/200;j++)
				for(k=0;k<=n/350;k++)
				{
					if(i*150+j*200+k*350<=n&&min>(n-(i*150+j*200+k*350)))
						min=n-(i*150+j*200+k*350);
				}
				printf("%d\n",min);
	}
return 0;
}
//Çî¾Ù