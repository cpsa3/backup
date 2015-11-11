////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-11-30 11:36:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1875
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:356KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <cstdio>
#include <cmath>
#define MAXN 105
#define INF (1<<30)
using namespace std;

int N;
double X[MAXN],Y[MAXN];
double d[MAXN][MAXN];
double p[MAXN];
double D(int a,int b)
{
    double dx=X[a]-X[b];
    double dy=Y[a]-Y[b];
    return sqrt(dx*dx+dy*dy);
}
void Init()
{
    int i,j;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
        scanf("%lf%lf",&X[i],&Y[i]);
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
            d[i][j]=INF;
        d[i][i]=0;
    }
    for(i=1;i<=N;i++)
    {
        for(j=i+1;j<=N;j++)
        {
            double dis=D(i,j);
            if(dis>=10&&dis<=1000)
                d[i][j]=d[j][i]=100*dis;
        }
    }
}
double Prime()
{
    int i,j,v;
    for(i=2;i<=N;i++)
        p[i]=d[1][i];
    p[1]=-1;
    double ans=0;
    for(i=1;i<N;i++)
    {
        double Min=INF;
        for(j=1;j<=N;j++)
        {
            if(p[j]!=-1&&Min>p[j])
            {
                Min=p[j];
                v=j;
            }
        }
        if(Min==INF) return -1;
        ans+=Min;
        p[v]=-1;
        for(j=1;j<=N;j++)
        {
            if(p[j]!=-1&&d[v][j]<p[j])
                p[j]=d[v][j];
        }
    }
    return ans;    
}
void Solve()
{
    double ans=Prime();
    if(ans==-1)
        printf("oh!\n");
    else     
        printf("%.1lf\n",ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        Init();
        Solve();
    }
    return 0;
}