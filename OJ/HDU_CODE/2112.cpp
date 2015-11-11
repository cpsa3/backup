////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-11-19 16:44:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2112
////Problem Title: 
////Run result: Accept
////Run time:578MS
////Run memory:4200KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
const int MAX=1005;
const int INF=99999999;
int N,map[MAX][MAX],path[MAX],s;
bool hash[MAX];
struct px
{
    char r[50];
};
struct px stu[200],t1,t2;
int find(px w)
{
    int i;
    for(i=1;i<=s;i++)
        if(!strcmp(w.r,stu[i].r))
            break;
        if(i<=s)
            return i;
        else
        {s++;stu[s]=w;return s;}
}
int Dijkstra()
{
    int i,j;
    path[1]=0;
    for(j=1;j<=s;j++)
    {
        int min=INF,w=-1;
        for(i=1;i<=s;i++)
        {
            if(path[i]!=-1&&hash[i]&&path[i]<min)
            {min=path[i];w=i;}
        }
        if(w==-1)
            break;
        hash[w]=false;
        for(i=1;i<=s;i++)
        {
            if(hash[i]&&map[w][i]!=-1&&(path[i]>path[w]+map[w][i]||path[i]==-1))
                path[i]=path[w]+map[w][i];
        }
    }
return path[2];
}
main ()
{
    int i,j,d,a,b,flag;
    while(scanf("%d",&N)!=EOF)
    {
        if(N==-1) break;
        memset(map,-1,sizeof(map));
        memset(path,-1,sizeof(path));
        memset(hash,true,sizeof(hash));
        s=2,flag=0;
        scanf("%s%s",stu[1].r,stu[2].r);
        //scanf("%s%s",t1.r,t2.r);
        //a=find(t1);
        //b=find(t2);
        if(!strcmp(stu[1].r,stu[2].r))
            flag=1;
        for(i=1;i<=N;i++)
        {
            scanf("%s%s%d",t1.r,t2.r,&d);
            a=find(t1);
            b=find(t2);
            if(map[a][b]>d||map[a][b]==-1)
            {map[a][b]=map[b][a]=d;}
        }
        if(flag)
            printf("0\n");
        else
        printf("%d\n",Dijkstra());
    }
return 0;
}