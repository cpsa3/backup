////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-05-08 22:59:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1829
////Problem Title: 
////Run result: Accept
////Run time:375MS
////Run memory:236KB
//////////////////System Comment End//////////////////
/*≤¢≤ÈºØ*/
#include <iostream>
#define MAXN 2005
int p[MAXN],d[MAXN];
int N,M;
int find_set(int x)
{
	if(x!=p[x])
		p[x]=find_set(p[x]);
	return p[x]; 
}
int main()
{
	int T,i,x,y,cas=1;
	scanf("%d",&T);
	while(T--)
	{
		bool flag=false;
		scanf("%d%d",&N,&M);
		for(i=1;i<=N;i++)
		{
			p[i]=i;
			d[i]=0; 
		}
		while(M--)
		{
			scanf("%d%d",&x,&y);
			if(flag) continue;
			int dx=find_set(x);
			int dy=find_set(y);
			if(dx==dy) flag=true;
			if(d[x])
				p[dy]=find_set(d[x]);
			d[x]=y;
			if(d[y])
				p[dx]=find_set(d[y]);
			d[y]=x;  
		} 
		printf("Scenario #%d:\n",cas++);
		if(flag)
			printf("Suspicious bugs found!\n\n");
		else
			printf("No suspicious bugs found!\n\n");
	}
	return 0;
}
