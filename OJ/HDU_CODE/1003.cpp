////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-11 10:48:49
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1003
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:600KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int m,start,end;
void f(int a[100001],int n)
{
	int i,s,t;
	for(i=1,t=1,s=0;i<=n;i++)
	{
		s+=a[i];
		if(s>m)
		{m=s;end=i;start=t;}
		if(s<0)
		{
			s=0;
			t=i+1;	
		}	
	}
	if(m==0)
	{
		for(i=2,m=a[1],start=1,end=1;i<=n;i++)
		{
			if(a[i]>m)
			{m=a[i];start=end=i;}
		}
	}
return;	
}
int b[100001];
int main ()
{
	int t,k,n,i;
	while(scanf("%d",&t)!=EOF)
	{
		for(k=1;k<=t;k++)
		{
			scanf("%d",&n);
			for(i=1;i<=n;i++)
				scanf("%d",&b[i]);
			m=-99999999;
			start=end=1;
			f(b,n);
			printf("Case %d:\n",k);
			if(k==t)
			printf("%d %d %d\n",m,start,end);
			else printf("%d %d %d\n\n",m,start,end);
		}
	}
return 0;
}