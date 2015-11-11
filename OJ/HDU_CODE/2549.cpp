////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-19 23:15:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2549
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include <iostream>
main ()
{
	int t,i,j;
	char a[1000],b[10];
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		scanf("%s%s",a,b);
		int w=b[0]-'0',flag=0;
		for(i=0,j=0;i<strlen(a);i++)
		{
			if(a[i]=='.')
			{flag=1;continue;}
			if(flag)
				j++;
			if(j==w)
				break;
		}
		if(i==strlen(a))
			printf("0\n");
		else
		printf("%c\n",a[i]); 
	}
return 0;
}
