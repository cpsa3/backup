////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-23 02:28:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3212
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:388KB
//////////////////System Comment End//////////////////
/*最小树形图*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <map>
#include <string>
#define MAXN 105
#define INF 1e9
#define min(a,b) (a<b?a:b)
using namespace std;
double Map[MAXN][MAXN];
bool vis[MAXN],circle[MAXN];
int pre[MAXN];
int N,root,cnt;
map<string,int>hash;
void Init()
{
	int i,j;
	hash.clear();
	string s1,s2;
	int t1,t2;
	cnt=0;
	for(i=0;i<=N+1;i++)
	{
		for(j=0;j<=N+1;j++)
			Map[i][j]=INF;
	}
	for(i=1;i<=N;i++)
	{
		cin>>s1>>t1>>s2>>t2;
		if(!hash[s1]) hash[s1]=++cnt;
		if(!hash[s2]) hash[s2]=++cnt;
		if(hash[s1]!=hash[s2])
			Map[hash[s2]][hash[s1]]=t2;
		Map[0][hash[s1]]=t1;
	}
	s1="THE_WINDY";
	if(!hash[s1]) hash[s1]=++cnt;
	Map[0][hash[s1]]=0;
	N++;
}
void dfs(int u)
{
	int i;
	vis[u]=true;
	for(i=0;i<=N;i++)
	{
		if(Map[u][i]<INF&&!vis[i])
			dfs(i);
	}
}
bool connect(int root)//深搜，判断是否存在最小树形图 
{
	int i;
	memset(vis,false,sizeof(vis));
	dfs(root);
	for(i=0;i<=N;i++)
	{
		if(!vis[i]) return false; 
	}
	return true;
}
double Min_Tree(int root)
{
	//判断是否连通
	if(!connect(root)) return -1;

	double ans=0;
	int i,j,k;
	memset(circle,false,sizeof(circle));//如果某点被删掉，那么circle[i]=1 
	while(true)
	{
		for(i=1;i<=N;i++)//求出每个点的最小入边
		{
			if(circle[i]) continue;
			Map[i][i]=INF;
			pre[i]=i;
			for(j=0;j<=N;j++)
			{
				if(circle[j]) continue;
				if(Map[j][i]<Map[pre[i]][i])
					pre[i]=j; 
			}  
		}

		for(i=1;i<=N;i++)//遍历找环
		{
			if(circle[i]) continue;
			j=i;
			memset(vis,false,sizeof(vis));
			while(!vis[j]&&j!=root)
			{
				vis[j]=true;
				j=pre[j]; 
			}
			if(j==root)//j==root表示i不在环上
				continue;
			i=j;//找到了环
			ans+=Map[pre[i]][i];
			for(j=pre[i];j!=i;j=pre[j])
			{
				ans+=Map[pre[j]][j];
				circle[j]=true;//用环上一点i代表此环，其他点删去，即circle[j]=1  
			}
			for(j=0;j<=N;j++)
			{
				if(circle[j]) continue;
				if(Map[j][i]<INF)
					Map[j][i]-=Map[pre[i]][i];//更新j的入边  
			}
			for(j=pre[i];j!=i;j=pre[j])//环上所有点的最优边为人工顶点的边 
			{
				for(k=0;k<=N;k++)
				{
					if(circle[k]) continue;
					if(Map[j][k]<INF)
						Map[i][k]=min(Map[i][k],Map[j][k]);
					if(Map[k][j]<INF)
						Map[k][i]=min(Map[k][i],Map[k][j]-Map[pre[j]][j]);
				}
			}
			break;//注意 
		}
		if(i>N)
		{
			for(j=1;j<=N;j++)
			{
				if(circle[j]) continue;
				ans+=Map[pre[j]][j]; 
			}
			break; 
		} 
	}
	return ans;
}
void Solve()
{
	double ans=Min_Tree(0);
	printf("%.0lf\n",ans);
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