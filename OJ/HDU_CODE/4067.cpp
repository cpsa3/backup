////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2011-10-11 16:14:01
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4067
////Problem Title: 
////Run result: Accept
////Run time:359MS
////Run memory:344KB
//////////////////System Comment End//////////////////
/*HDU_4067 Random Maze*/
/*��С���������(���ͼ)*/
/*
���⣺����n���㣬m���ߣ����s�ͳ���t������ÿ����������ֵa��b�����������������Ҫa���ѣ������Ƴ���������Ҫ����b��
      ��ĿҪ������С���ù���һ������ͼ��������������
      1.ֻ��һ����ںͳ���
      2.����·����Ψһ����
      3.�������s�����ĳ��� = ������� + 1
      4.���ڳ���t��������� = ���ĳ��� + 1
      5.����s��t�⣬���������� = �����
      ���������Թ��죬�����С���ã��������impossib��         

��ͼ��
(1):������������in[],out[],�ֱ��ʾ��ǰ������ͼ��ÿ�������Ⱥͳ��ȣ�
(2):��in[]��out[]��ʼȫΪ0,ans=0��
(3):����ÿ����u->v. 
		if(a<=b)  	//������ǰ��
		{
			Insert(v,u,1,b-a);
			ans+=a;
			in[v]++;out[u]++; 
		} 
		else 		//ɾ����ǰ�� 
		{
			Insert(u,v,1,a-b);
			ans+=b;	
		}
(4):Ϊ������s��t�ĳ���ȣ���������ļ���һ��t->s�ıߣ� in[s]++;out[t]++;
(5):���Դ���scr��sink
(6):�������е�i��
		if(in[i]>=out[i])	
			Insert(scr,i,in[i]-out[i],0);
		else 
			Insert(i,sink,out[i]-in[i],0);
(7):�����һ����С��������� 
		if(����scr�ĳ��߶�����)
			ans+=MinCost;
		else
			Impossible;
			
ps.����˵���㷨����ν��е����ģ�
	�ٸ��򵥵����ӣ�����ĳһ����i,in[i] > out[i],˵����ǰ����ȴ��ڵ�ǰ�ĳ��ȣ�
	��ô���ǿ���������������֮ǰɾ������iΪ���ı���ӻ��� ���� ��֮ǰ������
	��iΪ�յ�ı�ɾ�������ڱߵķ�����ʵ�Ǹı��״̬����Ҫ���⸶�ķ��ã�����С
	�������㷨�Ϳ��԰���ѡ����С�ĵ������ã�Ҳ�����Ǹ�mincost�� 
*/ 

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <queue>
#define MAXN 205
#define INF (1<<30)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;

struct edge
{
	int u,v,w,c,next;
}E[80000];
int head[MAXN],ecnt;
int pre[MAXN],dis[MAXN];
bool vis[MAXN];
int in[MAXN],out[MAXN];
int N,M,cas;
int scr,sink,vn,ans,ss,tt,In;

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
void Init()
{
	int i,j,u,v,w,c,a,b;
	scanf("%d%d%d%d",&N,&M,&ss,&tt);
	
	scr=0;sink=N+1;vn=sink+1;
	ans=0;
	memset(head,-1,sizeof(head));ecnt=0;
	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));
	
	for(i=1;i<=M;i++)
	{
		scanf("%d%d%d%d",&u,&v,&a,&b);
		if(a<=b)
		{
			Insert(v,u,1,b-a);
			in[v]++;out[u]++;
			ans+=a;
		}
		else
		{
			Insert(u,v,1,a-b);
			ans+=b;
		}
	}
	
	in[ss]++;out[tt]++;
	
	In=0;
	for(i=1;i<=N;i++)
	{
		if(in[i]>=out[i])
		{
			Insert(scr,i,in[i]-out[i],0);
			In+=in[i]-out[i];
		}
		else	
			Insert(i,sink,out[i]-in[i],0);
	}
}
queue<int>Q;
bool SPFA(int s,int t,int n)
{
	int i,u,v,c;
	while(!Q.empty()) Q.pop();
	memset(vis,false,sizeof(vis));
	for(i=0;i<=n;i++)//���·
		dis[i]=INF;
	Q.push(s);
	pre[s]=-1;
	dis[s]=0;
	vis[s]=true;
	while(!Q.empty())
	{
		u=Q.front();Q.pop();
		vis[u]=false;
		for(i=head[u];i!=-1;i=E[i].next)
		{
			v=E[i].v;c=E[i].c;
			if(E[i].w>0&&dis[v]>dis[u]+c)
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
	if(dis[t]!=INF) return true;
	return false;
}

void Solve()
{
	int flow=0,MinCost=0,i;
	while(SPFA(scr,sink,vn))
	{
		MinCost+=dis[sink];
		flow++;
		for(i=pre[sink];i!=-1;i=pre[E[i].u])
		{
			E[i].w--;
			E[i^1].w++;
		}
	}
	printf("Case %d: ",cas++);
	if(flow==In)
		printf("%d\n",ans+MinCost);
	else 
		printf("impossible\n");
}
int main()
{
	int T;
	cas=1;
	scanf("%d",&T);
	while(T--)
	{
		Init();
		Solve();
	}
	return 0;
}