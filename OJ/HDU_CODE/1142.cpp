////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-11-19 16:45:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1142
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:4172KB
//////////////////System Comment End//////////////////
#include <iostream>
const int MAX=1002;
const int INF=99999999;
int map[MAX][MAX],path[MAX],sum[MAX],N,M;
bool hash[MAX];
void Dijkstra()
{
    int i,j;
    for(i=1;i<=N;i++)//一定要加,最后都要到大重点2
        path[i]=map[i][2];
    path[2]=0;
    //hash[2]=false;
    for(i=1;i<=N;i++)
    {
        int min=INF,w=-1;
        for(j=1;j<=N;j++)
        {
            if(hash[j]&&path[j]<min)
            {min=path[j];w=j;}
        }
        if(w==-1)
            break;
        hash[w]=false;
        for(j=1;j<=N;j++)
        {
            if(hash[j]&&map[w][j]!=INF&&path[j]>path[w]+map[w][j])
                path[j]=path[w]+map[w][j];
        }
    }
return;
}
int dfs(int s)//记忆化搜索
{
    int i,ss=0;
    if(s==2) return 1;
    if(sum[s]!=-1) return sum[s];
    for(i=1;i<=N;i++)
    {
        if(map[s][i]!=INF&&path[s]>path[i])
        {
            int cur=dfs(i);
            ss+=cur;//累计路径的个数
        }
    }
    sum[s]=ss;
return ss;
}
main ()
{
    int i,j,a,b,d;
    while(scanf("%d",&N)!=EOF)
    {
        if(N==0) break;
        for(i=0;i<=N;i++)
            for(j=0;j<=N;j++)
            {
                map[i][j]=INF;
                map[i][i]=0;
                path[i]=INF;
                hash[i]=true;
                sum[i]=-1;
            }
        scanf("%d",&M);
        for(i=1;i<=M;i++)
        {
            scanf("%d%d%d",&a,&b,&d);
            if(map[a][b]>d)//判断重边
            {map[a][b]=map[b][a]=d;}
        }
        Dijkstra();
        printf("%d\n",dfs(1));
    }
return 0;
}