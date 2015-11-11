////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2012-03-12 14:08:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2160
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#define min(a,b) (a<b?a:b)
#define MOD 10000
using namespace std;
int N;
int f[30];
int main()
{
    int i;
    f[1]=1;f[2]=2;
    for(i=3;i<=20;i++)
        f[i]=f[i-1]+f[i-2];
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        printf("%d\n",f[N]);
    }
return 0;
}