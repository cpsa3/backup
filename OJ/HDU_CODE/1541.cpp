////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2010-11-28 22:53:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1541
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:1136KB
//////////////////System Comment End//////////////////
#include <iostream>
#define lch(a) (2*(a))
#define rch(a) (2*(a)+1)
#define MAXN 32005
struct px
{
	int s,e,v;
};
struct px Tnode[3*MAXN];
int level[MAXN],N;
void Build(int p,int s,int e)//����
{
	int mid=(s+e)>>1;
	Tnode[p].s=s;
	Tnode[p].e=e;
	Tnode[p].v=0;//��ʼ��
	if(s==e)
		return;
	Build(lch(p),s,mid);
	Build(rch(p),mid+1,e);
}
void Insert(int p,int k)//����
{
	Tnode[p].v++;
	if(Tnode[p].s==Tnode[p].e)//�ҵ���
		return;
	int mid=(Tnode[p].s+Tnode[p].e)>>1;
	if(k>=Tnode[p].s&&k<=mid) Insert(lch(p),k);
	else Insert(rch(p),k);
}
int Find(int p,int s,int e)//����
{
	int mid=(Tnode[p].s+Tnode[p].e)>>1;
	if(Tnode[p].s==s&&Tnode[p].e==e)
		return Tnode[p].v;
	if(e<=mid)
		return Find(lch(p),s,e);
	else if(s>mid)
		return Find(rch(p),s,e);
	else return Find(lch(p),s,mid)+Find(rch(p),mid+1,e);
}
int main ()
{
	int i,x,y;
	while(scanf("%d",&N)!=EOF)
	{
		memset(level,0,sizeof(level));//��ʼ��
		Build(1,1,MAXN);//������һ��Ҫ����MAXN
		for(i=1;i<=N;i++)
		{
			scanf("%d%d",&x,&y);
			x++;//��Ϊx�Ǵ�1��ʼ���
			level[Find(1,1,x)]++;
			Insert(1,x);
		}
		for(i=0;i<N;i++)//��Ϊy�Ǵ�1��ʼ���
			printf("%d\n",level[i]);
	}
	return 0;
}