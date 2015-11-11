////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-11 17:23:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2537
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
main ()
{
	int n,i;
	char a[20];
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		if(n==0)
			break;
		scanf("%s",a);
		int r=0,y=0;
		for(i=0;i<strlen(a)-1;i++)
		{
			if(a[i]=='R')
				r++;
			else
				y++;
		}
		if(a[i]=='B')
		{
			if(r==7)
				printf("Red\n");
			else
				printf("Yellow\n");
		}
		else
		{
			if(y==7)
				printf("Yellow\n");
			else
				printf("Red\n");
		}
	}
return 0;
}