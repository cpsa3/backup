////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-08-23 12:53:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1495
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1376KB
//////////////////System Comment End//////////////////
/*BFS*/
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <cstdio>
#include <queue>
#define min(a,b) (a<b?a:b)
using namespace std;
struct Node
{
	int s,n,m;
	int step;
	Node(int s1,int n1,int m1,int step1)
	{s=s1;n=n1;m=m1;step=step1;}
	Node(){}
};
int S,N,M;
bool vis[105][105][105];
queue<Node>Q;
bool Judge(int s,int n,int m)
{
	if(s==S/2&&n==S/2) return true;
	if(s==S/2&&m==S/2) return true;
	if(n==S/2&&m==S/2) return true;
	return false;
}
int BFS()
{
	if(S%2) return -1;
	Node u,v;
	int w,s,n,m;
	while(!Q.empty()) Q.pop();
	memset(vis,false,sizeof(vis));
	Q.push(Node(S,0,0,0));
	vis[S][0][0]=true;
	while(!Q.empty())
	{
		
		u=Q.front();Q.pop();
		s=u.s;n=u.n;m=u.m;
		w=min(u.s,N-n);
		if(!vis[u.s-w][u.n+w][u.m])
		{
			vis[u.s-w][u.n+w][u.m]=true;
			Q.push(Node(u.s-w,u.n+w,u.m,u.step+1));
			if(Judge(u.s-w,u.n+w,u.m))
				return u.step+1;
		}
		w=min(s,M-m);
		if(!vis[u.s-w][u.n][u.m+w])
		{
			vis[u.s-w][u.n][u.m+w]=true;
			Q.push(Node(u.s-w,u.n,u.m+w,u.step+1));
			if(Judge(u.s-w,u.n,u.m+w))
				return u.step+1;
		}
		w=min(n,S-s);
		if(!vis[u.s+w][u.n-w][u.m])
		{
			vis[u.s+w][u.n-w][u.m]=true;
			Q.push(Node(u.s+w,u.n-w,u.m,u.step+1));
			if(Judge(u.s+w,u.n-w,u.m))
				return u.step+1;
		}
		w=min(n,M-m);
		if(!vis[u.s][u.n-w][u.m+w])
		{
			vis[u.s][u.n-w][u.m+w]=true;
			Q.push(Node(u.s,u.n-w,u.m+w,u.step+1));
			if(Judge(u.s,u.n-w,u.m+w))
				return u.step+1;
		}
		w=min(m,S-s);
		if(!vis[u.s+w][u.n][u.m-w])
		{
			vis[u.s+w][u.n][u.m-w]=true;
			Q.push(Node(u.s+w,u.n,u.m-w,u.step+1));
			if(Judge(u.s+w,u.n,u.m-w))
				return u.step+1;
		}
		w=min(m,N-n);
		if(!vis[u.s][u.n+w][u.m-w])
		{
			vis[u.s][u.n+w][u.m-w]=true;
			Q.push(Node(u.s,u.n+w,u.m-w,u.step+1));
			if(Judge(u.s,u.n+w,u.m-w))
				return u.step+1;
		}
	}
	return -1;
}
int main()
{
	while(scanf("%d%d%d",&S,&N,&M)!=EOF)
	{
		if(S==0&&N==0&&M==0) break;
		int ans=BFS();
		if(ans==-1) printf("NO\n");
		else
			printf("%d\n",ans);
	}
return 0;
}