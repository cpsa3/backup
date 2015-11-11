////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-24 22:57:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1097
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	__int64 a,b;
	int i;
	while(scanf("%I64d%I64d",&a,&b)!=EOF)
	{
		__int64 w=a%10,s=a%10;
		int v[11];
		v[1]=s;
		for(i=2;i<=b;i++)
		{
			s=s*w%10;	
			v[i]=s;
			if(s==v[1])
				break;	
		}
		int d=b%(i-1);
		if(d==0)
			printf("%d\n",v[i-1]);
		else
			printf("%d\n",v[d]);
	}
return 0;
}