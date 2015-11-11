////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-11-01 18:10:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1978
////Problem Title: 
////Run result: Accept
////Run time:250MS
////Run memory:288KB
//////////////////System Comment End//////////////////
#include <iostream>
int map[101][101],ans[101][101],n,m;
int dfs(int x,int y)
{
	int i,j;
	if(x==n&&y==m) return 1;
	if(ans[x][y]!=-1) return ans[x][y];
	int num=0;
	for(i=0;i<=map[x][y];i++)
		for(j=0;j+i<=map[x][y];j++)
		{
			if(!(i==0&&j==0)&&x+i<=n&&y+j<=m)
					num=(num+dfs(x+i,y+j))%10000;
		}
		ans[x][y]=num;
		return num;
}
main ()
{
	int T,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				scanf("%d",&map[i][j]);
			memset(ans,-1,sizeof(ans));//≥ı ºªØ
			printf("%d\n",dfs(1,1));
	}
	return 0;
}