////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-26 21:53:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1004
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdlib.h>
#include <string.h>
struct px
{
	char a[20];
};
struct px stu[1001];
int cmp(const void *x,const void *y)
{
	return strcmp(((struct px *)x)->a,((struct px *)y)->a);
}

main ()
{
	int n,i;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		for(i=1;i<=n;i++)
			scanf("%s",stu[i].a);
		qsort(stu+1,n,sizeof(stu[0]),cmp);
		//printf("\n");
		//for(i=1;i<=n;i++)
			//printf("%s\n",stu[i].a);
		char b[20],MAX[20];
		strcpy(b,stu[1].a);
		strcpy(MAX,stu[1].a);
		int max1=1,s=1;
		for(i=2;i<=n;i++)
		{
			if(!strcmp(b,stu[i].a))
			s++;
			if(strcmp(b,stu[i].a)||i==n)
			{
				if(s>max1)
				{
					max1=s;
					strcpy(MAX,b);
				}
					strcpy(b,stu[i].a);
				s=1;
			}
		}
		printf("%s\n",MAX);
	}
return 0;
}