////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-05-03 13:34:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1828
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:440KB
//////////////////System Comment End//////////////////
/*AC代码：16ms*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define lch(a) (2*(a))
#define rch(a) (2*(a)+1)
#define MAXN 5005
struct Line
{
	int x,y1,y2;//竖直线段的上下端点y1,y2和位置x
	int side;//side=1表示左线段,side=-1表示右线段
};
struct Line L[MAXN<<1];
struct Tree
{
	int y1,y2;//左右端点,对应数组Y[]的下标 
	int len,lenall;//这个结点的长度,以此结点为根的树的总长度
	int num;//本结点被覆盖的次数
	int seg;//以该结点为根的树被覆盖的区间数
	bool lcover,rcover;//左，右端点是否被覆盖
};
struct Tree Tnode[8*MAXN];
int Y[MAXN<<1];
int K,N,W;//有K组不同的y值(离散化)
bool cmp(Line a,Line b)//比较函数，用于排序(按X从小到大)
{
    return a.x<b.x;
}
void Build(int p,int s,int e)
{
	Tnode[p].y1=s;//只是Y[]区间下标
	Tnode[p].y2=e;
	Tnode[p].len=Y[e]-Y[s];
	Tnode[p].lenall=Tnode[p].num=Tnode[p].seg=0;
	Tnode[p].lcover=Tnode[p].rcover=false;
	if(s+1==e)//本题要间隔大于1的区间才有必要再细分
		return;
	int mid=(s+e)>>1;
	Build(lch(p),s,mid);
	Build(rch(p),mid,e);//注意，不是mid+1
}
void Update(int p)//在插入和删除后，更新相关参数
{
	if(Tnode[p].num>0)//被完全覆盖
	{
		Tnode[p].lenall=Tnode[p].len;
		Tnode[p].seg=1;
		Tnode[p].lcover=Tnode[p].rcover=true;
	}
	else if(Tnode[p].y2-Tnode[p].y1>1)//非叶结点
	{
		Tnode[p].lenall=Tnode[lch(p)].lenall+Tnode[rch(p)].lenall;
		Tnode[p].lcover=Tnode[lch(p)].lcover;
		Tnode[p].rcover=Tnode[rch(p)].rcover;
		Tnode[p].seg=Tnode[lch(p)].seg+Tnode[rch(p)].seg-Tnode[lch(p)].rcover*Tnode[rch(p)].lcover;//*注意点
	}
	else//叶结点的处理
	{
		Tnode[p].lenall=Tnode[p].seg=0;
		Tnode[p].lcover=Tnode[p].rcover=false;
	}
}
void Insert(int p,int s,int e,int kind)//kind=1表示插入，kind=-1表示删除
{
	if(Tnode[p].y1==s&&Tnode[p].y2==e)//完全覆盖该区间
	{
		if(kind==1)
			Tnode[p].num++;
		else
			Tnode[p].num--;
	}
	else
	{
		int mid=(Tnode[p].y1+Tnode[p].y2)>>1;
		if(e<=mid) Insert(lch(p),s,e,kind);
		else if(s>=mid) Insert(rch(p),s,e,kind);
		else
		{
			Insert(lch(p),s,mid,kind);
			Insert(rch(p),mid,e,kind);
		}
	}
	Update(p);//每次插入或删除后都要更新以p为根结点的树
}
int Find(int key)////**返回KEY在Y数组的下标
{
	return lower_bound(Y+1,Y+K+1,key)-Y;
}
int main()
{
	int i,x1,y1,x2,y2;
	while(scanf("%d",&N)!=EOF)
	{
		K=1;
		for(i=1;i<=N;i++)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
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
		W=K;//注意这里WA了很多次！！！！
		sort(Y+1,Y+K);//对Y排序(对Y离散化)
		//-----------------------------//
		K=unique(Y+1,Y+K)-(Y+1);//**
		//-----------------------------//
		Build(1,1,K);
		sort(L+1,L+W,cmp);//按x对边排序
		int ans=0,lastlen=0;
		for(i=1;i<W-1;i++)
		{
			Insert(1,Find(L[i].y1),Find(L[i].y2),L[i].side);
			ans+=Tnode[1].seg*2*(L[i+1].x-L[i].x);//更新X轴增加的长度   
			ans+=abs(Tnode[1].lenall-lastlen);//更新y轴增加的长度  
			lastlen=Tnode[1].lenall;
		}
		Insert(1,Find(L[W-1].y1),Find(L[W-1].y2),L[W-1].side);//注意一定要加
		ans+=abs(lastlen-Tnode[1].lenall);
		printf("%d\n",ans); 
	}
return 0;
}
