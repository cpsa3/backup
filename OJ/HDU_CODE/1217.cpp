////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-11-19 16:47:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1217
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:260KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
const int MAX=40;
const int INF=99999999;
double map[MAX][MAX];
int N,M;
char stu[40][40],t1[40],t2[40];
int find(char t[40])
{
    int i;
    for(i=1;i<=N;i++)
        if(!strcmp(stu[i],t))
            break;
        return i;
}
void Floyd()
{
    int i,j,k;
    for(k=1;k<=N;k++)
        for(i=1;i<=N;i++)
        {
            if(map[i][k]==-1) continue;
            for(j=1;j<=N;j++)
            {
                if(map[k][j]==-1) continue;
                if(map[i][j]<map[i][k]*map[k][j])//Floydµƒ∏ƒ±‡∞Ê
                    map[i][j]=map[i][k]*map[k][j];
            }
        }
}
main ()
{
    int i,j,a,b,cas=1;
    double d;
    while(scanf("%d",&N)!=EOF)
    {
        if(N==0) break;
        for(i=0;i<=N;i++)
            for(j=0;j<=N;j++)
                map[i][j]=-1;
        //memset(map,-1.0,sizeof(map));
        for(i=1;i<=N;i++)
            scanf("%s",stu[i]);
        scanf("%d",&M);
        for(i=1;i<=M;i++)
        {
            scanf("%s%lf%s",t1,&d,t2);
            a=find(t1);
            b=find(t2);
            map[a][b]=d;
        }
        Floyd();
        int flag=0;
        for(i=1;i<=N;i++)
            if(map[i][i]>1)
            {flag=1;break;}
            printf("Case %d: ",cas++);
            if(flag)
                printf("Yes\n");
            else
                printf("No\n");
    }
    return 0;
}