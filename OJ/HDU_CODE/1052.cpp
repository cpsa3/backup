////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-15 17:41:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1052
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdlib.h>
using namespace std;
int cmp(const void *x,const void *y)
{
return *((int *)y)-*((int *)x);
}
int a[1005],b[1005];
main ()
{
	int n,i,j,k,s,temp;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(j=0;j<n;j++)
			scanf("%d",&b[j]);
		qsort(a,n,sizeof(int),cmp);
		qsort(b,n,sizeof(int),cmp);
		for(i=0;a[0]<b[i]&&i<n;i++);//????????????????
			for(s=-n;i<n;i++)
			{
				temp=-i;
				for(k=i,j=0;k<n;k++,j++)
				{
					if(a[j]>b[k])
						temp++;
					else if(a[j]<b[k])
						temp--;
				}
				s=s<temp?temp:s;
			}
			printf("%d\n",s*200);
	}
	return 0;
}