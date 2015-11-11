////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-21 11:50:32
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1077
////Problem Title: 
////Run result: Accept
////Run time:1265MS
////Run memory:240KB
//////////////////System Comment End//////////////////
/*几何题*/
/*枚举任意两个点，确定圆心，然后遍历所有点统计在该圆内的点的个数*/
/*AC代码：1250ms*/
#include <iostream>
#include <cmath>
const double eps=1e-6;
const int MAXN=305;
struct point 
{
	double x,y; 
};
struct point ps[MAXN];
int N;
double get_dis(point a,point b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
void get_center(point a,point b)
{
	double ox,oy,dx,dy,r,temp;
	ox=(a.x+b.x)/2;
	oy=(a.y+b.y)/2;
	dx=b.x-a.x;
	dy=b.y-a.y;
	ps[N].x=ox;ps[N].y=oy;
	temp=get_dis(ps[N],b);
	r=sqrt(1.0-temp);
	if(fabs(dx)<eps)//竖直的情况
		ps[N].x-=r;//+或-都可以
	else
	{
		double ang=atan(-dy/dx);
		ps[N].x-=r*sin(ang);//+或-都可以
		ps[N].y-=r*cos(ang);
	}
}
int main()
{
	int T,i,j,k,max;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(i=0;i<N;i++)
			scanf("%lf%lf",&ps[i].x,&ps[i].y);
		int ans=1;
		for(i=0;i<N;i++)//枚举O(n^2)
		{
			for(j=i+1;j<N;j++)
			{
				if(get_dis(ps[i],ps[j])>=4) continue;
				get_center(ps[i],ps[j]);
				for(k=0,max=0;k<N;k++)
				{
					if(N-k+max<=ans) break;
					double temp=sqrt(get_dis(ps[k],ps[N]));
					if(temp<=1.000001)
						max++;
				}
				if(max>ans)
					ans=max;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
