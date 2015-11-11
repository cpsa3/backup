////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
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
	double x,y1,y2;//��ֱ�߶ε����¶˵�y1,y2��λ��x
	int side;//side=1��ʾ���߶�,side=-1��ʾ���߶�
};
struct Line L[2*MAXN];
struct Tree
{
	double y1,y2,x;
	int cover;//���Ա�ʾ�ӽ��߶����е��߶δ���
	bool flag;//�˱��������ʾ�Ƿ��г�Ԫ�߶Σ�Ϊ�˴��������ȥ��
};
struct Tree Tnode[1000*MAXN];
double Y[2*MAXN];
int K;//��K�鲻ͬ��yֵ(��ɢ��)
bool cmp(Line a,Line b)//�ȽϺ�������������(��X��С����)
{
	return a.x<b.x;
}
void Build(int p,int s,int e)
{
	Tnode[p].x=-1;//-1��ʾ������û���߶�
	Tnode[p].cover=0;
	Tnode[p].y1=Y[s];//ע��
	Tnode[p].y2=Y[e];
	Tnode[p].flag=false;//��ʾ���������·�
	if(s+1==e)
	{
		Tnode[p].flag=true;//��ʾ�ֵ�����
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
	if(Tnode[p].y1>=s&&Tnode[p].y2<=e&&Tnode[p].flag)//ע��һ��Ҫ�ֵ���
	{
		if(Tnode[p].cover>0)//˵�������߶�
		{
			double temp_x=Tnode[p].x;//ע��
			Tnode[p].x=x;//x������
			Tnode[p].cover+=side;//���±ߵ����
			return (Tnode[p].y2-Tnode[p].y1)*(x-temp_x);
		}
		else//���ܹ��ɾ���
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
		for(i=1;i<=t;i++)//��������
		{
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			L[K].x=x1;
			L[K].y1=y1;//С
			L[K].y2=y2;//��
			L[K].side=1;
			Y[K]=y1;
			K++;
			L[K].x=x2;
			L[K].y1=y1;//С
			L[K].y2=y2;//��
			L[K].side=-1;
			Y[K]=y2;
			K++;
		}	
		sort(L+1,L+K,cmp);//��x�Ա�����
		sort(Y+1,Y+K);//��Y����
		Build(1,1,K-1);//����(��ΧΪK)
		double ans=0;//���
		for(i=1;i<K;i++)
			ans+=Insert(1,L[i].x,L[i].y1,L[i].y2,L[i].side);
		printf("Total explored area: %.2lf\n\n",ans);	
	}
return 0;
}
