////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-04-11 21:15:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1051
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:268KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;
struct Node
{
	int l,w;
	bool ok;
}node[5005];
int N,num;
int cmp(const void *p1,const void *p2)
{
	if(((struct Node *)p1)->l!=((struct Node *)p2)->l)
		return ((struct Node *)p1)->l-((struct Node *)p2)->l;
	return ((struct Node *)p1)->w-((struct Node *)p2)->w;
}
int main()
{
	int T,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(i=1;i<=N;i++)
		{
			scanf("%d%d",&node[i].l,&node[i].w);
			node[i].ok=false;
		}
		qsort(node+1,N,sizeof(node[0]),cmp);
		//for(i=1;i<=N;i++)
		//	printf("%d %d\n",node[i].l,node[i].w);
		num=0;
		Node p;
		for(i=1;i<=N;i++)
		{
			if(node[i].ok==false)
			{
				node[i].ok=true;
				num++;//printf("*%d\n",i);
				p=node[i];
				for(j=i+1;j<=N;j++)
				{
					if(node[j].ok==false&&node[j].l>=p.l&&node[j].w>=p.w)
					{node[j].ok=true;p=node[j];}
				}
			}
		}
		printf("%d\n",num);
	}
return 0;
}