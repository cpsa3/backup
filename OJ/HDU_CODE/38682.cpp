////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-09 21:26:37
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3868
////Problem Title: 
////Run result: Accept
////Run time:203MS
////Run memory:696KB
//////////////////System Comment End//////////////////
/*分治算法求最小点对*/  
/*AC代码：828ms*/  
#include <iostream>  
#include <cmath>  
#include <algorithm>  
#define MAXN 20005
#define INF 1e10
using namespace std;  
struct Point  
{  
    double x,y;  
};  
struct Point point[MAXN],*px[MAXN],*py[MAXN];  
double ans;
int N;

double dis(Point *p1,Point *p2)  
{  
    return sqrt((p1->x-p2->x)*(p1->x-p2->x)+(p1->y-p2->y)*(p1->y-p2->y));  
}  
bool cmpx(Point *p1,Point *p2) {return p1->x<p2->x;}  
bool cmpy(Point *p1,Point *p2) {return p1->y<p2->y;}  

double min(double a,double b){return a<b?a:b;}  

//-------核心代码------------//  
void closest(int s,int e)  
{  
	//printf("*\n");
	int i,j,k;
	double d1,d2;
    if(s==e||s+1==e)  return;
    if(s+2==e) 
	{
		ans=min(ans,dis(px[s],px[s+1])+dis(px[s+1],px[e])+dis(px[s],px[e]));
		return ;
	}

    int mid=(s+e)>>1;  
	closest(s,mid);
	closest(mid+1,e); 

    int cnt=0;  
    for(i=s;i<=e;i++)//把x坐标在px[mid].x-ans~px[mid].x+ans范围内的点取出来  
    {  
		//if(fabs(px[mid]->x-px[i]->x)<ans/2)
		//	py[cnt++]=px[i];
        if(px[i]->x>=px[mid]->x-ans&&px[i]->x<=px[mid]->x+ans)  
            py[cnt++]=px[i];  
    }  
    sort(py,py+cnt,cmpy);//按y坐标排序  

    for(i=0;i<cnt;i++)  
    {  
        for(j=i+1;j<cnt&&j<=i+7;j++)//py数组中的点是按照y坐标升序的  
        {  
			d1=dis(py[i],py[j]);
			if(d1>ans/2) continue;
			for(k=j+1;k<cnt&&k<=j+7;k++)
			{
				d2=dis(py[i],py[k])+dis(py[j],py[k]);
				ans=min(ans,d1+d2);
			} 
        }  
    }  
}  
void Init()
{
	int i;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%lf%lf",&point[i].x,&point[i].y);  
        px[i]=&point[i];
	}
	sort(px,px+N,cmpx); 
}
void Solve()
{
	ans=INF;
	closest(0,N-1);
	printf("%.3lf\n",ans);
}
int main()  
{  
    int i,T;
	scanf("%d",&T);
	while(T--)
	{
		Init();
		Solve();
	}
    return 0;  
}  