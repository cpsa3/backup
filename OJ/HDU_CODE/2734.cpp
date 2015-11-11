////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-07 23:34:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2734
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
char a[1000];
int main ()
{
	int i;
	while(gets(a)!=NULL)
	{
		if(a[0]=='#')
			break;
		__int64 ans=0;
		for(i=0;i<strlen(a);i++)
		{
			if(a[i]==' ')
				continue;
			ans+=(i+1)*(a[i]-'A'+1);
		}
		printf("%I64d\n",ans);
	}
return 0;
}