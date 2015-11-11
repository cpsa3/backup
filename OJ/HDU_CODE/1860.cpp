////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-19 23:51:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1860
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int i,j;
	char a[6];
	char b[100];
	while(gets(a))
	{
		if(a[0]=='#')
			break;
		gets(b);
		int c[20]={0};
		for(i=0;i<strlen(a);i++)
		{
			for(j=0;j<strlen(b);j++)
				if(a[i]==b[j])
					c[i]++;
		}
		for(i=0;i<strlen(a);i++)
			printf("%c %d\n",a[i],c[i]);

	}
return 0;
}