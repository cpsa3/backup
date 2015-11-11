////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-08-21 22:23:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3920
////Problem Title: 
////Run result: Accept
////Run time:546MS
////Run memory:18004KB
//////////////////System Comment End//////////////////
/*×´Ì¬Ñ¹ËõDP*/
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
struct Node
{
    int state;
    double dis;
    Node(int state1,double dis1)
    {state=state1;dis=dis1;}
    Node(){}
};
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
queue<Node>Q;
double BFS()
{
    int i,j,pos,state;
    double d;
    Node u,v;
	memset(vis,false,sizeof(vis));
    while(!Q.empty()) Q.pop();
    Q.push(Node(0,0));
	vis[0]=true;
    while(!Q.empty())
    {
        
        u=Q.front();Q.pop();
		vis[u.state]=false;
		pos=2*N;
        for(i=0;i<2*N;i++)
        {
            if((u.state&base[i])==0) 
            {pos=i;break;}
        }
        //printf("*%d\n",pos);
        for(i=pos+1;i<2*N;i++)
        {
            if((u.state&base[i])==0) 
            {
                d=dp[u.state]+map[pos][i]+min(dis[i],dis[pos]);
                state=((u.state|base[pos])|base[i]);
                if(dp[state]>d)
                {
                    dp[state]=d;
					//printf("^^%d %d %d %.3lf \n",pos,i,state,dp[state]);
					if(!vis[state])
					{
						vis[state]=true;
						Q.push(Node(state,d));
					}
                }   
            }
            
        }
    }
    //printf("%d %.2lf\n",GOAL,dp[3]);
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
    //printf("*\n");
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