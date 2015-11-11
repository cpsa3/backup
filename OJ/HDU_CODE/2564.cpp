////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-22 14:59:32
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2564
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <iostream>
char a[200];
main ()
{
	int t,i;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		gets(a);
		int flag=0;
		for(i=0;i<strlen(a);i++)
		{
			if(!flag)
			{
				if(a[i]>='a'&&a[i]<='z')
				{printf("%c",a[i]-32);flag=1;}
				else if(a[i]>='A'&&a[i]<='Z')
				{printf("%c",a[i]);flag=1;}
			}
			else
			{
				if(a[i]==' ')
					flag=0;
			}
		}
		printf("\n");
	}
return 0;
}