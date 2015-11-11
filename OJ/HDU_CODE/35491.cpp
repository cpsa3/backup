////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2011-08-24 18:05:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3549
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:272KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>
#include<vector>
using namespace std;
#define INF 1e8
#define min(a,b)(a<b?a:b)
int dis[200],cur[200],gap[200],pre[200];
int head[200];
int N,M,ecnt,sink,scr,vn;
struct edge
{
    int u,v,next,w;
}E[50000];
void Insert(int u,int v,int w)
{
    E[ecnt].u=u;
    E[ecnt].v=v;
    E[ecnt].w=w;
    E[ecnt].next=head[u];
    head[u]=ecnt++;
    E[ecnt].u=v;
    E[ecnt].v=u;
    E[ecnt].next=head[v];
    E[ecnt].w=0;
    head[v]=ecnt++;
}
int sap(int s,int t,int n)//���Ĵ���(ģ��)
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
void Init()
{
    int i,a,b,c;
    memset(head,-1,sizeof(head));
    ecnt=0;
    scanf("%d%d",&N,&M);
    for(i=1;i<=M;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        Insert(a,b,c);
    }
}
void Solve()
{
	scr=1;
	sink=N;
	vn=sink;
	printf("%d\n",sap(scr,sink,vn));
}
int main()
{
    int i,cas;
    scanf("%d",&cas);
    for(i=1;i<=cas;i++)
    {
		
        Init();
        printf("Case %d: ",i);
        Solve();
		
    }
    return 0;
}
