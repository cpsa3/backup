////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-09-02 18:19:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3993
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
int A[20],B[20];
int N;
void Init()
{
    int i;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
        scanf("%d",&A[i]);
    for(i=1;i<=N;i++)
        scanf("%d",&B[i]);
}
void Solve()
{
    double ans=0;
    int i,j;
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
        {
            if(B[j]>A[i]) ans+=3;
        }
    }
    printf("%.6lf\n",ans/N);
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