////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-24 21:51:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2027
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
main ()
{
	int t,i,k;
	while(scanf("%d\n",&t)!=EOF)
	{
		char a[101];
		for(k=1;k<=t;k++)
		{
			int b[6]={0};
			gets(a);
			for(i=0;i<strlen(a);i++)
			{
				if(a[i]=='a')
					b[1]++;
				else if(a[i]=='e')
					b[2]++;
				else if(a[i]=='i')
					b[3]++;
				else if(a[i]=='o')
					b[4]++;
				else if(a[i]=='u')
					b[5]++;
			}
			printf("a:%d\n",b[1]);
			printf("e:%d\n",b[2]);
			printf("i:%d\n",b[3]);
			printf("o:%d\n",b[4]);
			printf("u:%d\n",b[5]);
			if(k!=t)
				printf("\n");
		}
	}
return 0;
}