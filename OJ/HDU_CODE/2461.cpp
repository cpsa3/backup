////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-24 01:00:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2461
////Problem Title: 
////Run result: Accept
////Run time:2031MS
////Run memory:236KB
//////////////////System Comment End//////////////////
/*AC代码：2062ms*/
#include <iostream>
#include <algorithm>
using namespace std;
#define lch(a) (2*(a))
#define rch(a) (2*(a)+1)
#define MAXN 30
struct Line
{
    int x,y1,y2;//竖直线段的上下端点y1,y2和位置x
    int side;//side=1表示左线段,side=-1表示右线段
};
struct Line L[2*MAXN],JY[2*MAXN];
struct Tree
{
    int y1,y2,x;
    int cover;//用以表示加进线段树中的线段次数
    bool flag;//此标记用来表示是否有超元线段；为了处理方便加上去的
};
struct Tree Tnode[8*MAXN];
int Y[2*MAXN];
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
int Insert(int p,int x,int s,int e,int side)
{
    if(e<=Tnode[p].y1||s>=Tnode[p].y2)
        return 0;
    if(Tnode[p].y1>=s&&Tnode[p].y2<=e&&Tnode[p].flag)//注意一定要分到底
    {
        if(Tnode[p].cover>0)//说明有左线段
        {
            int temp_x=Tnode[p].x;//注意
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
    int ans1=Insert(lch(p),x,s,e,side);
    int ans2=Insert(rch(p),x,s,e,side);
    return ans1+ans2;
}
int main()
{
    int cas=1,i,N,M,R,j,p;
    int x1,x2,y1,y2;
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        if(N==0&&M==0) break;
        printf("Case %d:\n",cas++);
        K=1;
        for(i=1;i<=N;i++)//数据输入
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            JY[K].x=L[K].x=x1;
            JY[K].y1=L[K].y1=y1;//小
            JY[K].y2=L[K].y2=y2;//大
            JY[K].side=L[K].side=1;
            Y[K]=y1;
            K++;
            JY[K].x=L[K].x=x2;
            JY[K].y1=L[K].y1=y1;//小
            JY[K].y2=L[K].y2=y2;//大
            JY[K].side=L[K].side=-1;
            Y[K]=y2;
            K++;
        }    
        //sort(L+1,L+K,cmp);//按x对边排序
        sort(Y+1,Y+K);//对Y排序
        int ans=0;//存答案
        for(i=1;i<=M;i++)
		{
			ans=0;
			Build(1,1,K-1);//建树(范围为K)
			scanf("%d",&R);
			int k=1;
			for(j=1;j<=R;j++)
			{
				scanf("%d",&p);
				JY[k++]=L[2*p-1];
				JY[k++]=L[2*p];
			}
			sort(JY+1,JY+k,cmp);
			for(j=1;j<k;j++)
				ans+=Insert(1,JY[j].x,JY[j].y1,JY[j].y2,JY[j].side);
			printf("Query %d: %d\n",i,ans);
		}
        printf("\n");    
    }
	return 0;
}