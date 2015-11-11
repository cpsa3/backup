////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-11-19 16:48:01
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2680
////Problem Title: 
////Run result: Accept
////Run time:234MS
////Run memory:4144KB
//////////////////System Comment End//////////////////
#include <iostream>
const int MAX=1005;
const int INF=99999999;
int map[MAX][MAX],path[MAX],N,M,S;
bool hash[MAX];
void Dijkstra()
{
    int i,j;
    path[S]=0;
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
            if(map[w][j]!=INF&&path[j]>path[w]+map[w][j])
                path[j]=path[w]+map[w][j];
        }
    }
    return;
}
main ()
{
    int i,j,a,b,d,w,r;
    while(scanf("%d%d%d",&N,&M,&S)!=EOF)
    {
        for(i=0;i<=N;i++)
            for(j=0;j<=N;j++)
            {
                map[i][j]=INF;
                map[i][i]=0;
                path[i]=INF;
                hash[i]=true;
            }
            for(i=1;i<=M;i++)
            {
                scanf("%d%d%d",&a,&b,&d);
                if(map[b][a]>d)
                    map[b][a]=d;
            }
            scanf("%d",&w);
            Dijkstra();
            int ans=INF;
            for(i=1;i<=w;i++)
            {
                scanf("%d",&r);
                if(ans>path[r])
                    ans=path[r];
            }
            if(ans==INF)
                printf("-1\n");
            else
                printf("%d\n",ans);
    }
    return 0;
}