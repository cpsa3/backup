////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-11 13:42:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1395
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:268KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int n,i,t;
	while(cin>>n)
	{
		if(n%2==0||n==1)
		{printf("2^? mod %d = 1\n",n);continue;}
		for(i=1,t=2;;i++)
		{
			if(t==1)
				break;
			t<<=1;
			t=t%n;
			
	
		
		}

	printf("2^%d mod %d = 1\n",i,n);
	
	
	}

return 0;
}