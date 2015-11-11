////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
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
/*AC���룺203ms*/
/*��ά�߶���һά�Ľṹ��Ӹ��ṹ��*/
/*�����ȴֲ飬��ϸ��*/
#include <iostream>
#define lch(a) (2*(a))
#define rch(a) (2*(a)+1)
#define max(x,y) (x>y?x:y)
#define SubmaxN 1005
#define MainmaxN 105
void douswap(double &a,double &b)//Ҫдȡ��ַ��
{
	double t;
	t=a;a=b;b=t; 
}
void intswap(int &a,int &b)
{
	int t;
	t=a;a=b;b=t; 
}  

//------------(1).���Ķ���----------------// 
struct SubTree//���ã���ά
{
	int Al,Ar;
	int Lv;//LoveValueԵ��
};
struct MainTree//���(����������õĽṹ��)��һά
{
	int Hl,Hr;
	SubTree A[3*SubmaxN];//����ֵ
};
MainTree Tnode[3*MainmaxN];//����
//------------------------------------// 

//------------(2).���Ĺ���----------------// 
void SubBuild(int Mp,int Sp,int Subl,int Subr)//��ά���Ĺ���
{
	Tnode[Mp].A[Sp].Al=Subl;
	Tnode[Mp].A[Sp].Ar=Subr;
	Tnode[Mp].A[Sp].Lv=-1;//��ʼ��Ϊ-1
	if(Subl==Subr)
		return;
	int Submid=(Subl+Subr)>>1;
	SubBuild(Mp,lch(Sp),Subl,Submid);
	SubBuild(Mp,rch(Sp),Submid+1,Subr);
}
void MainBuild(int Mp,int Mainl,int Mainr)//һά���Ĺ���
{
	SubBuild(Mp,1,0,1000);//*һά��ÿһ�ζ���Ӧһ���ζ�ά��
	Tnode[Mp].Hl=Mainl;
	Tnode[Mp].Hr=Mainr;
	if(Mainl==Mainr)
		return;
	int Mainmid=(Mainl+Mainr)>>1;
	MainBuild(lch(Mp),Mainl,Mainmid);
	MainBuild(rch(Mp),Mainmid+1,Mainr);
}
//------------------------------------// 

//------------(3).���ĸ���----------------// 
void SubUpdate(int Mp,int Sp,int Act,int Love)//��ά���ĸ���
{
	if(Sp>3*SubmaxN)
		return;
	Tnode[Mp].A[Sp].Lv=max(Tnode[Mp].A[Sp].Lv,Love);
	if(Tnode[Mp].A[Sp].Al==Act&&Tnode[Mp].A[Sp].Ar==Act)//�ҵ����յĽ����
		return;
	int Submid=(Tnode[Mp].A[Sp].Al+Tnode[Mp].A[Sp].Ar)>>1;
	if(Act<=Submid)
		SubUpdate(Mp,lch(Sp),Act,Love);
	else
		SubUpdate(Mp,rch(Sp),Act,Love);
}
void MainUpdate(int Mp,int H,int Act,int Love)//һά���ĸ���
{
	if(Mp>3*MainmaxN)//һ��Ҫ�ӣ���Ȼ����ѭ��
		return;
	SubUpdate(Mp,1,Act,Love);//*�������һά���µĶ�ά��
	int Mainmid=(Tnode[Mp].Hl+Tnode[Mp].Hr)>>1;
	if(H<=Mainmid)
		MainUpdate(lch(Mp),H,Act,Love);
	else
		MainUpdate(rch(Mp),H,Act,Love);
}
//------------------------------------// 

//------------(4).���Ĳ���----------------// 
/*�����ȴֲ飬��ϸ��*/
int SubFind(int Mp,int Sp,int Al,int Ar)//��ά���Ĳ���
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
int MainFind(int Mp,int Hl,int Hr,int Al,int Ar)//һά���Ĳ���
{
	if(Mp>3*MainmaxN)
		return -1;
	if(Tnode[Mp].Hl==Hl&&Tnode[Mp].Hr==Hr)//�߶ȵķ�Χ�ҵ�
		return SubFind(Mp,1,Al,Ar);//ȥ�һ��ö�
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
