////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2010-11-13 23:39:07
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1429
////Problem Title: 
////Run result: Accept
////Run time:250MS
////Run memory:3136KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <queue>
using namespace std;
struct px
{
    int x,y,s,key,flag[10];
};
struct px start;
char map[25][25];
int mark[25][25][1025],dir[4][2]={0,1,0,-1,1,0,-1,0};
int wys[10]={1,2,4,8,16,32,64,128,256,512};
int N,M,T;
bool panduan(px t)
{
	if(t.x>=1&&t.x<=N&&t.y>=1&&t.y<=M)
		return true;
	return false;
}
void bfs()
{
	int i;
	for(i=0;i<10;i++)
		start.flag[i]=0;
    queue<px>Q;
    Q.push(start);
	struct px t,temp;
	mark[start.x][start.y][0]=0;
	while(!Q.empty())
	{
		temp=Q.front();
		Q.pop();
		if(temp.s>=T)
			break;
		if(map[temp.x][temp.y]=='^')
		{printf("%d\n",temp.s);return;}
		for(i=0;i<4;i++)
		{
			t=temp;
			t.x+=dir[i][0];
			t.y+=dir[i][1];
			t.s=temp.s+1;
			if(panduan(t)&&mark[t.x][t.y][t.key]&&map[t.x][t.y]!='*')
			{
				if(map[t.x][t.y]>='A'&&map[t.x][t.y]<='J')
				{
					if(t.flag[map[t.x][t.y]-'A'])
					{
						mark[t.x][t.y][t.key]=0;
						Q.push(t);
					}
				}
				else if(map[t.x][t.y]>='a'&&map[t.x][t.y]<='j')
				{
					if(t.flag[map[t.x][t.y]-'a']==0)
					{
						t.flag[map[t.x][t.y]-'a']=1;
						t.key+=wys[map[t.x][t.y]-'a'];
					}
					mark[t.x][t.y][t.key]=0;
					Q.push(t);
				}
				else
				{
					mark[t.x][t.y][t.key]=0;
					Q.push(t);
				}
			}
		}
	}
printf("-1\n");
return;
}
int main ()
{
    int i,j,k;
    while(scanf("%d%d%d",&N,&M,&T)!=EOF)
    {
        getchar();
		for(i=0;i<=N;i++)
			for(j=0;j<=M;j++)
				for(k=0;k<1025;k++)
					mark[i][j][k]=1;
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=M;j++)
            {
                scanf("%c",&map[i][j]);
                if(map[i][j]=='@')
                {start.x=i;start.y=j;start.s=0;start.key=0;}
            }
			getchar();
        }
		bfs();
    }
return 0;
}