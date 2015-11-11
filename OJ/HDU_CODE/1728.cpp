////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-10-28 22:08:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1728
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:364KB
//////////////////System Comment End//////////////////
#include<queue>
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char map[101][101];
int mark[101][101],n,m,sx,sy,ex,ey,num;
int r[5][2]={{0,0},{1,0},{0,1},{-1,0},{0,-1}};
struct  ss
{
    int x,y,step,now;
};
void BFS()
{

    if(ex==sx&&ey==sy){printf("yes\n");return;}
    int i,j;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    mark[i][j]=9999;
    mark[sx][sy]=0;
    queue<ss>Q;
    ss p,s;
    p.x=sx;p.y=sy;p.step=0;p.now=0;
    for(i=1;i<=4;i++)
    {
       s=p;
       s.x+=r[i][0];s.y+=r[i][1];
       s.now=i;
       if(s.x>=1&&s.x<=n&&s.y>=1&&s.y<=m&&map[s.x][s.y]=='.')
       { mark[s.x][s.y]=0;Q.push(s);}    
    }
    while(!Q.empty())
    {
      p=Q.front();
      Q.pop();
      if(p.x==ex&&p.y==ey&&p.step<=num)
      {printf("yes\n");return;}
      for(i=1;i<=4;i++)
      {
           s=p;
           s.x+=r[i][0];s.y+=r[i][1];
           if(s.now!=i){s.step++;s.now=i;}
           if(s.step<=num&&s.x>=1&&s.x<=n&&s.y>=1&&s.y<=m&&map[s.x][s.y]=='.')
           {
            if(s.step<=mark[s.x][s.y])                          //≈–∂œ∏˙–¬µ„£°~
            {Q.push(s);mark[s.x][s.y]=s.step;}
           }
      }    
    }
    printf("no\n");
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--&&scanf("%d %d%*c",&n,&m))
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
                scanf("%c",&map[i][j]);
            getchar();
        }
        scanf("%d %d %d %d %d",&num,&sy,&sx,&ey,&ex);
        BFS();
    }
}

