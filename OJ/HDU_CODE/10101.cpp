////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
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
    if(step>=T) //��֦1����step>=Tʱ��û���ҵ�D�� 
    {
        return false; 
    }    
    if(T-step<(abs(x-dx)+abs(y-dy))) //��֦2������Ҫ�Ĳ����������ϵ���̾��뻹С 
    {
        return false; 
    }    
    if((T-step-(abs(x-dx)+abs(y-dy)))%2!=0) //��֦3���������ϵ���̾��������ı���ż�� 
    {
        return false; 
    }    
    for(int i=0;i<4;i++)
    {
        int _x,_y;
        _x=x+dir[i][0];
        _y=y+dir[i][1];
        //�ж�����������1.����_x,_y�Ƿ�Խ�硣2.��vis[][]�Ƿ���ʹ���3.��map[][]�Ƿ���ǽ 
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