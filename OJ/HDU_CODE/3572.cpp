////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2011-04-28 22:44:04
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3572
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:2860KB
//////////////////System Comment End//////////////////
/*�������ͼ��*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 1005
#define INF 1e8
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct edge
{
	int u,v,w,next; 
}E[200000];
int head[MAXN],ecnt;
int gap[MAXN],cur[MAXN],dis[MAXN],pre[MAXN];
int N,M,scr,sink,vn,cas,ans;
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
	int i,j,P,S,E;
	memset(head,-1,sizeof(head));ecnt=0;
	scanf("%d%d",&N,&M);
	scr=0;sink=N+500+1;vn=sink+1;ans=0;
	for(i=1;i<=N;i++)
	{
		scanf("%d%d%d",&P,&S,&E);
		ans+=P;
		Insert(scr,i,P);
		for(j=S;j<=E;j++)
			Insert(i,N+j,1);
	}
	for(i=1;i<=500;i++)
		Insert(i+N,sink,M);
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
	printf("Case %d: ",cas++);
	if(Sap(scr,sink,vn)==ans)
		printf("Yes\n");
	else
		printf("No\n"); 
}
int main()
{
	int T;
	scanf("%d",&T);
	cas=1;
	while(T--)
	{
		Init();
		Solve();
		printf("\n");
	}
return 0;
}