////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2011-05-01 18:38:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1054
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:288KB
//////////////////System Comment End//////////////////
//��С֧�伯������С�ĵ�ȥ����ȫ���㣬����С�㸲��������С�ĵ�ȥ����ȫ���ߣ���
/*����DP*/
/*
dp[v][0]: ��v���ڸ��Ǽ��ڣ���vΪ������������С�㸲����
dp[v][1]: ��v�ڸ��Ǽ��ڣ���vΪ������������С�㸲����

����v��u���ӽڵ㣬
dp[u][0] = sum(dp[v][1]);
dp[u][1] = sum(min(dp[v][0], dp[v][1])) + 1;
����v��Ҷ�ӽڵ㣬�ͣ�
dp[v][0] = 0;
dp[v][1] = 1;
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#define MAXN 1505
#define min(a,b) (a<b?a:b)
using namespace std;
struct edge
{
	int u,v,next;
}E[4000];
int head[MAXN],ecnt;
int dp[MAXN][2],root,N;
void Insert(int u,int v)
{
	E[ecnt].u=u;
	E[ecnt].v=v;
	E[ecnt].next=head[u];
	head[u]=ecnt++;
}
void Init()
{
	int i,j,u,v,num;
	memset(head,-1,sizeof(head));ecnt=0;
	root=-1;
	for(i=0;i<N;i++)
	{
		dp[i][0]=dp[i][1]=0;
		scanf("%d:(%d)",&u,&num);
		if(num!=0&&root==-1) root=u;
		for(j=1;j<=num;j++)
		{
			scanf("%d",&v);
			Insert(u,v);
		}
	}
}
void dfs(int u)
{
	int i,v;
	if(head[u]==-1)//Ҷ��
	{
		dp[u][0]=0;
		dp[u][1]=1;
		return;
	}
	for(i=head[u];i!=-1;i=E[i].next)
	{
		v=E[i].v;
		dfs(v);
		dp[u][0]+=dp[v][1];
		dp[u][1]+=min(dp[v][1],dp[v][0]);
	}
	dp[u][1]++;
}
void Solve()
{
	dfs(root);
	printf("%d\n",min(dp[root][0],dp[root][1]));
}
int main()
{
	while(scanf("%d",&N)!=EOF)
	{
		Init();
		Solve();
	}
return 0;
}