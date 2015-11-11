////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-19 23:47:04
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2187
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdlib.h>
struct px
{
	int p,h;
};
struct px stu[1001];
int cmp(const void *x,const void *y)
{
	return ((struct px *)x)->p-((struct px *)y)->p;
}
main ()
{
	int t,n,m,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=m;i++)
			scanf("%d%d",&stu[i].p,&stu[i].h);
		qsort(stu+1,m,sizeof(stu[0]),cmp);
		double w=0;
		for(i=1;n;i++)
		{
			if(n>=stu[i].p*stu[i].h)
			{n-=stu[i].p*stu[i].h;w+=stu[i].h;}
			else
			{w+=n*1.0/stu[i].p;n=0;}
		}
		printf("%.2lf\n",w);
	}
return 0;
}