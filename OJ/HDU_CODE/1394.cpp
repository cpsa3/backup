////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2012-03-12 14:12:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1394
////Problem Title: 
////Run result: Accept
////Run time:250MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#define min(a,b) (a<b?a:b)
using namespace std;
int N;
int a[5005];
int Min;
int main()
{
    int i,j;
    while(scanf("%d",&N)!=EOF)
    {
        for(i=0;i<N;i++)
            scanf("%d",&a[i]);
        Min=0;
        for(i=0;i<N;i++)
        {
            for(j=i+1;j<N;j++)
            {
                if(a[i]>a[j]) Min++;
            }
        }
        int t=Min;
        for(i=0;i<N;i++)
        {
            t=t-a[i]+(N-1-a[i]);
            Min=min(Min,t);
        }
        printf("%d\n",Min);
    }
return 0;
}