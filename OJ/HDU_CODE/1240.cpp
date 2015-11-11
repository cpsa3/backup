////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-09-05 20:05:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1240
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
/*BFS*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 20
#define INF (1<<30)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct Node
{
    int x,y,z,step;
    Node(int x1,int y1,int z1,int step1)
    {x=x1;y=y1;z=z1;step=step1;}
    Node(){}
};
Node Q[200000];
int Head,Tail;
int dir[6][3]={
    0,0,1,
    0,0,-1,
    0,1,0,
    0,-1,0,
    1,0,0,
    -1,0,0
};
char map[MAXN][MAXN][MAXN];
bool vis[MAXN][MAXN][MAXN];
char s[20];
int N,sx,sy,sz,ex,ey,ez;
bool Judge(int x,int y,int z)
{
    if(x>=0&&x<N&&y>=0&&y<N&&z>=0&&z<N)
        return true;
    return false;
}
void Print()
{
    int i,j,k;
    printf("*************\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            printf("%c",map[i][j][1]);
        printf("\n");
    }
    printf("*************\n");
}
void Init()
{
    int i,j,k;
    getchar();
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            for(k=0;k<N;k++)
                scanf("%c",&map[j][k][i]);
            getchar();
        }
    }
    //Print();
    scanf("%d%d%d%d%d%d",&sx,&sy,&sz,&ex,&ey,&ez);
    scanf("%s",s);
    //printf("%c %c\n",map[sx][sy][sz],map[ex][ey][ez]);
}
int BFS()
{
    int i,j,k;
    Node u;
    if(sx==ex&&sy==ey&&sz==ez) return 0;
    memset(vis,false,sizeof(vis));
    vis[sz][sy][sz]=true;
    Head=Tail=0;
    Q[Head++]=Node(sx,sy,sz,0);
    while(Head!=Tail)
    {
        u=Q[Tail++];
        u.step++;
        for(i=0;i<6;i++)
        {
            int dx=u.x+dir[i][0];
            int dy=u.y+dir[i][1];
            int dz=u.z+dir[i][2];
            if(Judge(dx,dy,dz)&&!vis[dx][dy][dz]&&map[dx][dy][dz]=='O')
            {   //printf("*\n");
                vis[dx][dy][dz]=true;
                if(dx==ex&&dy==ey&&dz==ez)
                    return u.step;
                Q[Head++]=Node(dx,dy,dz,u.step);
            }
        }
    }
    return -1;
}
void Solve()
{
    int ans=BFS();
    if(ans==-1)
        printf("NO ROUTE\n");
    else
        printf("%d %d\n",N,ans);
}
int main()
{
    while(scanf("%s%d",s,&N)!=EOF)
    {
        Init();
        Solve();
    }
return 0;
}