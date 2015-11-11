////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2011-05-05 01:08:13
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2485
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:328KB
//////////////////System Comment End//////////////////
/*��������������С��(���)*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <queue>
#define MAXN 105
#define INF 1e8
#define min(a,b) (a<b?a:b)
using namespace std;
struct edge
{
	int u,v,w,next; 
}E[200000];
int head[MAXN],ecnt;
int gap[MAXN],cur[MAXN],dis[MAXN],pre[MAXN];
int map[55][55];
bool G[55][55];
int N,M,K,scr,sink,vn;
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
void Floyd()
{
	int i,j,k;
	for(k=1;k<=N;k++)
	{
		for(i=1;i<=N;i++)
		{
			if(k==i||map[i][k]==-1) continue;
			for(j=1;j<=N;j++)
			{
				if(i==j||k==j||map[k][j]==-1) continue;
				if(map[i][j]==-1||map[i][j]>map[i][k]+map[k][j])
					map[i][j]=map[i][k]+map[k][j]; 
			}
		}
	}
}
void Init()
{
	int i,j,u,v;
	memset(map,-1,sizeof(map));
	memset(G,false,sizeof(G));
	for(i=1;i<=N;i++)
		G[i][i]=true;
	memset(head,-1,sizeof(head));ecnt=0;
	//scr=0;sink=2*N+1;vn=sink+1;
	scr=1;sink=N*2;vn=sink;
	for(i=1;i<=M;i++)
	{
		scanf("%d%d",&u,&v);
		map[u][v]=1;G[u][v]=true;
	}
	Floyd();
	//ɾ��û�õĵ�
	for(i=2;i<=N-1;i++)
	{
		if(map[1][i]+map[i][N]>K)
		{
			for(j=1;j<=N;j++)//ɾ����õ���ص����б�
				G[i][j]=G[j][i]=false;
		}
	}
	for(i=2;i<=N-1;i++)//���
	{
		if(G[i][i])
			Insert(i,i+N,1); 
	}
	//��Ϊ1��N���ܱ��ƻ�
	Insert(1,1+N,INF);
	Insert(N,N+N,INF);
	//Insert(scr,1,INF);
	//Insert(N+N,sink,INF);
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			if(i==j) continue;
			if(G[i][j])
				Insert(i+N,j,INF); 
		} 
	} 
}
void Solve()
{
	printf("%d\n",Sap(scr,sink,vn));
}
int main()
{
	while(scanf("%d%d%d",&N,&M,&K)!=EOF)
	{
		if(N==0&&M==0&&K==0) break;
		Init();
		Solve();
	}
return 0;
}