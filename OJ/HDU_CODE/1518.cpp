////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-23 10:21:13
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1518
////Problem Title: 
////Run result: Accept
////Run time:828MS
////Run memory:240KB
//////////////////System Comment End//////////////////

#include <iostream>
#include <stdlib.h>
int mark[30],a[30],n,m,l;
int cmp(const void *a,const void *b)
{
	return *((int *)b)-*((int *)a);
}
int dfs(int c,int sum,int k)
{
	int i;
	if(c==3)
		return 1;
	if(sum==l) return dfs(c+1,0,0);
	for(i=k;i<m;i++)
		if(!mark[i]&&a[i]+sum<=l)
		{
			mark[i]=1;
			if(dfs(c,sum+a[i],i+1))
				return 1;
			mark[i]=0;
		}
return 0;
}


main ()
{
	int i,s;
	while(scanf("%d",&n)!=EOF)
	{
		while(n--)
		{
			scanf("%d",&m);
			for(i=0,s=0;i<m;i++)
			{
				scanf("%d",&a[i]);
				s+=a[i];
			}
			l=s/4;
			memset(mark,0,sizeof(mark));
			qsort(a,m,sizeof(int),cmp);
			if(s%4!=0||a[0]>l)
				printf("no\n");
			else
			{
				if(dfs(0,0,0))
					printf("yes\n");
				else
					printf("no\n");
			}
		}

	}
return 0;
}