////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2011-11-23 18:04:11
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1043
////Problem Title: 
////Run result: Accept
////Run time:609MS
////Run memory:264KB
//////////////////System Comment End//////////////////
/*AStar*/
/*���ۺ�����x��(3,3)�������پ���*/
/*AC���룺750ms*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#define min(a,b) (a<b?a:b)
#define MAXN 362900
#define INF 1e8
using namespace std;

char str[20];
int now[10],POS,bound;
int goal_state[9][2]={{1,1},{1,2},{1,3},{2,1},{2,2},{2,3},{3,1},{3,2},{3,3}};
int dir[4][2]={-1,0,0,1,0,-1,1,0};//u,r,l,d
char op[5]="urld";
bool ans;
int path[MAXN];
//h(n):��ǰλ����Ŀ��λ�õ������پ���
int h(int num[])
{
	int i,res=0;
	for(i=1;i<=9;i++)
	{
		int w=num[i];
		int x=(i-1)/3+1;
		int	y=(i-1)%3+1;
		res=res+abs(x-goal_state[w-1][0])+abs(y-goal_state[w-1][1]);
	}
	return res; 
}

void swap(int &a,int &b)
{
	int t;
	t=a;a=b;b=t;
}

int dfs(int pos,int dv,int pre,int map[])
{
	int hv=h(map);
	if(hv+dv>bound)
		return hv+dv;
	if(hv==0)//�ҵ�
	{
		ans=true;
		return dv; 
	}
	int next_bound=INF;
	int i,x,y,next_pos;
	x=(pos-1)/3+1;
	y=(pos-1)%3+1;
	for(i=0;i<4;i++)
	{
		if((i+pre)==3) continue;
		int dx=x+dir[i][0];
		int dy=y+dir[i][1];
		if(dx>3||dx<1||dy>3||dy<1) continue;

		next_pos=(dx-1)*3+dy;
		path[dv]=i;//��¼·��
		swap(map[pos],map[next_pos]);
		int new_bound=dfs(next_pos,dv+1,i,map);

		if(ans) 
			return new_bound;

		next_bound=min(next_bound,new_bound);

		swap(map[pos],map[next_pos]); 
	}
	//printf("#%d\n",next_bound);
	return next_bound;
}
void Print()
{
	int i;
	//printf("*%d\n",bound);
	for(i=0;i<bound;i++)
		printf("%c",op[path[i]]);
	printf("\n");
}
void IDA_star()
{
	int temp[10];
	
	ans=false;
	bound=h(now);
	int cnt=0;
	while(!ans&&bound<=100)
	{
		memcpy(temp,now,sizeof(now));
		bound=dfs(POS,0,10,temp);
		//printf("%d %d\n",bound,ans);
		//cnt++; 
	}
	//printf("&&&%d\n",cnt);
	Print();
}

bool Judge(int num[])//��������������������޽�
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
	if(!Judge(now))//���Ƿ��н�
	{printf("unsolvable\n");return;}
	IDA_star();
}

int main()
{
	int i;
	while(scanf("%s",str)!=EOF)
	{
		if(str[0]=='x') {now[1]=9;POS=1;}
		else now[1]=str[0]-'0';
		for(i=2;i<=9;i++)
		{
			scanf("%s",str);
			if(str[0]=='x') {now[i]=9;POS=i;}
			else now[i]=str[0]-'0';
		}
		Solve();
	}
	return 0;
}

