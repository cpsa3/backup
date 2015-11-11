////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-09-02 12:18:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1175
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:5968KB
//////////////////System Comment End//////////////////
/*BFS*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 1005
#define min(a,b) (a<b?a:b)
using namespace std;
struct Node
{
    int x,y,num,d;
    Node(int x1,int y1,int num1,int d1)
    {x=x1;y=y1;num=num1;d=d1;}
    Node(){}
};
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int map[MAXN][MAXN];
bool vis[MAXN][MAXN];
Node Q[6000000];
int N,M,Head,Tail,K;
void Init()
{
    int i,j;
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
            scanf("%d",&map[i][j]);
    }
    scanf("%d",&K);
}
bool Judge(int x,int y)
{
    if(x>=1&&x<=M&&y>=1&&y<=M)
        return true;
    return false;
}
int BFS(int sx,int sy,int ex,int ey)
{
    int i,t;
    Node u;
    if((map[sx][sy]!=map[ex][ey])||map[sx][sy]==0) return -1;
    t=map[ex][ey];map[ex][ey]=0;
    memset(vis,false,sizeof(vis));
    Head=Tail=0;
    Q[Head++]=Node(sx,sy,0,-1);
    vis[sx][sy]=true;
    while(Head!=Tail)
    {
        u=Q[Tail++];
        if(u.x==ex&&u.y==ey) {map[ex][ey]=t;return 1;}
        for(i=0;i<4;i++)
        {
            int dx=u.x+dir[i][0];
            int dy=u.y+dir[i][1];
            if(Judge(dx,dy)&&!vis[dx][dy]&&!map[dx][dy])
            {
                if(u.d==-1||u.d==i)
                {
                    vis[dx][dy]=true;
                    Q[Head++]=Node(dx,dy,u.num,i);
                }
                else if(u.num!=2)
                {
                    vis[dx][dy]=true;
                    Q[Head++]=Node(dx,dy,u.num+1,i);
                }
            }
        }
    }
    map[ex][ey]=t;
    return -1;
}
void Solve()
{
    int x1,y1,x2,y2;
    while(K--)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        int ans=BFS(x1,y1,x2,y2);
        if(ans==-1) printf("NO\n");
        else printf("YES\n");
    }
}
int main()
{
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        if(N==0&&M==0) break;
        Init();
        Solve();
    }
return 0;
}