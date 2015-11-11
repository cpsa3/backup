////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-08-10 22:26:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3884
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:448KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 10005
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct Node
{
    int x,p;
}node[MAXN];
int N,l,r,mid;
__int64 A[MAXN],B[MAXN];
__int64 K,ans,now;

int cmp(const void *p1,const void *p2)
{
    return ((struct Node *)p1)->x-((struct Node *)p2)->x;
}
void swap(int a,int b)
{
    Node t;
    t=node[a];node[a]=node[b];node[b]=t;
}
void go_r(__int64 &K)//”“±ﬂΩÁœÚ”““∆
{
	__int64 t;
	while(K>=0&&r<=N)
	{
		__int64 d=(node[r].x-node[mid].x);
		if((node[r].p-B[r])*d<=K)
			t=node[r].p-B[r];
		else
			t=K/d;
		if(t==0) break;
		B[r]+=t;
		now+=t;
		K-=t*d;
		if(B[r]==node[r].p)
			r++;
	}
}
void go_mid(__int64 &K)//ª„æ€µ„œÚ”““∆
{
	mid++;
	__int64 d=node[mid].x-node[mid-1].x;
	K+=(A[r-1]-A[mid-1]+B[r])*d;
	K-=(A[mid-1]-A[l-1])*d;
}
void Run(__int64 K)
{
	int i;
	memset(B,0,sizeof(B));
	A[0]=0;
	for(i=1;i<=N;i++)
		A[i]=A[i-1]+node[i].p;
	l=1;mid=1;r=2;
	now=B[1]=A[1];
	go_r(K);
	ans=max(ans,now);
	while(mid<N)
	{
		go_mid(K);
		go_r(K); 
		//◊Û±ﬂΩÁœÚ”““∆
		while((K<0)||(r<=N&&node[mid].x-node[l].x>node[r].x-node[mid].x))
		{
			 l++;
			 K+=B[l-1]*(node[mid].x-node[l-1].x);
			 now-=node[l-1].p; 
			 B[l-1]=0;
			 go_r(K);
		}
		ans=max(ans,now);
	}
}
void Init()
{
    int i;
    for(i=1;i<=N;i++)
        scanf("%d%d",&node[i].x,&node[i].p);
    qsort(node+1,N,sizeof(node[0]),cmp);
}
void Solve()
{
	int i;
    ans=0;
    Run(K);//¥”◊ÛœÚ”“…®√Ë(ºŸ∂®◊Û∂Àµ„ « µµ„)
    for(i=1;i<=N/2;i++)
        swap(i,N+1-i);
    for(i=1;i<=N;i++)
        node[i].x*=-1;
    Run(K);
    printf("%I64d\n",ans);    
}
int main()
{
    while(scanf("%d%I64d",&N,&K)!=EOF)
    {
        Init();
        Solve();
    }
return 0;
}