////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-11-29 22:30:04
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1872
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:324KB
//////////////////System Comment End//////////////////



#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cstdlib>
using namespace std;

struct Node
{
	char s[100];
	int id,w;
}node[500],node1[500];
int N;
int cmp(const void *p1,const void *p2)
{
	if(((struct Node *)p1)->w!=((struct Node *)p2)->w)
		return ((struct Node *)p2)->w-((struct Node *)p1)->w;
	return ((struct Node *)p1)->id-((struct Node *)p2)->id;
}
void Init()
{
	int i;
	for(i=1;i<=N;i++)
	{
		scanf("%s%d",node[i].s,&node[i].w);
		node[i].id=i;
	}
	qsort(node+1,N,sizeof(node[0]),cmp);
	for(i=1;i<=N;i++)
	{
		scanf("%s%d",node1[i].s,&node1[i].w);
	}
}
void Solve()
{
	int i;
	int ok1,ok2;
	ok1=ok2=1;
	for(i=1;i<=N;i++)
	{
		if(node1[i].w!=node[i].w)
		{
			ok1=0;
			break;
		}
	}
	for(i=1;i<=N;i++)
	{
		if(node1[i].w!=node[i].w||strcmp(node1[i].s,node[i].s))
		{
			ok2=0;
			break;
		}
	}
	if(!ok1)
	{
		printf("Error\n");
		for(i=1;i<=N;i++)
			printf("%s %d\n",node[i].s,node[i].w);
		return ;
	}
	if(!ok2)
	{
		printf("Not Stable\n");
		for(i=1;i<=N;i++)
			printf("%s %d\n",node[i].s,node[i].w);
		return ;
	}
	printf("Right\n");
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