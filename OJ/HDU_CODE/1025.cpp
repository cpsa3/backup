////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-11-03 21:15:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1025
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:512KB
//////////////////System Comment End//////////////////
#include <iostream>
int dp[500005],p[500005],n;
void solve()
{
	int left,right,len=1,i,mid;
	dp[1]=p[1];
	for(i=1;i<=n;i++)
	{
		left=1;
		right=len;
		while(left<=right)
		{
			mid=(left+right)/2;
			if(dp[mid]>=p[i])
				right=mid-1;
			else
				left=mid+1;
		}
		dp[left]=p[i];
		if(left>len) len++;
	}
	printf("My king, at most %d road",len);
	if(len>1) printf("s");
	printf(" can be built.\n\n"); 
return;
}
main ()
{
	int i,a,b,k=1;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			p[a]=b;
		}
		printf("Case %d:\n",k++);
		solve();
	}
return 0;
}