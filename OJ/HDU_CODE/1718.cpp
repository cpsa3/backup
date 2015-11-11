////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-04-11 19:26:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1718
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Node
{
	int id,hp,rank;
}node[1005];
int id,num;
int cmp(const void *p1,const void *p2)
{
	return ((struct Node *)p2)->hp-((struct Node *)p1)->hp;
}
int main()
{
	int i;
	while(scanf("%d",&id)!=EOF)
	{
		num=0;
		while(1)
		{
			scanf("%d%d",&node[num].id,&node[num].hp);
			if(node[num].id==0&&node[num].hp==0) break;
			num++;
		}
		qsort(node,num,sizeof(node[0]),cmp);
		node[0].rank=1;
		if(node[0].id==id) {printf("1\n");continue;}
		for(i=1;i<num;i++)
		{
			if(node[i].hp==node[i-1].hp)
				node[i].rank=node[i-1].rank;
			else
				node[i].rank=i+1;
			if(node[i].id==id)
				break;
		}
		printf("%d\n",node[i].rank);
	}
return 0;
}