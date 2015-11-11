////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-09-04 14:16:46
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4007
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:208KB
//////////////////System Comment End//////////////////
/*O(N^2)Ã¶¾Ù*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#define MAXN 1005
#define INF 2e9
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
struct Node
{
    int x,y;
}node[MAXN];
int xx[MAXN],yy[MAXN];
int xcnt,ycnt;
int N,R;
void Init()
{
    int i;
    for(i=1;i<=N;i++)
    {
        scanf("%d%d",&node[i].x,&node[i].y);
        yy[i]=node[i].y;
    }
    sort(yy+1,yy+1+N);
}
void Solve()
{
    int i,j,e,ans=0;
    for(i=1;i<=N;i++)
    {
        xcnt=0;
        for(j=1;j<=N;j++)
        {
            if(node[j].y>=yy[i]&&node[j].y<=yy[i]+R)
                xx[xcnt++]=node[j].x;
        }
        sort(xx,xx+xcnt);
        xx[xcnt++]=INF;
        e=0;
        for(j=0;j<xcnt-1;j++)
        {
            while(xx[e]<=xx[j]+R) e++;
            ans=max(ans,(e-j));
        }
    }
    printf("%d\n",ans);
}
int main()
{
    while(scanf("%d%d",&N,&R)!=EOF)
    {
        Init();
        Solve();
    }
return 0;
}