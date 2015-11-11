////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-09 22:22:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1200
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:224KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
char a[100][100];
main ()
{
	int n,i,j;
	char b[400];
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		if(n==0)
			break;
		scanf("%s",b);
		int sum=strlen(b),x=1,y=1,w=sum/n;
		for(i=0;i<sum;i++)
		{
			if(x%2!=0)
			{
			a[x][y++]=b[i];
			if(y==n+1)
			{y--;x++;}

			}
			else
			{
				a[x][y--]=b[i];
				if(y==0)
				{y++;x++;}
			}
		}
		for(i=1;i<=n;i++)
			for(j=1;j<=w;j++)
				printf("%c",a[j][i]);
			printf("\n");
	}
return 0;
}