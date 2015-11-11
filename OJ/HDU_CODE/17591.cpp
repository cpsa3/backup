////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2010-12-30 14:57:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1759
////Problem Title: 
////Run result: Accept
////Run time:1578MS
////Run memory:4104KB
//////////////////System Comment End//////////////////
/*���ѣ���Ŀ����˼���Ǹ���N�����M������·������������u,v֮���ܵ��ĵ�Ķ���*/
#include <iostream>
#include <queue>
using namespace std;
int map[1005][1005];
int len[1005];
bool flag[1005];
char K[1000];//ע��K>N������Kѹ��û��
queue<int>Q;
int ans,N,M;
void get_map()
{
	int i,a,b;
	//memset(map,0,sizeof(map));
	memset(len,0,sizeof(len));
	//for(i=0;i<=N-1;i++)
	//	map[i][0]=i;
	for(i=1;i<=M;i++)
	{
		scanf("%d%d%*d",&a,&b);
		//printf("*");
		map[a][len[a]++]=b;
	}
}
int bfs(int s)
{
	int v,u,ans1=0;
	while(!Q.empty())
		Q.pop();
	memset(flag,false,sizeof(flag));
	flag[s]=true;
	Q.push(s);
	while(!Q.empty())
	{
		if(ans1==N)//��֦
			break;
		u=Q.front();
		Q.pop();
		for(v=0;v<len[u];v++)
		{
			if(!flag[map[u][v]])
			{ans1++;Q.push(map[u][v]);flag[map[u][v]]=true;}
		}
	}
	return ans1;
}
int main()
{
	int i;
	while(scanf("%d%d%s",&N,&M,K)!=EOF)
	{
		get_map();
		ans=N;
		for(i=0;i<N;i++)
		{
			if(ans==N*N)//��֦
				break;
			ans+=bfs(i);
		}
		printf("%d\n",ans); 
	}
	return 0;
}