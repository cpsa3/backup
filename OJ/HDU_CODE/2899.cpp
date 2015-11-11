////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-08-28 22:15:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2899
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
/*Èý·Ö*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <cmath>
#define eps 1e-6
using namespace std;
double l,r,mid,y;
double fuck(double x)
{
    double res=0;
    res=6*pow(x,7)+8*pow(x,6)+7*pow(x,3)+5*x*x-y*x;
    return res;
}
int main()
{
    int T;
    double ml,mr,t1,t2;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf",&y);
        l=0;r=100;
        while(fabs(l-r)>eps)
        {
            ml=l+(r-l)/3;
            mr=r-(r-l)/3;
            t1=fuck(ml);
            t2=fuck(mr);
            if(t1<t2)
                r=mr;
            else
                l=ml;
        }
        double ans=fuck(l);
        printf("%.4lf\n",ans);
    }
return 0;
}