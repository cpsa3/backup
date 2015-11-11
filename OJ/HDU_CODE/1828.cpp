////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
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
/*AC���룺16ms*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define lch(a) (2*(a))
#define rch(a) (2*(a)+1)
#define MAXN 5005
struct Line
{
	int x,y1,y2;//��ֱ�߶ε����¶˵�y1,y2��λ��x
	int side;//side=1��ʾ���߶�,side=-1��ʾ���߶�
};
struct Line L[MAXN<<1];
struct Tree
{
	int y1,y2;//���Ҷ˵�,��Ӧ����Y[]���±� 
	int len,lenall;//������ĳ���,�Դ˽��Ϊ���������ܳ���
	int num;//����㱻���ǵĴ���
	int seg;//�Ըý��Ϊ�����������ǵ�������
	bool lcover,rcover;//���Ҷ˵��Ƿ񱻸���
};
struct Tree Tnode[8*MAXN];
int Y[MAXN<<1];
int K,N,W;//��K�鲻ͬ��yֵ(��ɢ��)
bool cmp(Line a,Line b)//�ȽϺ�������������(��X��С����)
{
    return a.x<b.x;
}
void Build(int p,int s,int e)
{
	Tnode[p].y1=s;//ֻ��Y[]�����±�
	Tnode[p].y2=e;
	Tnode[p].len=Y[e]-Y[s];
	Tnode[p].lenall=Tnode[p].num=Tnode[p].seg=0;
	Tnode[p].lcover=Tnode[p].rcover=false;
	if(s+1==e)//����Ҫ�������1��������б�Ҫ��ϸ��
		return;
	int mid=(s+e)>>1;
	Build(lch(p),s,mid);
	Build(rch(p),mid,e);//ע�⣬����mid+1
}
void Update(int p)//�ڲ����ɾ���󣬸�����ز���
{
	if(Tnode[p].num>0)//����ȫ����
	{
		Tnode[p].lenall=Tnode[p].len;
		Tnode[p].seg=1;
		Tnode[p].lcover=Tnode[p].rcover=true;
	}
	else if(Tnode[p].y2-Tnode[p].y1>1)//��Ҷ���
	{
		Tnode[p].lenall=Tnode[lch(p)].lenall+Tnode[rch(p)].lenall;
		Tnode[p].lcover=Tnode[lch(p)].lcover;
		Tnode[p].rcover=Tnode[rch(p)].rcover;
		Tnode[p].seg=Tnode[lch(p)].seg+Tnode[rch(p)].seg-Tnode[lch(p)].rcover*Tnode[rch(p)].lcover;//*ע���
	}
	else//Ҷ���Ĵ���
	{
		Tnode[p].lenall=Tnode[p].seg=0;
		Tnode[p].lcover=Tnode[p].rcover=false;
	}
}
void Insert(int p,int s,int e,int kind)//kind=1��ʾ���룬kind=-1��ʾɾ��
{
	if(Tnode[p].y1==s&&Tnode[p].y2==e)//��ȫ���Ǹ�����
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
	Update(p);//ÿ�β����ɾ����Ҫ������pΪ��������
}
int Find(int key)////**����KEY��Y������±�
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
		W=K;//ע������WA�˺ܶ�Σ�������
		sort(Y+1,Y+K);//��Y����(��Y��ɢ��)
		//-----------------------------//
		K=unique(Y+1,Y+K)-(Y+1);//**
		//-----------------------------//
		Build(1,1,K);
		sort(L+1,L+W,cmp);//��x�Ա�����
		int ans=0,lastlen=0;
		for(i=1;i<W-1;i++)
		{
			Insert(1,Find(L[i].y1),Find(L[i].y2),L[i].side);
			ans+=Tnode[1].seg*2*(L[i+1].x-L[i].x);//����X�����ӵĳ���   
			ans+=abs(Tnode[1].lenall-lastlen);//����y�����ӵĳ���  
			lastlen=Tnode[1].lenall;
		}
		Insert(1,Find(L[W-1].y1),Find(L[W-1].y2),L[W-1].side);//ע��һ��Ҫ��
		ans+=abs(lastlen-Tnode[1].lenall);
		printf("%d\n",ans); 
	}
return 0;
}
