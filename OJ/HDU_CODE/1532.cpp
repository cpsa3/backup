////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2010-12-29 22:30:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1532
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:580KB
//////////////////System Comment End//////////////////
/*���������*/
#include <iostream>
#include <queue>
using namespace std;
#define INF 99999999
#define MAXN 205
int cp[MAXN][MAXN];//������i,j������
int flow[MAXN][MAXN];//������i,j������
int a[MAXN];//a[i]=j:Դ��s��i����С����Ϊj
int p[MAXN];//p[v]=u;��ʾv�ĸ��ڵ�Ϊu
int N,M;//N:����  M:����
int maxf;//��¼�ܵ�����
int min(int a,int b)
{return a<b?a:b;}
queue<int>Q;
//��s->t�������
void Edmonds_Karp(int s,int t)//sΪԴ��,tΪ���
{
	int u,v;
	memset(p,0,sizeof(p));
	maxf=0;
	while(true)
	{
		memset(a,0,sizeof(a));//ÿ��������·��ʱ��Ҫ��ʼ��
		if(!Q.empty())
			Q.pop();
		Q.push(s);
		a[s]=INF;
		while(!Q.empty())//bfs������·��
		{
			u=Q.front();
			Q.pop();
			for(v=1;v<=M;v++)
			{
				if(!a[v]&&cp[u][v]>flow[u][v])
				{
					p[v]=u;//ע�ⲻ��p[u]=v;��¼v�ĸ��ڵ�
					Q.push(v);
					a[v]=min(a[u],cp[u][v]-flow[u][v]);//����v����С����
				}
			}
		}
		if(!a[t])//û���ҵ�����·��
			break;
		//�������������ͷ�������
		for(u=t;u!=s;u=p[u])//�ݹ��������·��
		{
			flow[p[u]][u]+=a[t];
			flow[u][p[u]]-=a[t];
		}
		maxf+=a[t];//���´�s������������
	}
	printf("%d\n",maxf);
}
int main()
{
	int s,e,c,i;
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		memset(cp,0,sizeof(cp));
		memset(flow,0,sizeof(flow));
		for(i=1;i<=N;i++)
		{
			scanf("%d%d%d",&s,&e,&c);
			cp[s][e]+=c;//�رߴ���
		}
		Edmonds_Karp(1,M);
	}
	return 0;
}