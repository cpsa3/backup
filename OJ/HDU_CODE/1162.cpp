////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-11-28 21:33:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1162
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:360KB
//////////////////System Comment End//////////////////
/*最小生成树*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <cmath>
#define INF (1<<30)
#define MAXN 105
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;

double map[MAXN][MAXN];
double d[MAXN];
int N;
double X[MAXN],Y[MAXN];
double dis(int a,int b)
{
    double dx=X[a]-X[b];
    double dy=Y[a]-Y[b];
    return sqrt(dx*dx+dy*dy);
}
void Init()
{
    int i,j;
    for(i=1;i<=N;i++)
        scanf("%lf%lf",&X[i],&Y[i]);
    for(i=1;i<=N;i++)
    {
        map[i][i]=0;
        for(j=i+1;j<=N;j++)
        {
            map[i][j]=map[j][i]=dis(i,j);
        }
    }
}
double Prime()
{
    int i,j,u,v;
    for(i=2;i<=N;i++)
        d[i]=map[1][i];
    d[1]=-1;
    double res=0;
    for(i=1;i<N;i++)
    {
        double Min=INF;
        for(j=1;j<=N;j++)
        {
            if(d[j]!=-1&&Min>d[j])
            {
                Min=d[j];
                v=j;
            }
        }
        res+=Min;
        d[v]=-1;
        for(j=1;j<=N;j++)
        {
            if(d[j]!=-1&&map[j][v]<d[j])
                d[j]=map[j][v];
        }
    }
    return res;
}
void Solve()
{
    double ans=Prime();
    printf("%.2lf\n",ans);
}
int main()
{
    while(scanf("%d",&N)!=EOF)
    {
        Init();
        Solve();
    }
    return 0;
}