////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-20 18:32:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3920
////Problem Title: 
////Run result: Accept
////Run time:890MS
////Run memory:244KB
//////////////////System Comment End//////////////////
/*模拟退火*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <ctime>
#include <cmath>
#define min(a,b) (a<b?a:b)
#define RunN 70
#define RanN 70
#define INF 1e8
using namespace std;
struct Node
{
    int link[25];
    double len;
};
struct Node node[RanN+5];
double X[40],Y[40];
double ox,oy;
double map[40][40];
double dis[40];
double ans;
bool vis[40];
int N,cas;

void adjust(Node &now,int rn)//rn为调整次数  
{  
    int i,u,v;  
    while(rn--)  
    {  
        u=rand()%(2*N)+1;
        v=rand()%(2*N)+1;
        if(u==v||now.link[u]==v) continue;
        int du=now.link[u];
        int dv=now.link[v];
        now.link[u]=v;
        now.link[v]=u;
        now.link[du]=dv;
        now.link[dv]=du;
    } 
    double len=0;
    memset(vis,false,sizeof(vis));
    for(i=1;i<=2*N;i++)
    {
        if(vis[i]) continue;
        v=now.link[i];
        len+=map[i][v];
        len+=min(dis[i],dis[v]);
        vis[i]=vis[v]=true;
    }
    now.len=len;
}  

void get_rnode()//产生RANN组初始数列  
{  
    int i,j;  
    for(i=0;i<RanN;i++)  
    {  
        for(j=1;j<=N;j++)
        {
            node[i].link[j]=j+N;
            node[i].link[j+N]=j;
        }
        adjust(node[i],N-1);//初始调整  
    }  
}  
void Run()
{
    int i,j;
    for(i=1;i<=2*N;i++)
    {
        map[i][i]=0;
        for(j=i+1;j<=2*N;j++)
        {
            map[i][j]=map[j][i]=sqrt((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]));
        }
    }
    for(i=1;i<=2*N;i++)
        dis[i]=sqrt((X[i]-ox)*(X[i]-ox)+(Y[i]-oy)*(Y[i]-oy));
}
void Init()
{
    int i,j;
    scanf("%lf%lf",&ox,&oy);
    scanf("%d",&N);
    for(i=1;i<=2*N;i++)
        scanf("%lf%lf",&X[i],&Y[i]);
    Run();
    get_rnode();
}
void Print()
{
    int i;
    printf("--------------\n");
    for(i=0;i<RanN;i++)
        printf("%.2lf\n",node[i].len);
    printf("--------------\n");
}
void Solve()
{
    int i,j,u,v,t=N-1;
    Node temp;
    //Print();
    while(t--)
    {
        for(i=0;i<RanN;i++)
        {
            for(j=0;j<RunN;j++)
            {
                temp=node[i];
                adjust(temp,t);
                if(temp.len<node[i].len)
                    node[i]=temp;
            }
        }
    }
    double ans=INF;
    for(i=0;i<RanN;i++)
    {
        if(ans>node[i].len)
            ans=node[i].len;
    }
    printf("Case #%d: %.2lf\n",cas++,ans);
}
int main()
{
    int T;
    cas=1;
    srand(time(0));
    scanf("%d",&T);
    while(T--)
    {
        Init();
        Solve();
    }
    return 0;
}