////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-09-08 10:20:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4015
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:216KB
//////////////////System Comment End//////////////////
/*HDU_4015 Mario and Mushrooms*/
/*ÍÆ¹«Ê½*/
#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;
double m,k;
int cas;
int main()
{

    int T;
    cas=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf",&m,&k);
        double ans=1.0/((m+1)*k+1);
        printf("Case #%d: %.8lf\n",cas++,ans);
    }
    return 0;
}