////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-08-28 22:25:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2199
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
/*¶þ·Ö*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <cmath>
#define eps 1e-7
using namespace std;
double l,r,mid,y;
double fuck(double x)
{
    double res=0;
    res=8*pow(x,4)+7*pow(x,3)+2*x*x+3*x+6-y;
    return res;
}
int main()
{
    int T;
    double t1,t2;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf",&y);
        l=0;r=100;
        t1=fuck(l);
        t2=fuck(r);
        if(t1>eps||t2<eps)
        {printf("No solution!\n");continue;}
        while(fabs(r-l)>eps)
        {
            mid=(l+r)/2;
            if(fuck(mid)>eps)
                r=mid;
            else
                l=mid;
        }
        printf("%.4lf\n",r);
    }
return 0;
}