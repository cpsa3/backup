////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-03 14:55:26
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1236
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:300KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
struct student
{
	char a[25];
	int b;
	int c[20];
	int d;
};
int cmp(const void *a,const void *b)
{
	if(((struct student *)b)->d!=((struct student *)a)->d)
	return ((struct student *)b)->d-((struct student *)a)->d;
	else
		return strcmp(((struct student *)a)->a,((struct student *)b)->a);
}

main ()
{
	struct student stu[1000];
	int n,m,g,i,j,s;
	int fen[15];
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		scanf("%d%d",&m,&g);
		for(i=1;i<=m;i++)
			scanf("%d",&fen[i]);
		for(i=1;i<=n;i++)
		{
			scanf("%s%d",stu[i].a,&stu[i].b);
			for(j=1,stu[i].d=0;j<=stu[i].b;j++)
			{
				scanf("%d",&stu[i].c[j]);
				stu[i].d+=fen[stu[i].c[j]];
			}
		}
		qsort(stu+1,n,sizeof(stu[0]),cmp);
		for(i=1,s=0;i<=n;i++)
		{
			if(stu[i].d>=g)
				s++;
			else 
				break;
		}
		printf("%d\n",s);
		for(i=1;i<=s;i++)
			printf("%s %d\n",stu[i].a,stu[i].d);
	}

return 0;
}