////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-29 14:11:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1976
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <iostream>
int main()
{
	int T,x1,x2,y1,y2,z1,z2;
	scanf("%d",&T);//Õ¸º« ‰»ÎT
	while(T--)
	{
		scanf("%d%d%d",&x1,&y1,&z1);
		scanf("%d%d%d",&x2,&y2,&z2);
		if(x1>x2)
			printf("First\n");
		else if(x1<x2)
			printf("Second\n");
		else
		{
			if(y1>y2)
				printf("First\n");
			else if(y1<y2)
				printf("Second\n");
			else
			{
				if(z1>z2)
					printf("First\n");
				else if(z1<z2)
					printf("Second\n");
				else
					printf("Same\n");
			}
		}
	}
	return 0;
}