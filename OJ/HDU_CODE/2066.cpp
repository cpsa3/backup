////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2010-11-09 22:59:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2066
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:4200KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
const int INF=99999999;
const int MAX=1010;
int max(int a,int b)
{
	return a>b?a:b;
}
int T,S,D,L;
int map[MAX][MAX];
int Dijkstra(int start,int end)
{
	bool hash[MAX];
	int path[MAX];//��¼����ʼ�㵽i������·��
	for(int i=0;i<=L;i++)
	{
		hash[i]=true;//��ʾ�õ�û�д����
		path[i]=INF;//��ʾi��û�����������ʱ���·Ϊ�����
	}
	hash[start]=false;
	path[start]=0;//ע���
	while(start!=end)
	{
		for(i=0;i<=L;i++)
		{
			if(map[start][i]!=0)
			{
				if(path[i]>path[start]+map[start][i])
					path[i]=path[start]+map[start][i];
			}
		}
		int min=INF;
		for(i=0;i<=L;i++)
		{
			if(path[i]<min&&hash[i])//���µ���ʼ��
			{
				min=path[i];
				start=i;
			}
		}
		hash[start]=false;
	}
return path[end];
}
int main ()
{
	int i,a,b,time,s,d;
	while(scanf("%d%d%d",&T,&S,&D)!=EOF)
	{
		memset(map,0,sizeof(map));//��ʼ��
		L=0;
		for(i=1;i<=T;i++)
		{
			scanf("%d%d%d",&a,&b,&time);
			if(!map[a][b])
				map[a][b]=map[b][a]=time;
			else
			{
				if(map[a][b]>time)
					map[a][b]=map[b][a]=time;
			}
			if(L<max(a,b))
				L=max(a,b);//��������ŵĵ�
		}
		for(i=1;i<=S;i++)
		{
			scanf("%d",&s);
			map[0][s]=map[s][0]=1;//����ܵ���ʼ��
		}
		L++;//��ӽ�����
		for(i=1;i<=D;i++)
		{
			scanf("%d",&d);
			map[L][d]=map[d][L]=1;
		}
		printf("%d\n",Dijkstra(0,L)-2);
	}
return 0;
}