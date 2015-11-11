////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-29 16:21:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2048
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
__int64 f[21];
main ()
{
	int t,i,n;
	f[1]=0;f[2]=1;
	for(i=3;i<=20;i++)
		f[i]=(i-1)*(f[i-1]+f[i-2]);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		double s=1;
		s=s*f[n];
		for(i=1;i<=n;i++)
			s=s*1.0/i;
		printf("%.2lf",s*100);
		cout<<"%"<<endl;
	}
return 0;
}