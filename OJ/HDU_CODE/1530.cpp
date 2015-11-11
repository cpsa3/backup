////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2012-03-12 14:19:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1530
////Problem Title: 
////Run result: Accept
////Run time:6250MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#define max(a,b) (a>b?a:b)
using namespace std;

bool vis[55];
int num[55];
int map[55][55];
int N,ans;
void Init()
{
    int i,j;
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
            scanf("%d",&map[i][j]);
    }
}
bool Judge(int num[],int n)
{
    if(n<=1) return true;
    int i,v;
    v=num[n];
    for(i=1;i<n;i++)
    {
        if(map[v][num[i]]==0) return false;
    }
    return true;
}
void dfs(int num[],bool vis[],int n)
{
    if(!Judge(num,n))
        return;
    ans=max(ans,n);
    int i,u,v;
    for(i=num[n]+1;i<=N;i++)
    {
        //if(!vis[i])
        //{
            vis[i]=true;
            num[n+1]=i;
            dfs(num,vis,n+1);
            vis[i]=false;
        //}
    }
}
void Solve()
{
    ans=0;
    memset(vis,false,sizeof(vis));
    num[0]=0;
    dfs(num,vis,0);
    printf("%d\n",ans);
}
int main()
{
    while(scanf("%d",&N),N)
    {
        Init();
        Solve();
    }
return 0;
}