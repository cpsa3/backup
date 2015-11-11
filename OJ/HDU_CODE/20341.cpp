////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-28 13:40:49
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2034
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdlib.h>
using namespace std;
int cmp(const void *x,const void *y)
{
	return *((int *)x)-*((int *)y);
}
main ()
{
	int a[101],b[101],n,m,i,j;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
			break;
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(i=1;i<=m;i++)
			scanf("%d",&b[i]);
		qsort(a+1,n,sizeof(int),cmp);
		qsort(b+1,m,sizeof(int),cmp);
		int flag=0;
		for(i=1;i<=n;i++)
		{
			if(i!=1&&a[i]==a[i-1])
				continue;
			for(j=1;j<=m;j++)
				if(a[i]==b[j])
					break;
				if(j==m+1)
				{flag=1;printf("%d ",a[i]);}
		}
		if(flag)
			printf("\n");
		else
			printf("NULL\n");
	}
return 0;
}