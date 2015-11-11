////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2011-08-30 12:22:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3046
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:2884KB
//////////////////System Comment End//////////////////
/*��С��*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 50000
#define INF 1e8
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct edge
{
    int u,v,w,next;
}E[2000000];
int head[MAXN],ecnt;
int gap[MAXN],dis[MAXN],pre[MAXN],cur[MAXN];
int N,M,cas,scr,sink,vn;
void Insert(int u,int v,int w)
{
    E[ecnt].u=u;
    E[ecnt].v=v;
    E[ecnt].w=w;
    E[ecnt].next=head[u];
    head[u]=ecnt++;
    E[ecnt].u=v;
    E[ecnt].v=u;
    E[ecnt].w=0;
    E[ecnt].next=head[v];
    head[v]=ecnt++;
}
void Init()
{
    int i,j,u,v,w;
    memset(head,-1,sizeof(head));ecnt=0;
    scr=0;sink=N*M+1;vn=sink+1;
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
        {
            u=(i-1)*M+j;
            scanf("%d",&w);
            if(w==1) Insert(u,sink,INF);
            if(w==2) Insert(scr,u,INF);
            if(i>1) Insert(u,u-M,1);
            if(i<N) Insert(u,u+M,1);
            if(j>1) Insert(u,u-1,1);
            if(j<M) Insert(u,u+1,1);
        }
    }
}
int Sap(int s,int t,int n)//���Ĵ���(ģ��)
{
    int ans=0,aug=INF;//aug��ʾ����·������
    int i,v,u=pre[s]=s;
    for(i=0;i<=n;i++)
    {
        cur[i]=head[i];
        dis[i]=gap[i]=0;
    }
    gap[s]=n;
    bool flag;
    while(dis[s]<n)
    {
        flag=false;
        for(int &j=cur[u];j!=-1;j=E[j].next)//һ��Ҫ�����int &j,why
        {
            v=E[j].v;
            if(E[j].w>0&&dis[u]==dis[v]+1)
            {
                flag=true;//�ҵ������
                aug=min(aug,E[j].w);
                pre[v]=u;
                u=v;
                if(u==t)
                {
                    ans+=aug;
                    while(u!=s)
                    {
                        u=pre[u];
                        E[cur[u]].w-=aug;
                        E[cur[u]^1].w+=aug;//ע��
                    }
                    aug=INF;
                }
                break;//�ҵ�һ�����˳�
            }
        }
        if(flag) continue;
        int mindis=n;
        for(i=head[u];i!=-1;i=E[i].next)
        {
            v=E[i].v;
            if(E[i].w>0&&dis[v]<mindis)
            {
                mindis=dis[v];
                cur[u]=i;
            }
        }
        if((--gap[dis[u]])==0) break;
        gap[dis[u]=mindis+1]++;
        u=pre[u];
    }
    return ans;
}
void Solve()
{
    int ans=Sap(scr,sink,vn);
    printf("Case %d:\n",cas++);
    printf("%d\n",ans);
}
int main()
{
    cas=1;
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        Init();
        Solve();
    }
return 0;
}
