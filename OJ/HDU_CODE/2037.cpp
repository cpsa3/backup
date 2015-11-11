////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-25 13:53:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2037
////Problem Title: 
////Run result: Accept
////Run time:281MS
////Run memory:188KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdlib.h>
int count=0,n;
struct px
{
	int start,end,id;
};
struct px stu[101];
int cmp(const void *x,const void *y)
{
	if(((struct px *)x)->start!=((struct px *)y)->start)
		return ((struct px *)x)->start-((struct px *)y)->start;
	else return ((struct px *)x)->end-((struct px *)y)->end;
}
void dfs(int k,int w,int s)
{
	int i;
	if(k>count)
		count=k;
	for(i=w+1;i<=n;i++)
	{
		if(stu[i].start>=stu[s].end)
			dfs(k+1,i,i);
	}	
return;	
}

main ()
{
	int i;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&stu[i].start,&stu[i].end);
			stu[i].id=i;
		}
		qsort(stu+1,n,sizeof(stu[0]),cmp);
		count=0;
		for(i=1;i<=n;i++)
			dfs(1,i,i);
		printf("%d\n",count);
	}
return 0;
}