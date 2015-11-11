////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-11-02 16:02:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1422
////Problem Title: 
////Run result: Accept
////Run time:234MS
////Run memory:2172KB
//////////////////System Comment End//////////////////
#include <iostream>
int a[200002],b[200002],c[200002];
main ()
{
	int n,i;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1;i<=n;i++)
			scanf("%d%d",&a[i],&b[i]);
		for(i=1;i<=n;i++)
			a[i]-=b[i];
		for(i=n+1;i<=2*n;i++)
			a[i]=a[i-n];
		memset(c,0,sizeof(c));
		int ans=0,max=0;
		for(i=1;i<=2*n;i++)
		{
			if(c[i-1]>=0)
			{
				c[i]=c[i-1]+a[i];
				if(c[i]>=0)
					max++;
				if(ans<max)
					ans=max;
			}
			else
			{
				c[i]=a[i];
				max=0;
				if(c[i]>=0)
					max++;
				if(ans<max)
					ans=max;
			}
			if(ans==n)
				break;
		}
		printf("%d\n",ans);
	}
return 0;
}