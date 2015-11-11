////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-08-26 20:49:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3972
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:712KB
//////////////////System Comment End//////////////////
/*hash*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 100003
using namespace std;
int N,x;
char hash[MAXN];
int num[MAXN];
int ans[2];
int main()
{
    int T;
    int i,j;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        memset(hash,0,sizeof(hash));
        memset(num,-1,sizeof(num));
        while(N--)
        {
            scanf("%d",&x);
            for(i=x%100003;;i=(i+1)%100003)
            {
                if(num[i]==-1)
                {
                    num[i]=x;
                    hash[i]=1;
                    break;
                }
                else if(num[i]==x)
                {
                    hash[i]=(hash[i]+1)%3;
                    break;
                }
            }
        }
        int cnt=0;
        for(i=0;i<MAXN;i++)
        {
            if(hash[i]!=0)
            {
                if(hash[i]==2)
                {
                    ans[0]=ans[1]=num[i];
                    break;
                }
                else
                {
                    ans[cnt++]=num[i];
                    if(cnt==2) break;
                }
            }
        }
        if(ans[0]>ans[1])
            ans[0]^=ans[1]^=ans[0]^=ans[1];
        printf("%d %d\n",ans[0],ans[1]);
    }
return 0;
}