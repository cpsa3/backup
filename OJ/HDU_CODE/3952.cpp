////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-19 01:05:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3952
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:220KB
//////////////////System Comment End//////////////////
/*暴力枚举*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cmath>
#define INF 1e8
#define eps 1e-5
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
struct Point
{
    int x,y;
};
struct Fruit
{
    int m;
    Point P[20];
}F[20];
int N,ans,cas;
void Init()
{
    int i,j;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
        scanf("%d",&F[i].m);
        for(j=1;j<=F[i].m;j++)
            scanf("%d%d",&F[i].P[j].x,&F[i].P[j].y);
    }
}


int Cmp(double x)//判断符号
{
    if(fabs(x)<eps)
        return 0;
    return x>0?1:-1; 
}

double Cross(Point s,Point e,Point o)////叉乘
{
    return (s.x-o.x)*(e.y-o.y)-(s.y-o.y)*(e.x-o.x);
}

bool Equal(Point a,Point b)//判断两个端点pa,pb是否重合
{return (a.x==b.x&&a.y==b.y);}

//判断线段l的两个端点l.s,l.e是否在线段a-b两侧
bool Same_side(Point a,Point b,Point s,Point e)//小于0表示异侧，大于0表示同侧
{
    if(Cmp(Cross(a,b,s))*Cmp(Cross(a,b,e))<=eps)
        return true;
    return false;
}
int fuck(Point s,Point e)
{
    int i,j,res=0;
    for(i=1;i<=N;i++)
    {
        bool ok=false;
        for(j=1;j<=F[i].m-1;j++)
        {
            if(Same_side(s,e,F[i].P[j],F[i].P[j+1]))
            {ok=true;break;}
        }
        if(Same_side(s,e,F[i].P[j],F[i].P[1]))
            ok=true;
        res+=ok;
    }
    ans=max(ans,res);
    return res;
}
void Run(int a,int b)
{
    int i,j;
    for(i=1;i<=F[a].m;i++)
    {
        for(j=1;j<=F[b].m;j++)
        {
            fuck(F[a].P[i],F[b].P[j]);
        }
    }
}
void Solve()
{
    int i,j,k,l;
    ans=1;
    if(N==1) {printf("Case %d: %d\n",cas++,1);return;}
    for(i=1;i<=N;i++)
    {
        for(j=i+1;j<=N;j++)
        {
            Run(i,j);
        }
    }
    //int temp=fuck(F[1].P[3],F[2].P[2]);
    //printf("*%d\n");
    printf("Case %d: %d\n",cas++,ans);
}
int main()
{
    int T;
    cas=1;
    scanf("%d",&T);
    while(T--)
    {
        Init();
        Solve();
    }
return 0;
}