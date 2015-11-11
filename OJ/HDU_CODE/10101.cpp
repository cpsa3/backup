////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-10-06 13:26:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1010
////Problem Title: 
////Run result: Accept
////Run time:609MS
////Run memory:264KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int dir[4][2]={0,1,1,0,-1,0,0,-1};
int vis[6][6];
char map[6][6];
int sx,sy,dx,dy;
int m,n,T;

bool DFS(int x,int y,int step)
{ if(map[x][y]=='D'&&step==T)
    {
        return true;
    }    
    if(step>=T) //剪枝1：当step>=T时还没有找到D点 
    {
        return false; 
    }    
    if(T-step<(abs(x-dx)+abs(y-dy))) //剪枝2：还需要的步数比理论上的最短距离还小 
    {
        return false; 
    }    
    if((T-step-(abs(x-dx)+abs(y-dy)))%2!=0) //剪枝3：比理论上的最短距离多出来的必是偶数 
    {
        return false; 
    }    
    for(int i=0;i<4;i++)
    {
        int _x,_y;
        _x=x+dir[i][0];
        _y=y+dir[i][1];
        //判断三个条件：1.检验_x,_y是否越界。2.看vis[][]是否访问过。3.看map[][]是否是墙 
        if(_x<m&&_y<n&&_x>=0&&_y>=0&&vis[_x][_y]==0&&map[_x][_y]!='X')
        {
            vis[_x][_y]=1;
            if(DFS(_x,_y,step+1))
            {
                return true;
            }    
            else
            {
                vis[_x][_y]=0;    
            }    
        }    
    } 
    return false;   
}    
int main()
{
    while(cin>>m>>n>>T)
    {
        if(m==0&&n==0&&T==0) break;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>map[i][j];
                if(map[i][j]=='S')
                {
                    sx=i;
                    sy=j;
                }    
                if(map[i][j]=='D')
                {
                    dx=i;
                    dy=j;
                }
                vis[i][j]=0;    
            }    
        }    
        vis[sx][sy]=1;
        if(DFS(sx,sy,0)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;  
    }    
    //system("PAUSE");
    return 0;
}  