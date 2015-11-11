////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
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
/*AC���룺2062ms*/
#include <iostream>
#include <algorithm>
using namespace std;
#define lch(a) (2*(a))
#define rch(a) (2*(a)+1)
#define MAXN 30
struct Line
{
    int x,y1,y2;//��ֱ�߶ε����¶˵�y1,y2��λ��x
    int side;//side=1��ʾ���߶�,side=-1��ʾ���߶�
};
struct Line L[2*MAXN],JY[2*MAXN];
struct Tree
{
    int y1,y2,x;
    int cover;//���Ա�ʾ�ӽ��߶����е��߶δ���
    bool flag;//�˱��������ʾ�Ƿ��г�Ԫ�߶Σ�Ϊ�˴��������ȥ��
};
struct Tree Tnode[8*MAXN];
int Y[2*MAXN];
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
int Insert(int p,int x,int s,int e,int side)
{
    if(e<=Tnode[p].y1||s>=Tnode[p].y2)
        return 0;
    if(Tnode[p].y1>=s&&Tnode[p].y2<=e&&Tnode[p].flag)//ע��һ��Ҫ�ֵ���
    {
        if(Tnode[p].cover>0)//˵�������߶�
        {
            int temp_x=Tnode[p].x;//ע��
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
        for(i=1;i<=N;i++)//��������
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            JY[K].x=L[K].x=x1;
            JY[K].y1=L[K].y1=y1;//С
            JY[K].y2=L[K].y2=y2;//��
            JY[K].side=L[K].side=1;
            Y[K]=y1;
            K++;
            JY[K].x=L[K].x=x2;
            JY[K].y1=L[K].y1=y1;//С
            JY[K].y2=L[K].y2=y2;//��
            JY[K].side=L[K].side=-1;
            Y[K]=y2;
            K++;
        }    
        //sort(L+1,L+K,cmp);//��x�Ա�����
        sort(Y+1,Y+K);//��Y����
        int ans=0;//���
        for(i=1;i<=M;i++)
		{
			ans=0;
			Build(1,1,K-1);//����(��ΧΪK)
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