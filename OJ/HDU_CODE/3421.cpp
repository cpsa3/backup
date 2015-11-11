////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-09-15 09:40:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3421
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:4120KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 1000006
#define max(a,b) (a>b?a:b)
using namespace std;
int num[MAXN];
int N,cas;
void Init()
{
    int i;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
        scanf("%d",&num[i]);
}
void Solve()
{
    int i,n,ans,Max;
    n=ans=0;
    bool ok=false;
    Max=-2000;
    for(i=1;i<=N;i++)
    {
        Max=max(Max,num[i]);
        if(num[i]>0)
        {
            ans+=num[i];
            ok=true;
            continue;
        }
        if(num[i]==0) continue;
        if(ok)
        {
            ok=false;
            n++;
        }
    }
    if(ok) n++;
    /*
    if(n==0)
    {
        n++;
        ans=Max;
    }
    */
    printf("Case %d:\n",cas++);
    printf("%d %d\n",n,ans);
}
int main()
{
    int T;
    cas=1;
    bool flag=false;
    scanf("%d",&T);
    while(T--)
    {
        if(flag) printf("\n");
        Init();
        Solve();
        flag=true;
    }
return 0;
}