////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-11-02 20:48:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1506
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:1380KB
//////////////////System Comment End//////////////////
#include <iostream>
int f[100005],l[100005],r[100005];
main () 
{
	int n,i;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		for(i=1;i<=n;i++)
			scanf("%d",&f[i]);
		for(i=1;i<=n;i++)
			l[i]=r[i]=i;
		f[0]=-1;f[n+1]=-1;
		for(i=2;i<=n;i++)
		{
			while(f[i]<=f[l[i]-1])
				l[i]=l[l[i]-1];
		}
		for(i=n-1;i>=1;i--)
		{
			while(f[i]<=f[r[i]+1])
				r[i]=r[r[i]+1];
		}
		__int64 max=0; 
		//printf("%d\n",f[1]);
		for(i=1;i<=n;i++)
		{
			if(max<(__int64)f[i]*(r[i]-l[i]+1))
				max=(__int64)f[i]*(r[i]-l[i]+1);
		}
		printf("%I64d\n",max);	
	}
return 0; 
}
