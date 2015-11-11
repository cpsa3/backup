////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-20 23:55:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1862
////Problem Title: 
////Run result: Accept
////Run time:375MS
////Run memory:2588KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
using namespace std;
struct student
{
	char xh[10];
	char xm[10];
	int cj;
};
struct student stu[100010];
int cmp1(const void *a,const void *b)
{
		return strcmp(((struct student *)a)->xh,((struct student *)b)->xh);
}

int cmp2(const void *a,const void *b)
{
		if(strcmp(((struct student *)a)->xm,((struct student *)b)->xm))
			return strcmp(((struct student *)a)->xm,((struct student *)b)->xm);
		else
			return strcmp(((struct student *)a)->xh,((struct student *)b)->xh);
}

int cmp3(const void *a,const void *b)
{

		if(((struct student *)a)->cj!=((struct student *)b)->cj)
			return ((struct student *)a)->cj-((struct student *)b)->cj;
		else
			return strcmp(((struct student *)a)->xh,((struct student *)b)->xh);
}

main()
{
	int n,c;
	int i=1;
	int j;
	while(scanf("%d%d",&n,&c)!=EOF)
	{
		if(n==0)
			break;
		for(j=0;j<n;j++)
			scanf("%s%s%d",stu[j].xh,stu[j].xm,&stu[j].cj);
		if(c==1)
			qsort(stu,n,sizeof(stu[0]),cmp1);
		else if(c==2)
			qsort(stu,n,sizeof(stu[0]),cmp2);
		else
			qsort(stu,n,sizeof(stu[0]),cmp3);
		printf("Case %d:\n",i);
		for(j=0;j<n;j++)
			printf("%s %s %d\n",stu[j].xh,stu[j].xm,stu[j].cj);
		i++;

	}
return 0;
}