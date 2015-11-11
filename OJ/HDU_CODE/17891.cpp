////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-10-02 14:47:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1789
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:248KB
//////////////////System Comment End//////////////////
/*HDU_1789 Doing Homework again*/
/*Ì°ÐÄ O(n^2)*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 1005
#define INF (1<<30)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;

struct Node
{
    int d,w;
    bool mark;
}node[MAXN];
int N;

int cmp(const void *p1,const void *p2)
{
    return ((struct Node *)p1)->d-((struct Node *)p2)->d;
}
void Init()
{
    int i;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
        scanf("%d",&node[i].d);
        node[i].mark=true;
    }
    for(i=1;i<=N;i++)
        scanf("%d",&node[i].w);
    qsort(node+1,N,sizeof(node[0]),cmp);
}

void Solve()
{
    int ans=0,num=0;
    int i,j,pos,Min;
    for(i=1;i<=N;i++)
    {
        if(num<node[i].d) num++;
        else
        {
            Min=INF;
            for(j=1;j<=i;j++)
            {
                if(!node[j].mark) continue;
                if(Min>node[j].w)
                {Min=node[j].w;pos=j;}
            }
            ans+=Min;
            node[pos].mark=false;
        }
    }
    printf("%d\n",ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        Init();
        Solve();
    }
return 0;
}