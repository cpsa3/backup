////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-09-15 09:39:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3420
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#define max(a,b) (a>b?a:b)
using namespace std;
int num[1005];
int N;
void Init()
{
    int i;
    for(i=1;i<=N;i++)
        scanf("%d",&num[i]);
}
void Solve()
{
    int i,ans=-1;
    if(N==0) {printf("0\n");return;}
    sort(num+1,num+1+N);
    int t;
    for(i=1;i<=N;i++)
    {
        t=num[i]*(N-i+1);
        ans=max(ans,t);
    }
    printf("%d\n",ans);
}
int main()
{
    while(scanf("%d",&N)!=EOF)
    {
        Init();
        Solve();
    }
return 0;
}