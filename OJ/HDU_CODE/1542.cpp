////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-11-30 14:20:23
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1542
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:284KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
using namespace std;
#define lch(a) (2*(a))
#define rch(a) (2*(a)+1)
#define MAXN 105
struct Line
{
	double x,y1,y2;//竖直线段的上下端点y1,y2和位置x
	int side;//side=1表示左线段,side=-1表示右线段
};
struct Line L[2*MAXN];
struct Tree
{
	double y1,y2,x;
	int cover;//用以表示加进线段树中的线段次数
	bool flag;//此标记用来表示是否有超元线段；为了处理方便加上去的
};
struct Tree Tnode[1000*MAXN];
double Y[2*MAXN];
int K;//有K组不同的y值(离散化)
bool cmp(Line a,Line b)//比较函数，用于排序(按X从小到大)
{
	return a.x<b.x;
}
void Build(int p,int s,int e)
{
	Tnode[p].x=-1;//-1表示该区间没有线段
	Tnode[p].cover=0;
	Tnode[p].y1=Y[s];//注意
	Tnode[p].y2=Y[e];
	Tnode[p].flag=false;//表示还可以往下分
	if(s+1==e)
	{
		Tnode[p].flag=true;//表示分到底了
		return;
	}
	int mid=(s+e)>>1;
	Build(lch(p),s,mid);
	Build(rch(p),mid,e);
}
double Insert(int p,double x,double s,double e,int side)
{
	if(e<=Tnode[p].y1||s>=Tnode[p].y2)
		return 0;
	if(Tnode[p].y1>=s&&Tnode[p].y2<=e&&Tnode[p].flag)//注意一定要分到底
	{
		if(Tnode[p].cover>0)//说明有左线段
		{
			double temp_x=Tnode[p].x;//注意
			Tnode[p].x=x;//x往右移
			Tnode[p].cover+=side;//更新边的情况
			return (Tnode[p].y2-Tnode[p].y1)*(x-temp_x);
		}
		else//不能构成矩形
		{
			Tnode[p].x=x;
			Tnode[p].cover+=side;
			return 0;
		}
	}
	double ans1=Insert(lch(p),x,s,e,side);
	double ans2=Insert(rch(p),x,s,e,side);
	return ans1+ans2;
}
int main()
{
	int t,cas=1,i;
	double x1,x2,y1,y2;
	while(scanf("%d",&t)!=EOF)
	{
		if(t==0) break;
		printf("Test case #%d\n",cas++);
		K=1;
		for(i=1;i<=t;i++)//数据输入
		{
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			L[K].x=x1;
			L[K].y1=y1;//小
			L[K].y2=y2;//大
			L[K].side=1;
			Y[K]=y1;
			K++;
			L[K].x=x2;
			L[K].y1=y1;//小
			L[K].y2=y2;//大
			L[K].side=-1;
			Y[K]=y2;
			K++;
		}	
		sort(L+1,L+K,cmp);//按x对边排序
		sort(Y+1,Y+K);//对Y排序
		Build(1,1,K-1);//建树(范围为K)
		double ans=0;//存答案
		for(i=1;i<K;i++)
			ans+=Insert(1,L[i].x,L[i].y1,L[i].y2,L[i].side);
		printf("Total explored area: %.2lf\n\n",ans);	
	}
return 0;
}
