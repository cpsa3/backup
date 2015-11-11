////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-10-17 22:45:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1045
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
char g[5][5];
int n,count=0;
int panduan(int x,int y)
{
	int i;
	for(i=1;;i++)//向上
	{
		if(x-i<1||g[x-i][y]=='X')
			break;
		if(g[x-i][y]=='W')
			return 0;
	}
	for(i=1;;i++)//向下
	{
		if(x+i>n||g[x+i][y]=='X')
			break;
		if(g[x+i][y]=='W')
			return 0;
	}
	for(i=1;;i++)//向左
	{
		if(y-i<1||g[x][y-i]=='X')
			break;
		if(g[x][y-i]=='W')
			return 0;
	}
	for(i=1;;i++)//向右
	{
		if(y+i>n||g[x][y+i]=='X')
			break;
		if(g[x][y+i]=='W')
			return 0;
	}
	return 1;
}
void dfs(int x,int y,int k)
{
	if(x==n+1)
	{
		if(k>count)
			count=k;
		return; 
	}
	if(g[x][y]=='.'&&panduan(x,y))
	{
		g[x][y]='W';
		if(y==n)
			dfs(x+1,1,k+1);
		else
			dfs(x,y+1,k+1);
		g[x][y]='.';
	}
	if(y==n)
		dfs(x+1,1,k);
	else
		dfs(x,y+1,k);
	return ;
}
main ()
{
	int i,j;
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		if(n==0)
			break;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				scanf("%c",&g[i][j]);
			getchar();
		}	
		count=0;
		dfs(1,1,0);
		printf("%d\n",count);
	}
	return 0;
}