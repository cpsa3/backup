////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-06 21:02:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2061
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
float a[100000],b[100000];
char c[1000];
int main ()
{
	int T,flag=0,i,n;
	scanf("%d",&T);
	while(T--)
	{
		if(flag)
			printf("\n");
		flag=1;
		scanf("%d",&n);
		int f=0;
		for(i=1;i<=n;i++)
		{
			scanf("%s%f%f",c,&a[i],&b[i]);
			if(b[i]<60&&b[i]>=0)
				f=1;
		}
		if(f)
		{printf("Sorry!\n");continue;}
		float sum1=0,sum2=0;
		for(i=1;i<=n;i++)
		{
			sum1+=a[i]*b[i];
			sum2+=a[i];
		}
		float ans=(float)sum1*1.0/sum2;
		printf("%.2f\n",ans);
		
	}
return 0;
}