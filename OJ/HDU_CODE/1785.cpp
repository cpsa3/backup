////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-29 13:51:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1785
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>
struct px
{
	double x,y;
	double v;
};
struct px stu[105];
int cmp(const void *p1,const void *p2)
{
	if(((struct px *)p2)->v>((struct px *)p1)->v)
		return 1;
	else
		return -1;
}
int main()
{
	int n,i;
	double t;
	while(scanf("%d",&n)!=EOF)
	{
		if(n<0)
			break;
		for(i=1;i<=n;i++)
		{
			scanf("%lf%lf",&stu[i].x,&stu[i].y);
			t=(stu[i].x*stu[i].x)+(stu[i].y*stu[i].y);
			t=sqrt((double)t);
			t=stu[i].x/t;
			stu[i].v=t;
			//printf("%.1lf\n",stu[i].v);
		}
		qsort(stu+1,n,sizeof(stu[0]),cmp);
		for(i=1;i<=n-1;i++)
			printf("%.1lf %.1lf ",stu[i].x,stu[i].y);
		printf("%.1lf %.1lf\n",stu[i].x,stu[i].y);
	}
return 0;
}