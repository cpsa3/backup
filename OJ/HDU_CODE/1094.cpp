////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-11 22:30:37
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1094
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