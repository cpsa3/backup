////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-09-16 13:58:23
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1271
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
/*HDU_1271 整数对*/
/*枚举*/
/*注意： 12的情况*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cmath>
#define STOP system("pause")
using namespace std;
int N;
int ans[30],cnt;
void Solve()
{
    int i,n,a,b,c,t,k;
    bool ok=false;
    cnt=0;
    for(k=1;k<=N;k*=10)
    {
        t=N/k;
        b=t%11;
        c=t/11;
        //1;
        if((b!=0||c!=0)&&b<10)
        {
            a=(N-k*b-k*11*c)>>1;
            if(2*a+k*b+k*11*c==N) ans[cnt++]=a+b*k+10*k*c;
        }
        //2;
        b--;
        if((b!=0||c!=0)&&b>=0)
        {
            a=(N-k*b-k*11*c)>>1;
            if(2*a+k*b+k*11*c==N) ans[cnt++]=a+b*k+10*k*c;
        }
    }
    if(!cnt) printf("No solution.\n");
    else
    {
        sort(ans,ans+cnt);
        n=1;
        for(i=1;i<cnt;i++)
        {
            if(ans[i]!=ans[n-1])
                ans[n++]=ans[i];
        }
        cnt=n;
        for(i=0;i<cnt-1;i++)
            printf("%d ",ans[i]);
        printf("%d\n",ans[i]);
    }
}
int main()
{
    while(scanf("%d",&N),N)
    {
        Solve();
    }
return 0;
}