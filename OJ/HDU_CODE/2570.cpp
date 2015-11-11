////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-11 17:13:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2570
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
using namespace std;
main ()
{
	int t,n,v,w,i,a[101];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&v,&w);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		int sum=0;
		double e,f;
		if(a[1]>w)
		{printf("0 0.00\n");continue;}
		else
		{
			e=a[1];
			sum+=v;
		}
		for(i=2;i<=n;i++)
		{
			f=(sum*e+a[i]*v)*1.0/(sum+v);
			if(f<=w)
			{sum+=v;e=f;}
			else
				break;
		}
		printf("%d %.2lf\n",sum,e/100); 	
	}
return 0;
}