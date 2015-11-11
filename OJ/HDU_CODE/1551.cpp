////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-08-29 17:12:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1551
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:320KB
//////////////////System Comment End//////////////////
/*¶þ·Ö*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cmath>
#define eps 1e-5
#define MAXN 10005
using namespace std;
int N,K;
double W[MAXN],sum;
void Init()
{
    int i;
    sum=0;
    for(i=1;i<=N;i++)
    {
        scanf("%lf",&W[i]);
        sum+=W[i];
    }
}
bool Judge(double mid)
{
    int i,res=0;
    for(i=1;i<=N;i++)
        res+=(int)(W[i]/mid);
    return res>=K;
}
void Solve()
{
    double l,r,mid;
    l=0;r=sum/K+eps;
    while(fabs(r-l)>=eps)
    {
        mid=(l+r)/2;
        if(Judge(mid))
            l=mid;
        else
            r=mid;
    }
    //if(!Judge(l)) l=0;
    printf("%.2lf\n",l);
}
int main()
{
    while(scanf("%d%d",&N,&K)!=EOF)
    {
        if(N==0&&K==0) break;
        Init();
        Solve();
    }
return 0;
}