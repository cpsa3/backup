////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-18 18:12:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1047
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
main  ()
{
	int sum[10001],i,j,n;
	char a[105];
	scanf("%d",&n);
	while(n--)
	{
		memset(sum,0,sizeof(sum));
		while(scanf("%s",a)!=EOF)
		{
			if(a[0]=='0')
				break;
			for(i=strlen(a)-1,j=0;i>=0;i--,j++)
				sum[j]+=a[i]-'0';
		}
		int c=0,w;
		for(i=0;i<=10000;i++)
		{
			w=c+sum[i];
			sum[i]=w%10;
			c=w/10;
		}
		i=10000;
		while(!sum[i]) i--;
		if(i<0)
			printf("0");
		for(;i>=0;i--)
			printf("%d",sum[i]);
		printf("\n");
		if(n)
			printf("\n");
	}
return 0;
}