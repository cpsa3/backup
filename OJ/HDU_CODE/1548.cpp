////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-11-19 16:46:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1548
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:400KB
//////////////////System Comment End//////////////////
#include <iostream>
const int MAX=205;
const int INF=99999999;
int N,A,B,K[MAX],map[MAX][MAX],path[MAX];
bool hash[MAX];
int Dijkstra()
{
    int i,j;
    path[A]=0;
    for(i=1;i<=N;i++)
    {
        int min=INF,w=-1;
        for(j=1;j<=N;j++)
        {
            if(hash[j]&&min>path[j])
            {min=path[j];w=j;}
        }
        if(w==-1)
            break;
        hash[w]=false;
        for(j=1;j<=N;j++)
        {
            if(map[w][j]!=0&&path[j]>path[w]+map[w][j])
                path[j]=path[w]+map[w][j];
        }
    }
    if(path[B]==INF)
        return -1;
    else
        return path[B];
}
main ()
{
    int i,j;
    while(scanf("%d",&N)!=EOF)
    {
        if(N==0) break;
        for(i=0;i<=N;i++)
            for(j=0;j<=N;j++)
            {
                map[i][j]=0;
                map[i][i]=1;
                path[i]=INF;
                hash[i]=true;
            }
        scanf("%d%d",&A,&B);
        for(i=1;i<=N;i++)
        {
            scanf("%d",&K[i]);
            if(i+K[i]<=N)
                map[i][i+K[i]]=1;
            if(i-K[i]>=1)
                map[i][i-K[i]]=1;
        }
        printf("%d\n",Dijkstra());
    }
return 0;
}