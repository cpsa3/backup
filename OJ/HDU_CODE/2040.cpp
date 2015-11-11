////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-25 14:17:00
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2040
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int f(int n,int m)
{
	int i,s,w;
	for(s=0,i=1;i<=n/2+1;i++)
		if(n%i==0)
			s+=i;
		if(s!=m)
			return 0;
	for(w=0,i=1;i<=m/2+1;i++)
	      if(m%i==0)
			w+=i;
		  if(w!=n)
			  return 0;
		  return 1;
}

main ()
{
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		if(f(n,m))
			printf("YES\n");
		else printf("NO\n");
	}
return 0;
}