////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-08 11:14:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2714
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
char a[100];
int main()
{
	int i;
	while(scanf("%s",a)!=EOF)
	{
		int ans=0,k=0;
		for(i=0;i<strlen(a);i++)
		{
			if(a[i]=='?')
			{k=i;continue;}
			if(a[i]=='X')
				ans+=10;
			else
				ans+=(10-i)*(a[i]-'0');
		}
		for(i=0;i<=10;i++)
		{
			if(((10-k)*i+ans)%11==0)
				break;
		}
		if(i==11||(i==10&&k!=9))
		{printf("-1\n");continue;}
		if(i==10)
			printf("X\n");
		else
			printf("%d\n",i);
	}
	return 0;
}
