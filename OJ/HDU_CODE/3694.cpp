////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2011-09-16 17:08:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3694
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:224KB
//////////////////System Comment End//////////////////
/*HDU_3694 Fermat Point in Quadrangle*/
/*�ĸ���ķ����*/
/*
ע�⣺
(1):��ģ���˻�ᳬʱ��

�ⷨ��
(1):����ı�����͹�ı��Σ���ô�����Ϊ�Խ��ߵĽ���
(2):����ı����ǰ��ı��Σ���ô�����������һ������
*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cmath>
#define MAXN 10
#define eps 1e-5
#define INF (1<<30)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;

/*==================================================*\
| Graham ��͹�� O(N * logN)
| CALL: nr = graham(pnt, int n, res); res[]Ϊ͹���㼯;
\*==================================================*/
//----------------------͹��ģ��-------------------------//
struct point {double x,y;};
struct point pnt[MAXN],res[MAXN],center;
int N,M;
double mult(point sp,point ep,point op)//���
{
	return (sp.x-op.x)*(ep.y-op.y)-(ep.x-op.x)*(sp.y-op.y);
}
bool operator<(const point &l,const point &r)
{
	return l.y<r.y||(l.y==r.y&&l.x<r.x);
}
int graham(point pnt[],int n,point res[])//ע�ⶼ�Ǵ�0��ʼ��,res�ڵĵ��������ʱ���ź����
{
	int i,len,k=0,top=1;
	sort(pnt,pnt+n);
	if (n == 0) return 0; res[0]=pnt[0];
	if (n == 1) return 1; res[1]=pnt[1];
	if (n == 2) return 2; res[2]=pnt[2];
	for(i=2;i<n;i++)
	{
		while(top&&(mult(pnt[i],res[top],res[top-1])+eps>=0))
			top--;
		res[++top]=pnt[i];
	}
	len=top;res[++top]=pnt[n-2];
	for(i=n-3;i>=0;i--)
	{
		while(top!=len&&(mult(pnt[i],res[top],res[top-1])+eps>=0))
			top--;
		res[++top]=pnt[i];
	}
	return top;       // ����͹���е�ĸ���
}
//----------------------͹��ģ��-------------------------//

double dis1(int a,int b)
{
    double dx=(res[a].x-res[b].x);
    double dy=(res[a].y-res[b].y);
    return sqrt(dx*dx+dy*dy);
}
double dis2(int a,int b)
{
    double dx=(pnt[a].x-pnt[b].x);
    double dy=(pnt[a].y-pnt[b].y);
    return sqrt(dx*dx+dy*dy);
}
void Solve()
{
    double ans=0;
    int m=graham(pnt,4,res);
    if(m==4)  //͹�ı���
        ans=dis1(0,2)+dis1(1,3);
    else      //���ı���
    {
        ans=INF;
        ans=min(ans,dis2(0,1)+dis2(0,2)+dis2(0,3));
        ans=min(ans,dis2(1,0)+dis2(1,2)+dis2(1,3));
        ans=min(ans,dis2(2,0)+dis2(2,1)+dis2(2,3));
        ans=min(ans,dis2(3,0)+dis2(3,1)+dis2(3,2));
    }
    printf("%.4lf\n",ans);
}

int main()
{
    int i;
    while(scanf("%lf%lf",&pnt[0].x,&pnt[0].y)!=EOF)
    {
        for(i=1;i<4;i++)
            scanf("%lf%lf",&pnt[i].x,&pnt[i].y);
        bool ok=true;
        for(i=0;i<4;i++)
        {
            if(pnt[i].x!=-1||pnt[i].y!=-1)
            {ok=false;break;}
        }
        if(ok){break;}
        Solve();
        //system("pause");
    }
return 0;
}