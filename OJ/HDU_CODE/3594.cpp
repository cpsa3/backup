////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-07-08 22:38:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3594
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:1588KB
//////////////////System Comment End//////////////////
/*判断强连通的图中每条边是不是只在一个环内*/
/*
(1):如果有重边则NO

*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 20005
#define INF 1e8
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct edge
{
    int u,v,next;
}E[50006];
int head[MAXN],ecnt;
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];
int Index,scc,top,N,M;
bool Instack[MAXN],ok;
int W[MAXN];
int temp[MAXN],cnt;
int ST[MAXN],Top;
bool vis[MAXN];
void Insert(int u,int v)
{
    E[ecnt].u=u;
    E[ecnt].v=v;
    E[ecnt].next=head[u];
    head[u]=ecnt++;
}
bool Judge(int u,int v)//判重
{
	int i;
	for(i=head[u];i!=-1;i=E[i].next)
	{
		if(E[i].v==v)
		{ok=false;return false;}
	}
	return true;
}
void Init()
{
    int u,v;
	ok=true;
    memset(head,-1,sizeof(head));ecnt=0;
    scanf("%d",&N);
    while(scanf("%d%d",&u,&v)!=EOF)
    {
        if(u==0&&v==0) break;
		if(Judge(u+1,v+1))
			Insert(u+1,v+1);
    }
}

void Run(int u,int v)
{
    int x;
    cnt=0;
    while(true)
    {
        temp[cnt++]=ST[Top--];
        x=temp[cnt-1];
        if(x==v) break;
        W[x]++;
        if(W[x]>1)
        {ok=false;return;}
    }
    while(cnt)
        ST[++Top]=temp[--cnt];  
}
void Tarjan(int u)
{
    int i,v;
    if(!ok) return;
    Low[u]=DFN[u]=++Index;

    Stack[++top]=u;
    ST[++Top]=u;
    vis[u]=true;
    Instack[u]=true;

    for(i=head[u];i!=-1;i=E[i].next)
    {
        v=E[i].v;
        if(!DFN[v])
        {
            Tarjan(v);
            if(Low[u]>Low[v])
                Low[u]=Low[v]; 
        }
        else if(Instack[v]&&Low[u]>DFN[v])
		{Low[u]=DFN[v]; Run(u,v);}
		//if(vis[v]&&Low[u]>DFN[v])
         //   Run(u,v);
    }
    if(Low[u]==DFN[u])
    {
        scc++;
        if(scc>1) {ok=false;return;}
        do{
            v=Stack[top--];
            Instack[v]=false;
            Belong[v]=scc;
        }while(u!=v);
    }
    Top--;
    vis[u]=false;
    return;
}
void Solve()
{
    int i;
    memset(DFN,0,sizeof(DFN));
    memset(Instack,false,sizeof(Instack));
    memset(Low,0,sizeof(Low));
    memset(vis,false,sizeof(vis));
    memset(W,0,sizeof(W));//记录dfs树上每个及其子孙节点连到祖先的边数
    Index=scc=top=Top=0;
    for(i=1;i<=N&&ok;i++)//缩点
    {if(!DFN[i]) Tarjan(i);}
    /*
    for(i=0;i<ecnt;i++)
	printf("#%d %d\n",E[i].u,E[i].v);
    for(i=1;i<=N;i++)
	printf("%d ",W[i]);
    printf("\n");
    */
    if(!ok)
        printf("NO\n");
    else 
		printf("YES\n");
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        Init();
        Solve();
    }
	return 0;
}
/*
5
7
0 1
1 2
2 1
2 3
3 4
4 2
1 5
5 3
3 6
6 1
NO
*/