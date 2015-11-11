////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-11-18 23:24:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2722
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1208KB
//////////////////System Comment End//////////////////
#include <iostream>
const int MAX=500;
const int INF=99999999;
int map[MAX][MAX],path[MAX],N,M,S;
bool hash[MAX];
int Dijkstra()
{
	int i,j;
	path[1]=0;
	for(i=1;i<=S;i++)
	{
		int min=INF,w=-1;
		for(j=1;j<=S;j++)
		{
			if(hash[j]&&path[j]<min)
			{min=path[j];w=j;}
		}
		if(w==-1)
			break;
		hash[w]=false;
		for(j=1;j<=S;j++)
		{
			if(map[w][j]!=INF&&path[j]>path[w]+map[w][j])
				path[j]=path[w]+map[w][j];
		}
	}
	if(path[S]==INF)
		return -1;
	else
		return path[S];
}
main ()
{
	int i,j,v,r;
	char p[3];
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		if(N==0&&M==0)
			break;
		S=(N+1)*(M+1);
		for(i=0;i<MAX;i++)
			for(j=0;j<MAX;j++)
			{
				map[i][j]=INF;
				map[i][i]=0;
				path[i]=INF;
				hash[i]=true;
			}
			//r=1;
			for(i=1;i<=2*N+1;i++)
			{
				if(i%2==1)
				{
					for(j=1;j<=M;j++)
					{
						scanf("%d%s",&v,p);
						if(v==0)
							continue;
						int left=(i/2)*(M+1)+j;
						//int left = (r - 1) * (M+ 1) + j;  
						int right=left+1;
						int t=2520/v;
						if(p[0]=='*')
						{
							map[left][right]=t;
							map[right][left]=t;
						}
						else if(p[0]=='>')
							map[left][right]=t;
						else if(p[0]=='<')
							map[right][left]=t;
					}
					r++;
				}
				else
				{
					for(j=1;j<=M+1;j++)
					{
						scanf("%d%s",&v,p);
						if(v==0)
							continue;
						int down=(i/2)*(M+1)+j;
						//int down = (r - 1) * (M+ 1) + j;   
						int up=down-(M+1);
						int t=2520/v;
						if(p[0]=='*')
						{
							map[up][down]=t;
							map[down][up]=t;
						}
						else if(p[0]=='^')
							map[down][up]=t;
						else if(p[0]=='v')
							map[up][down]=t;
					}
				}
			}
			int ans=Dijkstra();
			if(ans==-1)
				printf("Holiday\n");
			else
				printf("%d blips\n",ans);		
	}
	return 0;
}