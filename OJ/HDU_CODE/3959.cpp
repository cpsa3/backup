////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-08-19 01:09:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3959
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
/*ÆÚÍû*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cmath>
using namespace std;
__int64 N,M,X,A,B;
int cas;
__int64 gcd(__int64 n,__int64 m)
{
    if(m==0) return n;
    return gcd(m,n%m);
}
int main()
{
    int T;
    cas=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d%I64d",&N,&M);
        X=(__int64)((log10(N*1.0))/(log10(M*1.0)));
        __int64 t=(__int64)pow(M*1.0,X*1.0);
        if(t<N) 
        {
            X++;
            t*=M;
        }
        A=X*t;
        B=N;
        __int64 w=gcd(A,B);
        printf("Case %d: %I64d/%I64d\n",cas++,A/w,B/w);
    }
return 0;
}