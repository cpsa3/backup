////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-24 00:50:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2977
////Problem Title: 
////Run result: Accept
////Run time:265MS
////Run memory:17260KB
//////////////////System Comment End//////////////////
/*BFS+预处理*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <set>
#include <iterator>
#define MAXN 50//预处理的层数
using namespace std;
struct Node
{
	int map[4][4];
	int step,state; 
};
struct st
{
	int A[5];
	bool operator<(const st &rhs)const 
	{
		int i;
		for(i=1;i<=4;i++)
		{
			if(A[i]<rhs.A[i]) return true;
			if(A[i]>rhs.A[i]) return false; 
		}
		return false;
	}
};
set<st>hash[MAXN];
set<st>::iterator it;
int W[5],M,cas,head,tail;
int dir[4][2]={0,1,0,-1,1,0,-1,0};
bool vis[2000000];
int base[13];
Node Q[2000000];
void get_base()
{
	int i;
	base[1]=1;
	for(i=2;i<=11;i++)
		base[i]=base[i-1]*5;
}
bool Judge(int map[4][4],int x,int y,int k)
{
	if(k==1) return true; 
	int i,t[5]={0}; 
	for(i=0;i<4;i++) 
	{ 
	 	int dx=x+dir[i][0];
	 	int dy=y+dir[i][1];
	 	if(dx>=1&&dx<=3&&dy>=1&&dy<=3)
	 		t[map[dx][dy]]++; 
	} 
	if(k==2)
		return t[1]>0;
	if(k==3)
		return t[1]>0&&t[2]>0;
	else
		return t[1]>0&&t[2]>0&&t[3]>0;
}
void Run(int map[4][4],st &next)
{
	int i,j;
	memset(next.A,0,sizeof(next.A));
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
			next.A[map[i][j]]++;
	}
}
void Go()
{
	st now,next;
	Node u,v;
	int i,j,k,t,state;
	for(i=0;i<MAXN;i++)
		hash[i].clear();
	head=tail=0;
	memset(vis,false,sizeof(vis));
	
	memset(u.map,0,sizeof(u.map));u.step=0;u.state=0;
	Q[head++]=u;

	memset(now.A,0,sizeof(now.A));
	hash[0].insert(now);

	vis[0]=true;
	while(head!=tail)
	{
		u=Q[tail++];
		if(u.step==MAXN-3) return;
		u.step++;
		int step=u.step;
		for(i=1;i<=3;i++)
		{
			for(j=1;j<=3;j++)
			{
				int ith=(i-1)*3+j;
				for(k=1;k<=4;k++)
				{
					if(u.map[i][j]==k) continue;
					state=u.state+(k-u.map[i][j])*base[ith];
					if(Judge(u.map,i,j,k)&&!vis[state])
					{
						//t=u.map[i][j];
						vis[state]=true;
						v=u;
						v.map[i][j]=k;
						v.state=state;
						Q[head++]=v;
						Run(v.map,next);
						if(hash[step].find(next)==hash[step].end())
							hash[step].insert(next);
					}
				}
			}
		}
	}
}
void Print()
{
	int i;
	st now;
	for(it=hash[3].begin();it!=hash[3].end();it++)
	{
		now=(*it);
		printf("*%d %d %d %d \n",now.A[1],now.A[2],now.A[3],now.A[4]); 
	}
	printf("*****\n");
}
int fuck()
{
	int i,j,temp;
	st now;
	bool ok=false;
	for(i=1;i<MAXN-4&&!ok;i++)
	{
		for(it=hash[i].begin();it!=hash[i].end();it++)
		{
			now=(*it);
			temp=0;
			for(j=1;j<=4;j++)
				temp+=W[j]*now.A[j];
			if(temp>=M)
			{ok=true;break;}
		}
	}
	if(!ok) return -1;
	return i-1;
}
void Solve()
{
	printf("Case %d: ",cas++);
	if(M==0) {printf("0\n");return;}
	int ans=fuck();
	if(ans==-1)
		printf("Impossible\n");
	else
		printf("%d\n",ans);
}
int main()
{
	int i;
	cas=1;
	get_base();
	Go();//预处理
	//Print();
	while(scanf("%d",&W[1]),W[1])
	{
		for(i=2;i<=4;i++)
			scanf("%d",&W[i]);
		scanf("%d",&M);
		Solve();
	}
return 0;
}
