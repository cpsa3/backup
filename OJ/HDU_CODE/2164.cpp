////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-12-30 08:57:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2164
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <iostream>
int judge(char a,char b)
{
	if(a=='R')
	{
		if(b=='R')
			return 0;
		else if(b=='S')
			return 1;
		return -1;
	}
	else if(a=='S')
	{
		if(b=='R')
			return -1;
		else if(b=='S')
			return 0;
		return 1;
	}
	else
	{
		if(b=='R')
			return 1;
		else if(b=='S')
			return -1;
		return 0;
	}
}
int main()
{
	int T,i,N;
	char a[2],b[2];
	scanf("%d",&T);
	while(T--)
	{
		int flag=0;
		scanf("%d",&N);
		for(i=1;i<=N;i++)
		{
			scanf("%s%s",a,b);
			flag+=judge(a[0],b[0]);
		}
		if(flag>0)
			printf("Player 1\n");
		else if(flag<0)
			printf("Player 2\n");
		else
			printf("TIE\n");
	}
return 0;
}