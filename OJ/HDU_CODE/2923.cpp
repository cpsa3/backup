////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-11-19 23:34:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2923
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:288KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
const int MAX=110;
const int INF=99999999;
int map[MAX][MAX],path[MAX],N,C,R,n,r[1005];
bool hash[MAX];
char a[105][20];
int find(char t[20])
{
	int i;
	for(i=1;i<=n;i++)
		if(!strcmp(a[i],t))
			break;
		if(i<=n)
			return i;
		else
		{
			n++;
			strcpy(a[n],t);
			return n;
		}
}
void Dijkstra(int s,int e)
{
	int i,j;
	for(i=0;i<=N;i++)
	{
		path[i]=INF;
		hash[i]=true;
	}
	path[s]=0;
	for(i=1;i<=N;i++)
	{
		int min=INF,w=-1;
		for(j=1;j<=N;j++)
		{
			if(hash[j]&&min>path[j])
			{min=path[j];w=j;}
		}
		if(w==-1)
			break;
		hash[w]=false;
		for(j=1;j<=N;j++)
		{
			if(map[w][j]!=INF&&path[j]>path[w]+map[w][j])
				path[j]=path[w]+map[w][j];
		}
	}
}
/*void Floyd()
{
	int i,j,k;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
		{
			if(map[i][k]==INF)
				continue;
			for(j=1;j<=n;j++)
			{
				if(map[k][j]==INF)
					continue;
				if(map[i][j]>map[i][k]+map[k][j])
					map[i][j]=map[i][k]+map[k][j];
			}
		}
}*/
main ()
{
	int i,j,cas=1,w,s1,h1,h2;
	char temp[20],t1[20],t2[20],p[20];
	while(scanf("%d%d%d",&N,&C,&R)!=EOF)
	{
		if(N==0&&C==0&&R==0)
			break;
		memset(a,0,sizeof(a));
		for(i=0;i<=N;i++)
			for(j=0;j<=N;j++)
			{
				map[i][j]=INF;
				map[i][i]=0;//一定要加，不然WA
				path[i]=INF;
				hash[i]=true;
			}
			n=0;
			scanf("%s",temp);
			w=find(temp);
			for(i=1;i<=C;i++)
			{
				scanf("%s",temp);
				r[i]=find(temp);
			}
			for(i=1;i<=R;i++)
			{
				scanf("%s%s%s",t1,p,t2);
				h1=find(t1);
				h2=find(t2);
				sscanf(p+2,"%d",&s1);//数据输入
				if(p[0]=='<')
				{
					if(map[h2][h1]>s1)
						map[h2][h1]=s1;
				}
				if(p[strlen(p)-1]=='>')
				{
					if(map[h1][h2]>s1)
						map[h1][h2]=s1;
				}
			}
			Dijkstra(1,N);
			__int64 ans=0;
			for(i=1;i<=C;i++)
				ans+=path[r[i]];
			for(i=1;i<=C;i++)
			{
				Dijkstra(r[i],1);
				ans+=path[1];
			}
			/*Floyd();
			__int64 ans=0;
			for(i=1;i<=C;i++)
				ans+=(map[1][r[i]]+map[r[i]][1]);*/
			printf("%d. %I64d\n",cas++,ans);
	}
	return 0;
}
/*
4 2 5
NewTroy Midvale Metrodale
NewTroy <-20-> Midvale
Midvale --50-> Bakerline
NewTroy <-5-- Bakerline
Metrodale <-30-> NewTroy
Metrodale --5-> Bakerline


1. 80

3 2 3
a b c
a <-10-> b
a <-10-> c
b <-10-> c

40
*/