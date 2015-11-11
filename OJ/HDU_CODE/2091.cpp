////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-25 22:57:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2091
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:188KB
//////////////////System Comment End//////////////////
#include <iostream>
main ()
{
	char x;
	int n,i,j;
	int flag=0;
	while(1)
	{ 
		scanf("%c",&x);
		if(x=='@')
			break;
		scanf("%d",&n);
		if(flag)
			printf("\n");
		for(i=n-1;i>=1;i--)
		{
			for(j=1;j<=i;j++)
				printf(" ");
			printf("%c",x);
			for(j=1;j<=(n-i-1)*2-1;j++)
				printf(" ");
			if(i!=n-1)
				printf("%c",x);
			printf("\n");
		}

		for(i=1;i<=2*n-1;i++)
			printf("%c",x);
		printf("\n");
		flag=1;
		getchar();//÷’µ„
	}
return 0;
}