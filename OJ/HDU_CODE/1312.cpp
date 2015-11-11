////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-29 22:46:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1312
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include <iostream>
char a[30][30];
int x,y,count=1,w,h;
int dir[4][2]={0,1,0,-1,1,0,-1,0};
void dfs(int x1,int y1,int map[30][30])
{
	int i;
	for(i=0;i<4;i++)
	{
		int a=x1+dir[i][0];
		int b=y1+dir[i][1];
		if(a<1||a>h||b<1||b>w||!map[a][b])
			continue;
		map[a][b]=0;
		{dfs(a,b,map);count++;}
	}
return;
}

main ()
{
	int i,j;
	while(scanf("%d%d\n",&w,&h)!=EOF)
	{
		if(w==0&&h==0)
			break;
		int map[30][30]={0};
		for(i=1;i<=h;i++)
		{
			for(j=1;j<=w;j++)
			{
				scanf("%c",&a[i][j]);
				if(a[i][j]=='.')
					map[i][j]=1;
				if(a[i][j]=='@')
				{x=i;y=j;}	
			}
			getchar();
		}
			count=1;
			dfs(x,y,map);
			printf("%d\n",count);
	}
return 0;
}