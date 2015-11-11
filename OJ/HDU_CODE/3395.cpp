////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2011-08-29 02:06:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3395
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:464KB
//////////////////System Comment End//////////////////
/*�����������+���*/
/*KM���Ȩƥ��*/
/*
��ͼ��
(1):��ÿ����i���Xi��Yi�����㡣Xi��ʾ������Yi��ʾ������
(2):scr��ÿ����Xi��һ������Ϊ1������Ϊ0�ıߣ���ʾÿ����ֻ������ȥƥ��һ�Σ�
(3):ÿ����Yi����sink��һ������Ϊ1����Ϊ0�ıߣ����ÿ����ֻ�ܱ�ƥ��һ�Σ�
(4):�����i��Ϊ��j��female�����Xi��Yj��һ������Ϊ1������ΪW[i]^W[j]�ıߣ�
    ��ʾ��i������������jƥ��һ�Ρ�
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <queue>
#define MAXN 205
#define INF 1e8
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct edge
{
    int u,v,w,c,next;
}E[200000];
int head[MAXN],ecnt;
int N,scr,sink,vn;
int W[MAXN];
char map[MAXN][MAXN];
int pre[MAXN],dis[MAXN];
bool vis[MAXN];
void Insert(int u,int v,int w,int c)
{
    E[ecnt].u=u;
    E[ecnt].v=v;
    E[ecnt].w=w;
    E[ecnt].c=c;
    E[ecnt].next=head[u];
    head[u]=ecnt++;
    E[ecnt].u=v;
    E[ecnt].v=u;
    E[ecnt].w=0;
    E[ecnt].c=-c;
    E[ecnt].next=head[v];
    head[v]=ecnt++;
}
void Print()
{
    int i;
    for(i=0;i<ecnt;i+=2)
        printf("%d %d %d %d \n",E[i].u,E[i].v,E[i].w,E[i].c);
    printf("**************************\n");
}
void Init()
{
    int i,j,u,v,c;
    memset(head,-1,sizeof(head));ecnt=0;
    scr=0;sink=N*2+1;vn=sink+1;
    for(i=1;i<=N;i++)
        scanf("%d",&W[i]);
    for(i=0;i<N;i++)
        scanf("%s",map[i]);
    //��ͼ
    for(i=1;i<=N;i++)
    {
        Insert(scr,i,1,0);
        Insert(i+N,sink,1,0);
    }
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
        {
            if(i==j) continue;
            if(map[i-1][j-1]=='1')
            {
                c=W[i]^W[j];
                Insert(i,j+N,1,c);
            }
        }
    }
    //Print();
}
queue<int>Q;
bool SPFA(int s,int t,int n)
{
	
	int i,u,v,c;
	memset(vis,false,sizeof(vis));
	for(i=0;i<=n;i++)
		dis[i]=-INF;
	Q.push(s);
	pre[s]=-1;
	dis[s]=0;
	vis[s]=true;
	while(!Q.empty())
	{
		//printf("^\n");
		u=Q.front();Q.pop();
		vis[u]=false;
		for(i=head[u];i!=-1;i=E[i].next)
		{
			v=E[i].v;c=E[i].c;
			if(E[i].w>0&&dis[v]<dis[u]+c)//ǰ����E[i].w>0
			{
				dis[v]=dis[u]+c;
				pre[v]=i;
				if(!vis[v])
				{
					vis[v]=true;
					Q.push(v);
				}
			}
		}
	}
	//printf("%d\n",dis[t]);
	if(dis[t]>0) return true;
	return false;
}
void Solve()
{
    int i,ans=0,flow;
    while(SPFA(scr,sink,vn))
    {
        ans+=dis[sink];
        for(i=pre[sink];i!=-1;i=pre[E[i].u])//����
		{
			E[i].w--;
			E[i^1].w++;
		}
    }
    printf("%d\n",ans);
}
int main()
{
    while(scanf("%d",&N),N)
    {
        Init();
        Solve();
    }
return 0;
}