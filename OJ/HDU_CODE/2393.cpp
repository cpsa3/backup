////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2012-03-12 14:04:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2393
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

double a[3];
int main()
{
    int i;
    int cas=1;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf%lf",&a[0],&a[1],&a[2]);
        
        printf("Scenario #%d:\n",cas++);
        sort(a,a+3);
        if(a[0]*a[0]+a[1]*a[1]==a[2]*a[2])
            printf("yes\n");
        else
            printf("no\n");
        printf("\n");
    }
return 0;
}