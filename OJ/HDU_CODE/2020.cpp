////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-09-24 16:00:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2020
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>
using namespace std;
struct px
{
	int x,y;
};
struct px a[102];
int cmp(const void *x1,const void *y1)
{
	return ((struct px *)y1)->y-((struct px *)x1)->y;
}
main ()
{
	int m,i;
	while(scanf("%d",&m)!=EOF)
	{
		if(m==0)
			break;
		for(i=0;i<m;i++)
		{
			scanf("%d",&a[i].x);
			a[i].y=abs(a[i].x);
		}
		qsort(a,m,sizeof(a[0]),cmp);
		for(i=0;i<m-1;i++)
			printf("%d ",a[i].x);
		printf("%d\n",a[i].x);
	}
return 0;
}