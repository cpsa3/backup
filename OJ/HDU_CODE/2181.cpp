////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2012-03-12 14:09:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2181
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

int dir[21][4];
int s[30];
bool vis[30];
int cnt;
int m;
void Init()
{
    int i,j;
    for(i=1;i<=20;i++)
    {
        for(j=1;j<=3;j++)
            scanf("%d",&dir[i][j]);
        sort(dir[i]+1,dir[i]+4);
    }
}
void fuck(int s[])
{
    int i;
    printf("%d: ",++cnt);
    for(i=1;i<=20;i++)
        printf(" %d",s[i]);
    printf(" %d\n",m);
}
void dfs(int s[],int num,bool vis[])
{
    int i,j,a,b;
    a=s[num];
    if(num==20)
    {
        if(dir[a][1]==m||dir[a][2]==m||dir[a][3]==m)
            fuck(s);
        return;
    }
    for(i=1;i<=3;i++)
    {
        b=dir[a][i];
        if(!vis[b])
        {
            vis[b]=true;
            s[num+1]=b;
            dfs(s,num+1,vis);
            vis[b]=false;
        }
    }
}
void Solve()
{
    while(scanf("%d",&m)!=EOF)
    {
        if(m==0) break;
        cnt=0;
        memset(vis,false,sizeof(vis));
        vis[m]=true;
        s[1]=m;
        dfs(s,1,vis);
    }
}
int main()
{
    Init();
    Solve();
return 0;
}