////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-17 16:17:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2099
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int a,b,i;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		if(a==0&&b==0) break;
		int flag=0;
		for(i=0;i<=99;i++)
		{
			if((a*100+i)%b==0&&flag==0) 
			{
				flag=1;
				if(i<=9)
					printf("0%d",i);
				else printf("%d",i);
			}
			else if((a*100+i)%b==0&&flag)
			{
				if(i<=9)
					printf(" 0%d",i);
				else printf(" %d",i);
			}
		}
		printf("\n");
	}
return 0;
}