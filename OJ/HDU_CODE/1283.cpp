////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-13 22:49:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1283
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
int M1,M2,R1,R2,R3;
char a[1000];
int main()
{
	int i;
	while(scanf("%d%d",&M1,&M2)!=EOF)
	{
		scanf("%s",a);
		R1=R2=R3=0;
		for(i=0;i<strlen(a);i++)
		{
			switch(a[i])
			{
			case 'A':
				R1=M1;
				break;
			case 'B':
				R2=M2;
				break;
			case 'C':
				M1=R3;
				break;
			case 'D':
				M2=R3;
				break;
			case 'E':
				R3=R1+R2;
				break;
			case 'F':
				R3=R1-R2;
				break;
			}
		}
		printf("%d,%d\n",M1,M2);
	}
	return 0;
}