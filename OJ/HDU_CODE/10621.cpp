////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2010-10-09 17:01:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1062
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
using namespace std;
main ()
{
	int t,k,i;
	char a[1001];
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		gets(a);
		char b[1001];
		for(i=0,k=0;;i++)
		{
			b[k++]=a[i];
			if(a[i]==' '||a[i]=='\0')
			{
				b[k-1]='\0';// Ò»¸öµ¥´Ê½áÊø
				printf("%s",strrev(b));//* µ¹ÖÃ×Ö·û´®
				if(a[i]=='\0')
				{printf("\n");break;}
				else
				{
					printf(" ");
					k=0;
				}
			}
		}
	}
return 0;
}