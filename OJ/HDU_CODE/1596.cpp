////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-11-19 16:52:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1596
////Problem Title: 
////Run result: Accept
////Run time:4156MS
////Run memory:8152KB
//////////////////System Comment End//////////////////
#include <iostream>
const int MAX=1005;
const int INF=99999999;
double map[MAX][MAX];
int N,Q;
void Floyd()
{
    int i,j,k;
    for(k=1;k<=N;k++)
        for(i=1;i<=N;i++)
        {
            if(map[i][k]==0)
                continue;
            for(j=1;j<=N;j++)
            {
                if(map[k][j]==0) 
                    continue;
                if(map[i][j]<map[i][k]*map[k][j])
                    map[i][j]=map[i][k]*map[k][j];
            }
        }
}

int main ()
{
    int i,j,s,e;
    while(scanf("%d",&N)!=EOF)
    {
        memset(map,0,sizeof(map));
        for(i=1;i<=N;i++)
            for(j=1;j<=N;j++)
                scanf("%lf",&map[i][j]);
        Floyd();
        scanf("%d",&Q);
        for(i=1;i<=Q;i++)
        {
            scanf("%d%d",&s,&e);
            if(map[s][e]==0)
                printf("What a pity!\n");
            else
                printf("%.3lf\n",map[s][e]);
        }
    }
return 0;
}