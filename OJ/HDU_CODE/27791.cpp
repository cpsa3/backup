////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2012-03-12 16:07:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2779
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <iostream>
#include <memory.h>
#include <algorithm>
#define max(a,b) (a>b?a:b)
using namespace std;

struct Node
{
    int s,e;
}node[105];
int N,cas;
bool mark[50];
int cmp(const void *p1,const void *p2)
{
    if(((Node *)p1)->e!=((Node *)p2)->e)
        return ((Node *)p1)->e-((Node *)p2)->e;
    return ((Node *)p1)->s-((Node *)p2)->s;
}

void Init()
{
    int i,a,b;
    for(i=1;i<=N;i++)
	{
        scanf("%d%d",&a,&b);
		node[i].s=a<<1;
		node[i].e=b<<1;
	}
    qsort(node+1,N,sizeof(node[0]),cmp);
}
void Solve()
{
    int i,j,ans=0;
    memset(mark,false,sizeof(mark));
	for(i=1;i<=N;i++)
	{
		for(j=node[i].s;j<=node[i].e-1;j++)
		{
			if(mark[j]==false)
			{
				ans++;
				mark[j]=true;
				break;
			}
		}
	}
    printf("On day %d Emma can attend as many as %d parties.\n",cas++,ans);
}
int main()
{
    cas=1;
    while(scanf("%d",&N),N)
    {
        Init();
        Solve();
    }
return 0;
}