////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-07-25 00:03:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1043
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:4404KB
//////////////////System Comment End//////////////////
/*BFS+状态压缩*/
/*从终止状态直接把所有可达的状态都先搜出来*/
/*AC代码：938ms*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <queue>
#define MAXN 362900
using namespace std;
struct Node
{
	int state;
	int pos;
	int num[10];
};
bool vis[MAXN];
char str[20];
int now[10];
int factor[10]={1,1,2,6,24,120,720,5040,40320,362880};
int dir[4][2]={-1,0,0,1,1,0,0,-1};//u,r,d,l
int pre[MAXN];//记录路径
char d[MAXN];//记录
char ans[MAXN],cnt;//记录答案

int get_state(int num[])
{
	int res=0,temp,i,j;
	for(i=1;i<=9;i++)
	{
		temp=0;
		for(j=i+1;j<=9;j++)
		{
			if(num[i]>num[j]) temp++; 
		}
		res+=factor[9-i]*temp; 
	}
	return (res+1);
}
void Copy(int a[],int b[])
{
	int i;
	for(i=1;i<=9;i++)
		a[i]=b[i];
	return ;
}
char get_dir(int d)//直接把方向反存
{
	switch(d)
	{
	case 0:return 'd';
	case 1:return 'l';
	case 2:return 'u';
	case 3:return 'r'; 
	}
}
queue<Node>Q;
void BFS()
{
	int i,x,y,t,temp[10],w;
	Node u,v;
	for(i=1;i<=9;i++)
		temp[i]=i;
	while(!Q.empty()) Q.pop();
	memset(vis,false,sizeof(vis));
	memset(pre,-1,sizeof(pre));
	
	u.state=1;
	Copy(u.num,temp);u.pos=9;
	Q.push(u);
	vis[u.state]=true;
	
	while(!Q.empty())
	{
		
		u=Q.front();Q.pop();
		x=(u.pos-1)/3+1;
		y=(u.pos-1)%3+1;
		//printf("*%d %d %d\n",u.pos,x,y);
		for(i=0;i<4;i++)
		{
			Copy(temp,u.num);
			int dx=x+dir[i][0];
			int dy=y+dir[i][1];
			//printf("&%d %d\n",dx,dy);
			if(dx>=1&&dx<=3&&dy>=1&&dy<=3)
			{
				w=(dx-1)*3+dy;
				t=temp[u.pos];temp[u.pos]=temp[w];temp[w]=t;
				
				int st=get_state(temp);
				if(vis[st]) continue;

				vis[st]=true;
				pre[st]=u.state;
				d[st]=get_dir(i);
				//if(st==1) break;//已经找到
				v.state=st; 
				v.pos=w;
				Copy(v.num,temp);
				Q.push(v);
			}
		}
	}
}
bool Judge(int num[])//如果逆序数是奇数，则无解
{
	int res=0,i,j;
	for(i=1;i<=9;i++)
	{
		if(num[i]==9) continue;
		for(j=i+1;j<=9;j++)
		{
			if(num[j]==9) continue;
			if(num[i]>num[j]) res++; 
		}
	}
	if(res%2) return false;
	return true;
}
void Solve()
{
	int i;
	if(!Judge(now))//判是否有解
	{printf("unsolvable\n");return;}

	int pos=get_state(now);
	cnt=0;
	while(true)
	{
		if(pre[pos]==-1) break;
		ans[cnt++]=d[pos];
		pos=pre[pos]; 
	}
	for(i=0;i<cnt;i++)
		printf("%c",ans[i]);
	printf("\n");
}
int main()
{
	int i;
	BFS();//先从终止状态把所以可达的答案都搜出来
	while(scanf("%s",str)!=EOF)
	{
		if(str[0]=='x') now[1]=9;
		else now[1]=str[0]-'0';
		for(i=2;i<=9;i++)
		{
			scanf("%s",str);
			if(str[0]=='x') now[i]=9;
			else now[i]=str[0]-'0';
		}
		Solve();
	}
	return 0;
}