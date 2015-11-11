////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-13 10:54:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1213
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
int p[1001],k;
int find_set(int x)
{
	if(x!=p[x])
		p[x]=find_set(p[x]);
	return p[x];
}

void bin(int x,int y)
{
	int fx=find_set(x);
	int fy=find_set(y);
	if(fx!=fy)
	p[fx]=fy;
}
main ()
{
	int t,n,m,x,y,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		k=0;
		for(i=0;i<=n;i++)
		{
			p[i]=i;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			bin(x,y);
		}
		for(i=1;i<=n;i++)
		{
			if(p[i]==i)
				k++;
		}
		printf("%d\n",k);
	}
return 0;
}