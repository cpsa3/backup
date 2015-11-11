////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2010-10-06 13:22:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1010
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <math.h>
#include <stdlib.h>
int N,M,T,sx,sy,flag=0,map[9][9],ex,ey;
char a[9][9];
int dir[4][2]={-1,0,1,0,0,-1,0,1};
void dfs(int sum,int x,int y)
{
	int i;
	if(flag==1||sum>T)//��֦1��sum>T��û�ҵ�
		return; 
	if(T<sum+abs(x-ex)+abs(y-ey))//��֦2������Ҫ�Ĳ����������ϵ���̾��뻹С
		return;
	if((T-(sum+abs(x-ex)+abs(y-ey)))%2!=0)//��֦3��(��ż��֦)�������ϵ���̾��������ı���ż��
		return;
	if(sum==T&&a[x][y]=='D')
	{flag=1;return;}
	for(i=0;i<4;i++)
	{
		int dx=x+dir[i][0];
		int dy=y+dir[i][1];
		if(dx<=0||dx>N||dy<=0||dy>M||map[dx][dy]==0)
			continue;
		map[dx][dy]=0;
		dfs(sum+1,dx,dy);
		map[dx][dy]=1;
	}
return; 
}

main ()
{
	int i,j;
	while(scanf("%d%d%d",&N,&M,&T)!=EOF)
	{
		getchar();
		if(N==0&&M==0&&T==0)
			break;
		int sum=0;
		for(i=1;i<=N;i++)
		{
			for(j=1;j<=M;j++)
			{
				scanf("%c",&a[i][j]);
				if(a[i][j]=='S')
				{sx=i;sy=j;map[i][j]=0;continue;}
				if(a[i][j]=='.')
				{map[i][j]=1;sum++;continue;}
				if(a[i][j]=='D')
				{ex=i;ey=j;map[i][j]=1;sum++;continue;}
				if(a[i][j]=='X')
				{map[i][j]=0;continue;}
			}
			getchar();	
		}
		if(sum<T)//·����֦
		{printf("NO\n");continue;}
		flag=0;
		dfs(0,sx,sy);
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
return 0;	
}