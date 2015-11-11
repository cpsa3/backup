////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-13 22:16:05
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2140
////Problem Title: 
////Run result: Accept
////Run time:828MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
main ()
{
	char a[10002];
	int i; 
	while(scanf("%s",a)!=EOF)
	{
		for(i=0;i<strlen(a);i++)
		{
			if(a[i]=='b')
				printf(" ");
			else if(a[i]=='q')
				printf(",");
			else if(a[i]=='t')
				printf("!");
			else if(a[i]=='m')
				printf("l");
			else if(a[i]=='i')
				printf("e");
			else if(a[i]=='c')
				printf("a");
			else if(a[i]=='a')
				printf("c");
			else if(a[i]=='e')
				printf("i");
			else if(a[i]=='l')
				printf("m");
			else
				printf("%c",a[i]);
		}
		printf("\n");
	}
return 0;
}