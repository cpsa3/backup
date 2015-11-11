////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-05-01 19:50:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1350
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:488KB
//////////////////System Comment End//////////////////
/*最小路径覆盖*/
/*有向无环图*/
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#define MAXN 505
using namespace std;
bool map[MAXN][MAXN];
bool flag[MAXN];
int result[MAXN];
struct px
{
	int x1,y1,x2,y2,s,e;
};
struct px P[MAXN];
int M;
int Find(int a)
{
	int i;
	for(i=1;i<=M;i++)
	{
		if(map[a][i]&&!flag[i])
		{
			flag[i]=true;
			if(result[i]==0||Find(result[i]))
			{
				result[i]=a;
				return 1;
			}
		}
	}
	return 0;
}
int MaxMatch()
{
	int ans=0,i;
	memset(result,0,sizeof(result));//忘记初始WA好几次！！！
	for(i=1;i<=M;i++)
	{
		memset(flag,false,sizeof(flag));
		ans+=Find(i);
	}
	return ans;
}
void Build()
{
	memset(map,false,sizeof(map));
	int i,j,k;
	for(i=1;i<=M;i++)
	{
		for(j=1;j<=M;j++)
		{
			if(i!=j&&(P[i].e+abs(P[j].x1-P[i].x2)+abs(P[j].y1-P[i].y2))<P[j].s)
				map[i][j]=true;
			//if(P[i].e>=P[j].s)
			//	break;
		}
	}
}
int main()
{
	int T,i,j,h,m;
	char ss[10];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&M);
		for(i=1;i<=M;i++)
		{
			scanf("%s",ss);
            sscanf(ss,"%d%*[:]%d",&h,&m);
			scanf("%d%d%d%d",&P[i].x1,&P[i].y1,&P[i].x2,&P[i].y2);
			P[i].s=h*60+m;
			P[i].e=P[i].s+abs(P[i].x1-P[i].x2)+abs(P[i].y1-P[i].y2);
			//printf("**%d %d\n",P[i].h,P[i].m);
		}
		Build();
		printf("%d\n",M-MaxMatch());
	}
return 0;
}

