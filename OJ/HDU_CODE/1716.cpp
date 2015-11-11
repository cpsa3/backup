////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-04-11 20:37:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1716
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
int ans[200],num,a[5],b[5];
bool vis[5];
void dfs(int n)
{
	int res,i;
	if(n==5)
	{
		res=b[1]*1000+b[2]*100+b[3]*10+b[4];
		for(i=0;i<num;i++)
		{if(ans[i]==res) break;}
		if(i==num)
			ans[num++]=res;
		return;
	}
	for(i=1;i<=4;i++)
	{
		if(!vis[i])
		{
			vis[i]=true;
			b[n]=a[i];
			dfs(n+1);
			vis[i]=false;
		}
	}
}
int main()
{
	int i;
	bool ok=false;
	while(scanf("%d%d%d%d",&a[1],&a[2],&a[3],&a[4])!=EOF)
	{
		if(a[1]+a[2]+a[3]+a[4]==0) break;
		if(ok) printf("\n");
		else ok=true;
		sort(a+1,a+5);
		num=0;
		for(i=1;i<=4;i++)
		{
			if(a[i])
			{
				memset(vis,false,sizeof(vis));
				vis[i]=true;
				b[1]=a[i];
				dfs(2);
			}
		}
		bool flag=false;
		int pre=ans[0]/1000;
		for(i=0;i<num;i++)
		{
			if(ans[i]/1000==pre)
			{
				if(!flag)
				{printf("%d",ans[i]);flag=true;}
				else
					printf(" %d",ans[i]);
			}
			else
			{printf("\n%d",ans[i]);pre=ans[i]/1000;}
		}
		printf("\n");
	}
return 0;
}