////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-11-19 16:46:23
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1385
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:264KB
//////////////////System Comment End//////////////////
#include <iostream>
const int MAX=105;
//const int INF=99999999;
int map[MAX][MAX],tax[MAX],path[MAX][MAX],N;
void find(int start,int end)
{
    while(path[start][end]!=end)
    {
        printf("-->%d",path[start][end]);
        start=path[start][end];
    }
    printf("-->%d\n",end);
}
main ()
{
    int i,j,k,s,e;
    while(scanf("%d",&N)!=EOF)
    {
        if(N==0)
            break;
        for(i=1;i<=N;i++)
            for(j=1;j<=N;j++)
            {
                scanf("%d",&map[i][j]);
                //if(map[i][j]==-1)
                //    map[i][j]=INF;
                path[i][j]=j;//path[i][j]表示从i到j的路径中,靠近i的点
            }
        for(i=1;i<=N;i++)
            scanf("%d",&tax[i]); 
        for(k=1;k<=N;k++)
            for(i=1;i<=N;i++)
            {
                if(i==k||map[i][k]==-1)
                    continue;
                for(j=1;j<=N;j++)
                {
                    if(map[k][j]==-1||i==j||j==k)
                        continue;
                    if(map[i][j]==-1||map[i][j]>map[i][k]+map[k][j]+tax[k])
                    {
                        map[i][j]=map[i][k]+map[k][j]+tax[k];
                        path[i][j]=path[i][k];
                    }
                    if(map[i][j]==map[i][k]+map[k][j]+tax[k]&&path[i][j]>path[i][k])
                        path[i][j]=path[i][k];//为了找更近的点
                }
            }
        while(scanf("%d%d",&s,&e)!=EOF)
        {
            if(s==-1&&e==-1)
                break;
            printf("From %d to %d :\n",s,e);
            if(s==e)
                printf("Path: %d\n",s);
            else
            {
                printf("Path: %d",s);
                find(s,e);
            }
            printf("Total cost : %d\n\n",map[s][e]);
        }
    }
return 0;
}