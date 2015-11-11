////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-11-28 21:32:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1301
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:276KB
//////////////////System Comment End//////////////////

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <cmath>
#include <cstdlib>
#define MAXN 1005
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define INF (1<<30)
using namespace std;

struct edge
{
	int u,v,w;
}E[MAXN];
int N,M;
int p[30];
char s[2];
int cmp(const void *p1,const void *p2)
{
	return ((struct edge *)p1)->w-((struct edge *)p2)->w;
}
int find_set(int x)
{
	if(p[x]!=x)
		p[x]=find_set(p[x]);
	return p[x];
}
void Init()
{
	int i,j,d,m;
	M=0;
	for(i=1;i<N;i++)
	{
		scanf("%s%d",s,&m);
		for(j=1;j<=m;j++)
		{
			scanf("%s%d",s,&d);
			M++;
			E[M].u=i;
			E[M].v=s[0]-'A'+1;
			E[M].w=d;
		}
	}
	qsort(E+1,M,sizeof(E[0]),cmp);
}
double Kruscal()
{
	int i,j,x,y;
	for(i=1;i<=N;i++)
		p[i]=i;
	int ans=0,n=0;
	for(i=1;i<=M;i++)
	{
		x=E[i].u;
		y=E[i].v;
		int dx=find_set(x);
		int dy=find_set(y);
		if(dx!=dy)
		{
			ans+=E[i].w;
			n++;
			p[dx]=dy;
			if(n==N-1) break;
		}
	}
	return ans;
}
void Solve()
{
	int ans=Kruscal();
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