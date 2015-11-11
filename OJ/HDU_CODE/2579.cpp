////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-05-08 22:27:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2579
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:11228KB
//////////////////System Comment End//////////////////
/*BFS*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <queue>
using namespace std;
struct Node
{
    int x,y,step;
};
struct Node scr;
const int dir[4][2]={0,1,0,-1,1,0,-1,0};
char map[1005][1005];
bool vis[1005][1005][11];
int N,M,K;
void Init()
{
    int i,j;
    scanf("%d%d%d",&N,&M,&K);
    for(i=0;i<N;i++)
        scanf("%s",map[i]);
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            if(map[i][j]=='Y')
            {scr.x=i;scr.y=j;map[i][j]='.';i=N;break;}
        }
    }
    //for(i=0;i<N;i++)
    //    puts(map[i]);
	//puts("");
}
bool Judge(int x,int y)
{
    if(x>=0&&x<N&&y>=0&&y<M) return true;
    return false;
}
queue<Node>Q;
void BFS()
{
    int i;
    Node u,v;
    while(!Q.empty()) Q.pop();
    memset(vis,false,sizeof(vis));
    scr.step=0;
    vis[scr.x][scr.y][0]=true;
    Q.push(scr);
    while(!Q.empty())
    {
        u=Q.front();Q.pop();
        //if(map[u.x][u.y]=='G')
        //{printf("%d\n",u.step);return;}
        for(i=0;i<4;i++)
        {
            v.x=u.x+dir[i][0];
            v.y=u.y+dir[i][1];
            v.step=u.step+1;
            int w=v.step%K;
            if(Judge(v.x,v.y)&&!vis[v.x][v.y][w])
            {
                //vis[v.x][v.y][w]=true;
                if(map[v.x][v.y]=='.')
                {
                    vis[v.x][v.y][w]=true;
                    Q.push(v);
                }
                else if(map[v.x][v.y]=='#'&&v.step%K==0)
                {
                    vis[v.x][v.y][w]=true;
                    Q.push(v);
                }
                else if(map[v.x][v.y]=='G')
                {printf("%d\n",v.step);return;}
            }
        }
    }
    printf("Please give me another chance!\n");
}
void Solve()
{
    BFS();
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        Init();
        Solve();
    }
return 0;
} 