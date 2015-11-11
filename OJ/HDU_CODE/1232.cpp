////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-10-12 14:59:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1232
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <iostream>
struct px
{
	int a,b;
};
int p[1000];//储存其父节点
struct px stu[1000000];
int find_set(int x)
{
	if(x!=p[x])
		p[x]=find_set(p[x]);
	return p[x];
}
main ()
{
	int n,m,i;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		scanf("%d",&m);
		for(i=1;i<=m;i++)
			scanf("%d%d",&stu[i].a,&stu[i].b);
		for(i=0;i<1000;i++)
			p[i]=i;//初始化
		int x,y,k=0;
		for(i=1;i<=m;i++)
		{
			x=find_set(stu[i].a);
			y=find_set(stu[i].b);
			if(x!=y)
			{
				k++;
				if(k==n-1)
					break;
				p[x]=y;
			}
		}
		printf("%d\n",n-1-k);
	}
return 0;
}