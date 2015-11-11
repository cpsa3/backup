////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-09-12 20:14:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4033
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*¶þ·Ö */
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cmath>
#define MAXN 105
#define INF 2e8
#define eps 1e-8
//#define PI 3.14159265358979323846
#define PI acos(-1.0)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
int N,cas;
double D[MAXN],Max,Min;

double deg(double a,double b,double c)
{
    double p=(a+b+c)/2.0;
    double s= sqrt(p*(p-a)*(p-b)*(p-c));
    
    //printf("%.3lf %.3lf %.3lf %.3lf\n",s,a,b,c);
    double res=((s*2/a)*1.0/b);
    res=asin(res);
    
    if(a*a+b*b<=c*c+eps)
        res=PI-res;
    
    //printf("*%.3lf\n",res);
    return res;
}
void Init()
{
    int i;
    scanf("%d\n",&N);
    for(i=1;i<=N;i++)
        scanf("%lf",&D[i]);
    Max=INF;Min=-1;
    
    for(i=1;i<N;i++)
    {
        Max=min(Max,D[i]+D[i+1]);
        Min=max(Min,fabs(D[i]-D[i+1]));
    }
    Max=min(Max,D[N]+D[1]);
    Min=max(Min,fabs(D[N]-D[1]));
}

int Judge(double mid)
{
    int i;
    double res=0;
    
    for(i=1;i<N;i++)
    {
        res+=deg(D[i],D[i+1],mid);
    }
    res+=deg(D[N],D[1],mid);
    
    //printf("%.3lf\n",res);
    
    if(fabs(res-2*PI)<eps) return 0;
    if(res>2*PI) return 1;
    return -1;
}

void Solve()
{
    printf("Case %d: ",cas++);
    //printf("%.3lf %.3lf %.3lf\n",PI,Min,Max);
    double l,r,mid;
    l=Min+eps;r=Max-eps;
    //l=5;r=6.9;
    bool ok=false;
    if(l>=r+eps)
    {
        printf("impossible\n");
        return;
    }
    //Judge(6.766);
    while(fabs(r-l)>eps)
    {
        mid=(l+r)/2;
        int k=Judge(mid);
        if(k==1)
            r=mid;
        else if(k==-1)
            l=mid;
        else
        {
            ok=true;
            break;
        }
    }

    if(ok) printf("%.3lf\n",mid);
    else printf("impossible\n");
}
int main()
{
    int T;
    cas=1;
    scanf("%d",&T);
    while(T--)
    {
        Init();
        Solve();
    }
return 0;
}