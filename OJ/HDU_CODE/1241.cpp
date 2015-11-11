////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-22 14:30:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1241
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:272KB
//////////////////System Comment End//////////////////
#include <iostream>
char a[101][101];
int n,m,count,dir[8][2]={0,1,0,-1,1,0,-1,0,1,1,1,-1,-1,-1,-1,1};
void dfs(int x,int y)
{
	int i;
	for(i=0;i<8;i++)
	{
		int dx=x+dir[i][0];
		int dy=y+dir[i][1];
		if(dx>=0&&dx<m&&dy>=0&&dy<n&&a[dx][dy]=='@')
		{
			a[dx][dy]='*';
			dfs(dx,dy);
		}
	}
return;
}
main ()
{
	int i,j;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		getchar();
		if(m==0)
			break;
		for(i=0;i<m;i++)
			scanf("%s",a[i]);
		count=0;
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
			{
				if(a[i][j]=='@')
				{count++;a[i][j]='*';dfs(i,j);}
			}
			printf("%d\n",count);
	}
return 0;
}