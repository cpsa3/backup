////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-11 22:26:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1092
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:280KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int n,a,s,i;
	while(cin>>n)
	{
		if(n==0)
			break;
		s=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a);
			s+=a;
		}
		cout<<s<<endl;
	}
return 0;
}