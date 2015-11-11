////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-27 22:24:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1229
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int a,b,k,t,p,i,x,y;
	while(cin>>a>>b>>k)
	{
		int c[10]={0};
		int d[10]={0};
		if(a==0&&b==0)
			break;
		x=a;
		y=b;
		for(i=1;i<=k;i++)
		{
			t=a%10;
			p=b%10;
			c[i]=t;
			d[i]=p;
			a=a/10;
			b=b/10;
		}
		for(i=1;i<=k;i++)
		{
			if(c[i]!=d[i])
			
				
				break;
		}
		if(i==(k+1))
			cout<<"-1"<<endl;
		else
			cout<<x+y<<endl;
	}
return 0;
}