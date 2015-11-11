////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-08-30 00:05:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1242
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:328KB
//////////////////System Comment End//////////////////
/*BFS*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 207
using namespace std;
struct Node
{
    int x,y,step;
    Node(int x1,int y1,int step1)
    {x=x1;y=y1;step=step1;}
    Node(){}
};
char map[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dir[4][2]={0,1,0,-1,1,0,-1,0};
Node Q[2000000];
int Head,Tail;
int N,M;
void Init()
{
    int i;
    for(i=0;i<N;i++)
        scanf("%s",map[i]);
}
bool Judge(int x,int y)
{
    if(x>=0&&x<N&&y>=0&&y<M)
        return true;
    return false;
}
int BFS()
{
    int i,j;
    Node u;
    memset(vis,false,sizeof(vis));
    Head=Tail=0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            if(map[i][j]=='r')
            {
                Q[Head++]=Node(i,j,0);
                vis[i][j]=true;
            }
        }
    }
    while(Head!=Tail)
    {
        u=Q[Tail++];
        u.step++;
        for(i=0;i<4;i++)
        {
            int dx=u.x+dir[i][0];
            int dy=u.y+dir[i][1];
            if(Judge(dx,dy)&&!vis[dx][dy]&&map[dx][dy]!='#')
            {
                vis[dx][dy]=true;
                if(map[dx][dy]=='x')
                    Q[Head++]=Node(dx,dy,u.step+1);
                else
                {
                    Q[Head++]=Node(dx,dy,u.step);
                    if(map[dx][dy]=='a')
                        return u.step;
                }
            }
        }
    }
    return -1;
}
void Solve()
{
    int ans=BFS();
    if(ans==-1)
        printf("Poor ANGEL has to stay in the prison all his life.\n");
    else
        printf("%d\n",ans);
}
int main()
{
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        Init();
        Solve();
    }
return 0;
}