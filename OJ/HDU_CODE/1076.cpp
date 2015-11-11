////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-03 14:16:26
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1076
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include <iostream>
int f(int n)
{
	if(n%4==0&&n%100!=0||n%400==0)
		return 1;
	return 0; 
}
main ()
{
	int t,i,Y,N;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&Y,&N);
		int s=0;
		for(i=Y;;i++)
		{
			if(f(i))
				s++;
			if(s==N)
				break;
		}
		printf("%d\n",i);
	}
return 0;
}