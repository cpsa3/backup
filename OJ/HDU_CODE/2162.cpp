////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2012-03-12 14:00:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2162
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n,x,cnt=1;
    while(scanf("%d",&n)!=EOF)
    {
        if(n<=0) break;
        int sum = 0;
        while(n--)
        {
            scanf("%d",&x);
            sum+=x;
        }
        printf("Sum of #%d is %d\n",cnt++,sum);
    }
return 0;
}