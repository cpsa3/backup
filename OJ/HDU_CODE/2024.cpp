////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-24 19:33:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2024
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int t,i;
	char a[60];
	scanf("%d\n",&t);
		while(t--)
		{
			gets(a);
			int flag=0;
			if(!(a[0]>='a'&&a[0]<='z'||a[0]>='A'&&a[0]<='Z'||a[0]=='_'))
			{printf("no\n");continue;}
			for(i=1;i<strlen(a);i++)
				if(!(a[i]>='a'&&a[i]<='z'||a[i]>='A'&&a[i]<='Z'||a[i]=='_'||a[i]>='0'&&a[i]<='9'))
				{flag=1;printf("no\n");break;}
				if(flag==1)
					continue;
				printf("yes\n");
		}
return 0;
}