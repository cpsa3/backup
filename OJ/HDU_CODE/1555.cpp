////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2012-03-12 14:03:46
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1555
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;

int M,K;
int main()
{
    int i,ans,cnt;
    while(scanf("%d%d",&M,&K)!=EOF)
    {
        if(M==0&&K==0) break;
        ans=cnt=0;
        while(M)
        {
            M--;
            ans++;
            cnt++;
            if(cnt==K)
            {
                M++;
                cnt=0;
            }
        }
        printf("%d\n",ans);
    }
return 0;
}
