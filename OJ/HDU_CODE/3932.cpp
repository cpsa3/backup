////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2011-08-24 19:47:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3932
////Problem Title: 
////Run result: Accept
////Run time:265MS
////Run memory:264KB
//////////////////System Comment End//////////////////
/*��С����Բ(ģ���˻�)*/
/*AC���룺*/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define RanN 10
#define RunN 30
#define p 0.7
#define INF 1e8
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
int N;
struct px
{
    double x,y,d;
};
struct px stu[1005];
struct px S[RanN+2];
double X,Y;
double get_dis(px t)
{
    double ans=0,temp;
    int i;
    for(i=1;i<=N;i++)
    {
        temp=sqrt((double)((t.x-stu[i].x)*(t.x-stu[i].x)+(t.y-stu[i].y)*(t.y-stu[i].y)));
        ans=max(ans,temp);
    }
    return ans;
}
void get_ans()
{
    int i,r;
    double delta,epsilon=1e-3,k1,k2,Min;
    px temp;
    delta=(double)10000/(sqrt(1.0*N));
    //delta=max(X,Y);
    for(r=1;r<=RanN;r++)
    {
        S[r].x=double(rand()%1000+1)/1000.000*X;
        S[r].y=double(rand()%1000+1)/1000.000*Y;
        S[r].d=get_dis(S[r]);
    }
    while(delta>epsilon)
    {
        for(r=1;r<=RanN;r++)
        {
            for(i=1;i<=RunN;i++)
            {
                k1=double(rand()%1000+1)/1000.000*delta;//������
                k2=sqrt(delta*delta-k1*k1);//k1,k2��ƽ���Ϳ�������delta
                if (rand()%2==1) k1*=-1;//������
                if (rand()%2==1) k2*=-1;
                temp.x=S[r].x+k1;
                temp.y=S[r].y+k2;
                if(temp.x<=X&&temp.x>=0&&temp.y<=Y&&temp.y>=0)//�ڽ��ڲŴ���
                {
                    Min=get_dis(temp);
                    if(Min<S[r].d)//ֱ�Ӹ��¸õ�
                    {S[r].d=Min;S[r].x=temp.x;S[r].y=temp.y;}
                }
            }
        }
        delta*=p;
    }
    Min=INF;
    px ans;
    for(i=1;i<=RanN;i++)
    {
        if(S[i].d<Min)
        {Min=S[i].d;ans=S[i];}
    }
    printf("(%.1lf,%.1lf).\n%.1lf\n",ans.x,ans.y,ans.d);
}
int main()
{
    int i;
    srand(time(0)); 
    while(scanf("%lf%lf%d",&X,&Y,&N)!=EOF)
    {
        for(i=1;i<=N;i++)
            scanf("%lf%lf",&stu[i].x,&stu[i].y);
        get_ans();
    }
    return 0;
}