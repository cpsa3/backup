////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-28 23:45:46
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1969
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:320KB
//////////////////System Comment End//////////////////
/*二分（要注意PI的精度）*/
/*AC代码：31ms*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <cmath>
#define MAXN 10005
#define eps 1e-7
#define PI 3.14159265358979323846
using namespace std;
double l,r,mid,y;
int N,F;
double Area[MAXN];
void Init()
{
    int i;
    double t;
    scanf("%d%d",&N,&F);
    F++;
    r=0;
    for(i=1;i<=N;i++)
    {
        scanf("%lf",&t);
        Area[i]=PI*t*t;
        r+=Area[i];
    }
}
bool Judge(double mid)
{
    int i,num=0;
    for(i=1;i<=N;i++)
        num+=(int)(Area[i]/mid);
    return num>=F;
}
void Solve()
{
    l=0;r=r/F;
    while(fabs(r-l)>eps)
    {
        mid=(l+r)/2;
        if(Judge(mid))
            l=mid;
        else
            r=mid;
    }
    printf("%.4lf\n",r);
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