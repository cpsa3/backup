////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-13 13:28:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1856
////Problem Title: 
////Run result: Accept
////Run time:234MS
////Run memory:78568KB
//////////////////System Comment End//////////////////
#include <iostream>
int p[10000001],w[10000001],max;
int find_set(int x)
{
	if(x!=p[x])
		p[x]=find_set(p[x]);
	return p[x];
}

void bin(int x,int y)
{
	int a=find_set(x);
	int b=find_set(y);
	if(a!=b)
	{
		p[a]=b;
		w[b]+=w[a];
		w[a]=0;
		if(w[b]>max)
			max=w[b];
	}
}

main ()
{
	int n,x,y,i;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
		{printf("1\n");continue;}
		for(i=1;i<=10000000;i++)
		{
			p[i]=i;
			w[i]=1;
		}
		max=1;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&x,&y);
			bin(x,y);
		}
		printf("%d\n",max);
	}
return 0;
}
