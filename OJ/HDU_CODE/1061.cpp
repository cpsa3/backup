////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-06 17:43:19
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
	int t,n,start,len,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		__int64 s[20],w,flag=0;
		w=s[1]=n%10;
		for(i=2;;i++)
		{
			s[i]=(s[i-1]*n)%10;
			for(j=1;j<i;j++)
			{
				if(s[j]==s[i])
				{start=j;len=i-j;flag=1;break;}
			}
			if(flag)
				break;
		}
		w=n-(j-1);
		if(w%len!=0)
			printf("%I64d\n",s[j-1+w%len]);
		else
			printf("%I64d\n",s[i-1]);
	}
return 0;
}