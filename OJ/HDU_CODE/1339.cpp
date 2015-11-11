////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-29 10:59:25
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1339
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int d,n,i;
	scanf("%d",&d);
	while(d--)
	{
		cin>>n;
		for(i=0;;)
		{
			if(n%2!=0)
				break;
			else
				i++;
			n=n/2;
		}
		cout<<n<<" "<<i<<endl;
	}
	return 0;
}
