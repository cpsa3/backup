////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-08-29 23:14:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2298
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
/*Èý½Çº¯Êý¼ÆËã*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cmath>
#define min(a,b) (a<b?a:b)
#define eps 1e-8
#define PI acos(-1.0)
using namespace std;
double x,y,v;
int main()
{
    int T;
    //printf("%lf\n",PI);
    double a,b,c1,c2;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf%lf",&x,&y,&v);
        a=(9.8*x*x+v*v*y)/(v*v*sqrt(x*x+y*y));
        b=acos(x/sqrt(x*x+y*y));
        if(a>1||a<-1)
        {printf("-1\n");continue;}
        //printf("%.6lf\n",a);
        a=asin(a);
        //printf("%.8lf %.8lf\n",a,b);
        c1=(a+b)/2;
        c2=(PI-a+b)/2;
        if((c1<eps||c1>PI/2)&&(c2<eps||c2>PI/2))
            printf("-1\n");
        else
        {
            if((c1<eps||c1>PI/2))
                printf("%.6lf\n",c2);
            else if((c2<eps||c2>PI/2))
                printf("%.6lf\n",c1);
            else
                printf("%.6lf\n",min(c1,c2));
        }
    }
return 0;
}