////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2012-03-12 14:17:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1599
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:332KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#define min(a,b) (a<b?a:b)
#define INF (1<<20)
using namespace std;

int map[105][105];
int dis[105][105];
int N,M;
void Init()
{
    int i,j,u,v,w;
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
            map[i][j]=dis[i][j]=INF;
    }
    for(i=1;i<=M;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        if(map[u][v]>w)
            map[u][v]=map[v][u]=dis[u][v]=dis[v][u]=w;
    }
}
void Floyd()
{
    int i,j,k;
    int ans=INF;
    for(k=1;k<=N;k++)
    {
        for(i=1;i<k;i++)
        {
            for(j=1;j<i;j++)
                ans=min(ans,map[i][k]+map[k][j]+dis[i][j]);
        }
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=N;j++)
            {
                if(dis[i][k]+dis[k][j]<dis[i][j])
                    dis[i][j]=dis[i][k]+dis[k][j];
            }
        }
    }
    if(ans==INF) printf("It's impossible.\n");
    else printf("%d\n",ans);
}
int main()
{
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        Init();
        Floyd();
    }
    return 0;
}