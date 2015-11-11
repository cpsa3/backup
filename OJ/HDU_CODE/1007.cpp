////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-04-12 01:24:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1007
////Problem Title: 
////Run result: Accept
////Run time:609MS
////Run memory:1792KB
//////////////////System Comment End//////////////////
/*最近点对(枚举)*/
/*AC代码：609ms*/
#include <iostream>
#include <cmath>
#define min(a,b) (a<b?a:b)
#define MAXN 100005
#define INF 99999999
#define step 2
struct point
{
	double x,y;
};
struct point ps[MAXN];
double ansr;
int N;
int cmp1(const void *p1,const void *p2)
{
	if(((struct point *)p1)->x!=((struct point *)p2)->x)
		return ((struct point *)p1)->x>((struct point *)p2)->x?1:-1;
	return ((struct point *)p1)->y>((struct point *)p2)->y?1:-1;
}
int cmp2(const void *p1,const void *p2)
{
	if(((struct point *)p1)->y!=((struct point *)p2)->y)
		return ((struct point *)p1)->y>((struct point *)p2)->y?1:-1;
	return ((struct point *)p1)->x>((struct point *)p2)->x?1:-1;
}
double get_dis(point p1,point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
void work()
{
	int i,j;
	for(i=1;i<=N;i++)
		for(j=i+1;j<=N&&j<=i+step;j++)
			ansr=min(ansr,get_dis(ps[i],ps[j]));
}
int main()
{
	int i;
	while(scanf("%d",&N)!=EOF)
	{
		if(N==0)
			break;
		for(i=1;i<=N;i++)
			scanf("%lf%lf",&ps[i].x,&ps[i].y);
		ansr=INF;
		qsort(ps+1,N,sizeof(ps[0]),cmp1);
		work();
		//qsort(ps+1,N,sizeof(ps[0]),cmp2);
		//work();
		printf("%.2lf\n",ansr/2);
	}
return 0;
}