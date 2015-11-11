////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-10 21:19:46
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2550
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdlib.h>
struct px
{
	int a,b;
};
int cmp(const void *x,const void *y)
{
	if(((struct px *)x)->a!=((struct px *)y)->a)
		return ((struct px *)x)->a-((struct px *)y)->a;
	else
		return ((struct px *)x)->b-((struct px *)y)->b;
}
struct px stu[100];
main ()
{
	int i,t,n,j,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d%d",&stu[i].a,&stu[i].b);
		qsort(stu+1,n,sizeof(stu[0]),cmp);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=stu[i].b;j++)
			{
				printf(">+");
				for(k=1;k<=stu[i].a-2;k++)
					printf("-");
				printf("+>\n");
			}
			printf("\n");
		}
	}
return 0;
}