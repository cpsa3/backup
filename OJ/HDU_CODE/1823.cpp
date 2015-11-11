////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-05-03 13:31:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1823
////Problem Title: 
////Run result: Accept
////Run time:203MS
////Run memory:6812KB
//////////////////System Comment End//////////////////
/*AC代码：203ms*/
/*二维线段树一维的结构体加个结构体*/
/*就像先粗查，再细查*/
#include <iostream>
#define lch(a) (2*(a))
#define rch(a) (2*(a)+1)
#define max(x,y) (x>y?x:y)
#define SubmaxN 1005
#define MainmaxN 105
void douswap(double &a,double &b)//要写取地址符
{
	double t;
	t=a;a=b;b=t; 
}
void intswap(int &a,int &b)
{
	int t;
	t=a;a=b;b=t; 
}  

//------------(1).树的定义----------------// 
struct SubTree//活泼，二维
{
	int Al,Ar;
	int Lv;//LoveValue缘分
};
struct MainTree//身高(里面包含活泼的结构体)，一维
{
	int Hl,Hr;
	SubTree A[3*SubmaxN];//活泼值
};
MainTree Tnode[3*MainmaxN];//主树
//------------------------------------// 

//------------(2).树的构建----------------// 
void SubBuild(int Mp,int Sp,int Subl,int Subr)//二维树的构建
{
	Tnode[Mp].A[Sp].Al=Subl;
	Tnode[Mp].A[Sp].Ar=Subr;
	Tnode[Mp].A[Sp].Lv=-1;//初始化为-1
	if(Subl==Subr)
		return;
	int Submid=(Subl+Subr)>>1;
	SubBuild(Mp,lch(Sp),Subl,Submid);
	SubBuild(Mp,rch(Sp),Submid+1,Subr);
}
void MainBuild(int Mp,int Mainl,int Mainr)//一维树的构建
{
	SubBuild(Mp,1,0,1000);//*一维的每一段都对应一整段二维的
	Tnode[Mp].Hl=Mainl;
	Tnode[Mp].Hr=Mainr;
	if(Mainl==Mainr)
		return;
	int Mainmid=(Mainl+Mainr)>>1;
	MainBuild(lch(Mp),Mainl,Mainmid);
	MainBuild(rch(Mp),Mainmid+1,Mainr);
}
//------------------------------------// 

//------------(3).树的更新----------------// 
void SubUpdate(int Mp,int Sp,int Act,int Love)//二维树的更新
{
	if(Sp>3*SubmaxN)
		return;
	Tnode[Mp].A[Sp].Lv=max(Tnode[Mp].A[Sp].Lv,Love);
	if(Tnode[Mp].A[Sp].Al==Act&&Tnode[Mp].A[Sp].Ar==Act)//找到最终的结点了
		return;
	int Submid=(Tnode[Mp].A[Sp].Al+Tnode[Mp].A[Sp].Ar)>>1;
	if(Act<=Submid)
		SubUpdate(Mp,lch(Sp),Act,Love);
	else
		SubUpdate(Mp,rch(Sp),Act,Love);
}
void MainUpdate(int Mp,int H,int Act,int Love)//一维树的更新
{
	if(Mp>3*MainmaxN)//一定要加，不然会死循环
		return;
	SubUpdate(Mp,1,Act,Love);//*更新这棵一维树下的二维树
	int Mainmid=(Tnode[Mp].Hl+Tnode[Mp].Hr)>>1;
	if(H<=Mainmid)
		MainUpdate(lch(Mp),H,Act,Love);
	else
		MainUpdate(rch(Mp),H,Act,Love);
}
//------------------------------------// 

//------------(4).树的查找----------------// 
/*就像先粗查，再细查*/
int SubFind(int Mp,int Sp,int Al,int Ar)//二维树的查找
{
	if(Sp>3*SubmaxN)
		return -1;
	if(Tnode[Mp].A[Sp].Al==Al&&Tnode[Mp].A[Sp].Ar==Ar)
		return Tnode[Mp].A[Sp].Lv;
	int Submid=(Tnode[Mp].A[Sp].Al+Tnode[Mp].A[Sp].Ar)>>1;
	if(Ar<=Submid)
		return SubFind(Mp,lch(Sp),Al,Ar);
	else if(Al>Submid)
		return SubFind(Mp,rch(Sp),Al,Ar);
	return max(SubFind(Mp,lch(Sp),Al,Submid),SubFind(Mp,rch(Sp),Submid+1,Ar)); 
}
int MainFind(int Mp,int Hl,int Hr,int Al,int Ar)//一维树的查找
{
	if(Mp>3*MainmaxN)
		return -1;
	if(Tnode[Mp].Hl==Hl&&Tnode[Mp].Hr==Hr)//高度的范围找到
		return SubFind(Mp,1,Al,Ar);//去找活泼度
	int Mainmid=(Tnode[Mp].Hl+Tnode[Mp].Hr)>>1;
	if(Hr<=Mainmid)
		return MainFind(lch(Mp),Hl,Hr,Al,Ar);
	else if(Hl>Mainmid)
		return MainFind(rch(Mp),Hl,Hr,Al,Ar);
	return max(MainFind(lch(Mp),Hl,Mainmid,Al,Ar),MainFind(rch(Mp),Mainmid+1,Hr,Al,Ar)); 
}
//------------------------------------// 

int main()
{
	int M,i;
	char s[2];
	double A1,A2,A,L;
	int IntA,IntL,H,H1,H2,IntA1,IntA2,temp; 
	while(scanf("%d",&M)!=EOF)
	{
		if(M==0)
			break;
		MainBuild(1,100,200);
		for(i=1;i<=M;i++)
		{
			scanf("%s",s);
			if(s[0]=='I')
			{
				scanf("%d%lf%lf",&H,&A,&L);
				IntA=(int)(A*10);
				IntL=(int)(L*10);
				MainUpdate(1,H,IntA,IntL);
			}
			else
			{
				scanf("%d%d%lf%lf",&H1,&H2,&A1,&A2);
				if(H2<H1)
					intswap(H1,H2);
				if(A2<A1)
					douswap(A1,A2);
				IntA1=(int)(10*A1);
				IntA2=(int)(10*A2);
				temp=MainFind(1,H1,H2,IntA1,IntA2);
				double ans=temp/10.0;
				if(ans<0)
					printf("-1\n");
				else
					printf("%.1lf\n",ans);
			}
		}
	}
return 0;
}
