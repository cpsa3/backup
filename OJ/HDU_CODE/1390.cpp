////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2012-03-12 14:13:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1390
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

int N;

void Solve()
{
    bool flag=false;
    int n=0;
    while(N)
    {
        if(N%2)
        {
            if(!flag)
            {printf("%d",n);flag=true;}
            else
                printf(" %d",n);
        }
        N>>=1;
        n++;
    }
    printf("\n");
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        Solve();
    }
return 0;
}