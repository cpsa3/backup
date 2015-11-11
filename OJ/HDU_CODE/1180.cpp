////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-08-31 22:04:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1180
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
/*BFS*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
struct Node
{
    int x,y,step;
    Node(int x1,int y1,int step1)
    {x=x1;y=y1;step=step1;}
    Node(){}
};
Node Q[2000000];
int Head,Tail;
int N,M;
char map[30][30];
bool vis[30][30];
int dir[4][2]={0,1,0,-1,1,0,-1,0};
void Init()
{
    int i,j;
    Head=Tail=0;
    memset(vis,false,sizeof(vis));
    for(i=0;i<N;i++)
        scanf("%s",map[i]);
    bool ok=false;
    for(i=0;i<N&&!ok;i++)
    {
        for(j=0;j<M;j++)
        {
            if(map[i][j]=='S')
            {
                Q[Head++]=Node(i,j,0);
                vis[i][j]=true;
                ok=true;break;
            }
        }
    }
}
bool Judge(int x,int y)
{
    if(x>=0&&x<N&&y>=0&&y<M)
        return true;
    return false;
}
int BFS()
{
    int i,res=-1;
    Node u;
    //bool ok=false;
    while(Head!=Tail)
    {
        u=Q[Tail++];
        if(map[u.x][u.y]=='T')
        {
            return u.step;
        }
        u.step++;
        for(i=0;i<4;i++)
        {
            int dx=u.x+dir[i][0];
            int dy=u.y+dir[i][1];
            if(Judge(dx,dy)&&!vis[dx][dy]&&map[dx][dy]!='*')
            {
                //if(map[dx][dy]=='T') return u.step;
                if(map[dx][dy]=='.'||map[dx][dy]=='T')
                {
                    vis[dx][dy]=true;
                    Q[Head++]=Node(dx,dy,u.step);
                }
                else if((map[dx][dy]=='|'&&(u.step-1)%2==0)||(map[dx][dy]=='-'&&(u.step-1)%2==1))
                {
                    dx+=dir[i][0];
                    dy+=dir[i][1];
                    if(Judge(dx,dy)&&!vis[dx][dy]&&map[dx][dy]!='*')
                    {
                        if(i>=2)
                        {
                            vis[dx][dy]=true;
                            Q[Head++]=Node(dx,dy,u.step);
                        }
                        else
                        {
                            Q[Head++]=Node(u.x,u.y,u.step);
                        }
                    }
                }
                else
                {
                    dx+=dir[i][0];
                    dy+=dir[i][1];
                    if(Judge(dx,dy)&&!vis[dx][dy]&&map[dx][dy]!='*')
                    {
                        if(i<2)
                        {
                            vis[dx][dy]=true;
                            Q[Head++]=Node(dx,dy,u.step);
                        }
                        else
                        {
                            Q[Head++]=Node(u.x,u.y,u.step);
                        }
                    }
                }
            }
        }
    }
    return -1;
}
void Solve()
{
    int ans=BFS();
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