////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-21 22:27:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3920
////Problem Title: 
////Run result: Accept
////Run time:531MS
////Run memory:17924KB
//////////////////System Comment End//////////////////
/*状态压缩DP*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <queue>
#include <cmath>
#define MAXN 2000000
#define INF 1e8
#define min(a,b) (a<b?a:b)
#define GOAL ((1<<(2*N))-1)
using namespace std;
int N,cas;
double X[30],Y[30];
double map[30][30];
double dis[30]; 
double ox,oy;
double dp[MAXN];
bool vis[MAXN];
int base[30];
void get_base()
{
    int i;
    base[0]=1;
    for(i=1;i<30;i++)
        base[i]=base[i-1]<<1;
}
void Run()
{
    int i,j;
    for(i=0;i<2*N;i++)
    {
        map[i][i]=0;
        for(j=i+1;j<2*N;j++)
        {
            map[i][j]=map[j][i]=sqrt((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]));
        }
    }
    for(i=0;i<2*N;i++)
        dis[i]=sqrt((X[i]-ox)*(X[i]-ox)+(Y[i]-oy)*(Y[i]-oy));
    for(i=0;i<MAXN;i++)
        dp[i]=INF;
    dp[0]=0;
}
void Init()
{
    int i;
    scanf("%lf%lf",&ox,&oy);
    scanf("%d",&N);
    for(i=0;i<2*N;i++)
        scanf("%lf%lf",&X[i],&Y[i]);
    Run();
}
//类似SPFA
queue<int>Q; 
double BFS()
{
    int i,u,pos,state;
    double d;
	memset(vis,false,sizeof(vis));
    while(!Q.empty()) Q.pop();
    Q.push(0);
	vis[0]=true;
    while(!Q.empty())
    {
        
        u=Q.front();Q.pop();
		vis[u]=false;
		pos=2*N;
        for(i=0;i<2*N;i++)//先找到第一个为零的点，并固定下来
        {
            if((u&base[i])==0) 
            {pos=i;break;}
        }
        for(i=pos+1;i<2*N;i++)//然后O(N)扫描
        {
            if((u&base[i])==0) 
            {
                d=dp[u]+map[pos][i]+min(dis[i],dis[pos]);
                state=((u|base[pos])|base[i]);
                if(dp[state]>d)
                {
                    dp[state]=d;
					if(!vis[state])
					{
						vis[state]=true;
						Q.push(state);
					}
                }   
            }
            
        }
    }
    return dp[GOAL];
}
void Print()
{
    int i;
    printf("%d\n",GOAL);
    for(i=0;i<2*N;i++)
        printf("%.2lf ",dis[i]);
    printf("\n");
}
void Solve()
{
    //Print();
    double ans=BFS();
	printf("Case #%d: %.2lf\n",cas++,ans);
}
int main()
{
    int T;
    cas=1;
	get_base();
    scanf("%d",&T);
    while(T--)
    {
        Init();
        Solve();
    }
	return 0;
}