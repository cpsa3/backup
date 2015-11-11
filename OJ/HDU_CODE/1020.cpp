////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-09 15:08:04
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1020
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
#include <stdlib.h>
int cmp(const void *x,const void *y)
{
return *((char *)x)-*((char *)y);
}
main ()
{
	int t,i,k;
	char a[10001];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",a);
		//qsort(a,strlen(a),sizeof(char),cmp);
		char w=a[0];
		for(i=1,k=1;i<strlen(a);i++)
		{
			
			if(w!=a[i])
			{
				if(k!=1)
					printf("%d",k);
				printf("%c",w);
				k=1;
				w=a[i];
			}
			else
				k++;
			if(i==strlen(a)-1)
			{
				if(k!=1)
					printf("%d",k);
				printf("%c\n",w);
				break;
			}
		}
	}
return 0;
}