////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-11 23:15:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3371
////Problem Title: 
////Run result: Accept
////Run time:890MS
////Run memory:1468KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
const int MAXN=505;
const int INF=99999999;
int N,M,K,sum;
int p[MAXN];
int map[MAXN][MAXN],node[MAXN];
int mark[MAXN];
struct px 
{
    int s,e,v;
};
struct px stu[25005];
int cmp(const void *p1,const void *p2)
{
    return ((struct px *)p1)->v-((struct px *)p2)->v;
}
int find_set(int x)
{
    if(p[x]!=x)
        p[x]=find_set(p[x]);
    return p[x];
}
int main ()
{
    int T,t,x,dx,dy,i,j,y,k,temp;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&N,&M,&K);
        for(i=1;i<=N;i++)
            p[i]=i;
        for(i=1;i<=M;i++)
            scanf("%d%d%d",&stu[i].s,&stu[i].e,&stu[i].v);
        qsort(stu+1,M,sizeof(stu[0]),cmp);
        for(i=1;i<=K;i++)
        {
            scanf("%d",&t);
            scanf("%d",&x);
            dx=find_set(x);
            for(j=2;j<=t;j++)
            {
                scanf("%d",&y);
                dy=find_set(y);
                if(dx!=dy)
                    p[dy]=dx;
            }
        }
        sum=0;
        memset(mark,0,sizeof(mark));
        for(i=1;i<=N;i++)
        {
            temp=find_set(i);
            if(temp==i)
                node[++sum]=i;
        }
        for(i=1;i<=N;i++)
            for(j=1;j<=N;j++)
            {
                map[i][j]=INF;
                map[i][i]=0;
            }
            for(i=1;i<=M;i++)
            {
                dx=find_set(stu[i].s);
                dy=find_set(stu[i].e);
                if(dx!=dy)
                {
                    if(map[dx][dy]>stu[i].v)
                        map[dx][dy]=map[dy][dx]=stu[i].v;
                }
            }
            vector<int>V;
            V.push_back(node[1]);
            mark[node[1]]=1;
            int ans=0;
            int flag=0;
            while(V.size()<sum)
            {
                int d,min=INF;
                for(i=0;i<V.size();i++)
                {
                    for(j=1;j<=sum;j++)
                    {
                        if(mark[node[j]]==0&&min>map[node[j]][V[i]])
                        {min=map[node[j]][V[i]];d=node[j];}
                    }
                }
                V.push_back(d);
                mark[d]=1;
                ans+=min;
                if(min==INF)
                {flag=1;break;}
            }
            if(flag)
                printf("-1\n");
            else
            printf("%d\n",ans);
    }
    return 0;
}
/*
2
4 3 1
1 2 1
1 3 2
1 4 3
2 3 2

*/