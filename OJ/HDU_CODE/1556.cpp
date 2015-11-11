////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-11-25 13:40:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1556
////Problem Title: 
////Run result: Accept
////Run time:703MS
////Run memory:4356KB
//////////////////System Comment End//////////////////
#include <iostream>
#define lch(a) (2*(a))
#define rch(a) (2*(a)+1)
#define M 100005
struct px
{
	int st;
	int ed;
	int value;
	bool mark;
};
struct px Tnode[5*M];
int N;
void init(int p,int st,int ed)//建树
{
	int mid=(st+ed)>>1;
	Tnode[p].st=st;
	Tnode[p].ed=ed;
	Tnode[p].value=0;
	Tnode[p].mark=false;
	if(st!=ed)
	{
		init(lch(p),st,mid);
		init(rch(p),mid+1,ed);//注意要加一
	}
}
void Insert(int p,int a,int b)//插入
{
	int mid=(Tnode[p].st+Tnode[p].ed)>>1;
	if(a==Tnode[p].st&&b==Tnode[p].ed)
	{
		Tnode[p].value++;
		Tnode[p].mark=true;
		return;//已经找到了，就返回
	}
	if(Tnode[p].mark)//没找到之前，先分下去
	{
		Tnode[lch(p)].mark=Tnode[rch(p)].mark=true;
		Tnode[lch(p)].value+=Tnode[p].value;
		Tnode[rch(p)].value+=Tnode[p].value;
		Tnode[p].value=0;
		Tnode[p].mark=false;
	}
	if(b<=mid)//继续往下找
		Insert(lch(p),a,b);
	else if(a>=mid+1)
		Insert(rch(p),a,b);
	else
	{
		Insert(lch(p),a,mid);
		Insert(rch(p),mid+1,b);
	}
}
int Find(int p,int a,int b)//查找
{
	if(Tnode[p].ed==Tnode[p].st) return Tnode[p].value;
	if(Tnode[p].mark)
	{
		Tnode[lch(p)].mark=Tnode[rch(p)].mark=true;
		Tnode[lch(p)].value+=Tnode[p].value;
		Tnode[rch(p)].value+=Tnode[p].value;
		Tnode[p].value=0;
		Tnode[p].mark=false;		
	}
	
	int mid=(Tnode[p].st+Tnode[p].ed)>>1;
	//if(b<=mid) return Find(lch(p),a,b);
	//else return Find(rch(p),a,b);
	if(a>mid) return Find(rch(p),a,b);
	else return Find(lch(p),a,b);
	
}
int main ()
{
	int i,a,b;
	while(scanf("%d",&N)!=EOF)
	{
		if(N==0)
			break;
		init(1,1,N);
		for(i=1;i<=N;i++)
		{
			scanf("%d%d",&a,&b);
			Insert(1,a,b);
		}
		for(i=1;i<N;i++)
			printf("%d ",Find(1,i,i));
		printf("%d\n",Find(1,N,N));
	}
	return 0;
}
