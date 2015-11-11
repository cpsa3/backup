////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-06 17:49:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1061
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
main ()
{
	int t,n,len,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		__int64 s[20],w;
		w=s[1]=n%10;
		for(i=2;;i++)
		{
			s[i]=(s[i-1]*n)%10;
			if(s[i]==s[1])
				break;
		}
		len=i-1;
		if(n%len!=0)
			printf("%I64d\n",s[n%len]);
		else
			printf("%I64d\n",s[i-1]);
	}
return 0;
}