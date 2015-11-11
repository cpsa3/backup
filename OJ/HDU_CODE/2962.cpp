////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-11-19 16:48:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2962
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:8128KB
//////////////////System Comment End//////////////////
#include <iostream>
const int MAX=1005;
const int INF=999999999;
int map1[MAX][MAX],path1[MAX],C,R,map2[MAX][MAX],path2[MAX];
bool hash[MAX];
int min1(int a,int b)
{
    return a<b?a:b;
}
int Dijkstra1(int s,int e)
{
    int i,j;
    for(i=1;i<=C;i++)
    {
        hash[i]=true;
        path1[i]=-1;
    }
    path1[s]=INF;
    for(i=1;i<=C;i++)
    {
        int min=-1,w=-1;
        for(j=1;j<=C;j++)
        {
            if(hash[j]&&path1[j]>min)
            {min=path1[j];w=j;}
        }
        if(w==-1)
            break;
        hash[w]=false;
        for(j=1;j<=C;j++)
        {
            if(map1[w][j]!=-1&&path1[j]<min1(path1[w],map1[w][j]))
                path1[j]=min1(path1[w],map1[w][j]);
        }
    }
    return path1[e];
}
int Dijkstra2(int s,int e)
{
    int i,j;
    for(i=1;i<=C;i++)
    {
        hash[i]=true;
        path2[i]=INF;
    }
    path2[s]=0;
    for(i=1;i<=C;i++)
    {
        int min=INF,w=-1;
        for(j=1;j<=C;j++)
        {
            if(hash[j]&&path2[j]<min)
            {min=path2[j];w=j;}
        }
        if(w==-1)
            break;
        hash[w]=false;
        for(j=1;j<=C;j++)
        {
            if(map2[w][j]!=INF&&path2[j]>path2[w]+map2[w][j])
                path2[j]=path2[w]+map2[w][j];
        }
    }
        return path2[e];
}
main ()
{
    int i,j,a,b,h,l,s,e,d,cas=1;
    while(scanf("%d%d",&C,&R)!=EOF)
    {
        if(C==0&&R==0)
            break;
        for(i=0;i<=C;i++)
            for(j=0;j<=C;j++)
            {
                map1[i][j]=-1;
                map1[i][i]=INF;
                map2[i][j]=INF;
                map2[i][i]=0;
            }
            for(i=1;i<=R;i++)
            {
                scanf("%d%d%d%d",&a,&b,&h,&l);
                if(h==-1)
                    map1[a][b]=map1[b][a]=INF;
                else 
                {
                    if(map1[a][b]<h)
                        map1[a][b]=map1[b][a]=h;
                }
                if(map2[a][b]>l)
                {map2[a][b]=map2[b][a]=l;}
            }
            scanf("%d%d%d",&s,&e,&d);
            for(i=1;i<=C;i++)
                for(j=1;j<=C;j++)
                    if(map1[i][j]>d)
                        map1[i][j]=d;
                    int ans1=Dijkstra1(s,e);
                    if(cas!=1)
                        printf("\n");
                    printf("Case %d:\n",cas++);
                    if(ans1==-1)
                        printf("cannot reach destination\n");

                    else
                    {
                        for(i=1;i<=C;i++)
                            for(j=1;j<=C;j++)
                                if(map1[i][j]<ans1)
                                    map2[i][j]=INF;
                                int ans2=Dijkstra2(s,e);
                                printf("maximum height = %d\n",ans1);
                                printf("length of shortest route = %d\n",ans2);
                    }
    }
    return 0;
}