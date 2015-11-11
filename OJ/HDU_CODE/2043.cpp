////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-26 17:10:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2043
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
main ()
{
	char a[100];
	int m,i;
	scanf("%d\n",&m);
	while(m--)
	{
		gets(a);
		if(strlen(a)<8||strlen(a)>16)
		{printf("NO\n");continue;}
		int b[5]={0};
		for(i=0;i<strlen(a);i++)
		{
			if(b[1]==0&&a[i]>='A'&&a[i]<='Z')
				b[1]=1;
			if(b[2]==0&&a[i]>='a'&&a[i]<='z')
				b[2]=1;
			if(b[3]==0&&a[i]>='0'&&a[i]<='9')
				b[3]=1;
			if(b[4]==0&&!(a[i]>='A'&&a[i]<='Z'||a[i]>='a'&&a[i]<='z'||a[i]>='0'&&a[i]<='9'))
				b[4]=1;
		}
		int s=0;
		for(i=1;i<=4;i++)
			if(b[i])
				s++;
			if(s>=3)
				printf("YES\n");
			else
				printf("NO\n");
	}
return 0;
}