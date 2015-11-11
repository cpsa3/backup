////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-11-19 16:49:25
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1690
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:320KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>
const int MAX=105;
const __int64 INF=9999999999999999;//注意这个已经超过int范围了
__int64 map[MAX][MAX],B[MAX];
int L1,L2,L3,L4,C1,C2,C3,C4,T,N,M;
void Floyd()
{
    int i,j,k;
    for(k=1;k<=N;k++)
        for(i=1;i<=N;i++)
        {
            if(map[i][k]==INF)
                continue;
            for(j=1;j<=N;j++)
            {
                if(map[k][j]==INF)
                    continue;
                if(map[i][j]>map[i][k]+map[k][j])
                    map[i][j]=map[i][k]+map[k][j];
            }
        }
}
main ()
{
    int i,j,cas,s,e;
    __int64 sum,len;
    scanf("%d",&T);
    for(cas=1;cas<=T;cas++)
    {
        scanf("%d%d%d%d%d%d%d%d",&L1,&L2,&L3,&L4,&C1,&C2,&C3,&C4);
        scanf("%d%d",&N,&M);
        for(i=0;i<=N;i++)
            for(j=0;j<=N;j++)
            {
                map[i][j]=INF;
                map[i][i]=0;
            }
            for(i=1;i<=N;i++)
                scanf("%I64d",&B[i]);
            for(i=1;i<=N;i++)
                for(j=i+1;j<=N;j++)
                {
                    len=abs((int)(B[i]-B[j]));
                    if(len<=L1)
                        sum=C1;
                    else if(len<=L2)
                        sum=C2;
                    else if(len<=L3)
                        sum=C3;
                    else if(len<=L4)
                        sum=C4;
                    else
                        sum=INF;
                    map[i][j]=map[j][i]=sum;
                }
                Floyd();
                printf("Case %d:\n",cas);
                for(i=1;i<=M;i++)
                {
                    scanf("%d%d",&s,&e);
                    if(map[s][e]==INF)
                        printf("Station %d and station %d are not attainable.\n",s,e);
                    else
                        printf("The minimum cost between station %d and station %d is %I64d.\n",s,e,map[s][e]);
                }
    }
    return 0;
}