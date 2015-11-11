////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-07 22:18:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2074
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int n,i,flag=0,map[100],j;
	char a,b,c;
	while(scanf("%d %c %c",&n,&a,&b)!=EOF)
	{
		getchar();
		memset(map,0,sizeof(map));
		if((n-1)%4!=0)
		{c=a;a=b;b=c;}
		if(flag==1)
			printf("\n");
		if(n==1)
		{printf("%c\n",a);continue;}
		printf(" ");
		for(i=2;i<=n-1;i++) 
			printf("%c",a);
		printf(" \n");

		for(i=2;i<=n/2+1;i++)
		{
			printf("%c",a);
			for(j=i;j<=n-i+1;j++)
			{
				if(map[j]==0)
					map[j]=1;
				else
					map[j]=0;
				//map[j]=-map[j];
			}
			for(j=2;j<=n-1;j++)
			{
				if(map[j]==0)
					printf("%c",a);
				else
					printf("%c",b);
			}
			printf("%c\n",a);
		}
		 
		for(i=n/2+1;i>=3;i--)
		{
			printf("%c",a);
			for(j=i;j<=n-i+1;j++)
			{
				if(map[j]==0)
					map[j]=1;
				else
					map[j]=0;
				//map[j]=-map[j];
			}
			for(j=2;j<=n-1;j++)
			{
				if(map[j]==0)
					printf("%c",a);
				else
					printf("%c",b);
			}
			printf("%c\n",a);
		
		}
		printf(" ");
		for(i=2;i<=n-1;i++) 
			printf("%c",a);
		printf(" \n");
		flag=1;
	}
return 0;
}