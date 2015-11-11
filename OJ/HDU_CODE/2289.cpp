////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-29 00:29:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2289
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
/*二分（要注意PI的精度）*/
/*AC代码：31ms*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <cmath>
#define eps 1e-9
#define PI 3.14159265358979323846
//#define PI acos(-1.0)
using namespace std;
double l1,r1,mid;
double r,R,H,V,L;
void Init()
{
    scanf("%lf%lf%lf%lf",&r,&R,&H,&V);
}
double Judge(double h)
{
    double u=h/H*(R-r)+r;
    double res=PI*h*(u*u+r*r+u*r)/3;
    return res;
}
void Solve()
{
    l1=0;r1=H;
    while(r1-l1>eps)
    {
        mid=(l1+r1)/2;
        double res=Judge(mid);
        if(res>V)
            r1=mid;
        else
            l1=mid;
    }
    printf("%.6lf\n",l1);
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
/*
33
50.6 100.9 120 1111111
77.586325
*/